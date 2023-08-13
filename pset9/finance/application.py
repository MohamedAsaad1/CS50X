import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    stock = db.execute("SELECT symbol, name, price, SUM(shares) as sumshares FROM portfolio WHERE user_id = ? GROUP BY symbol", user_id)
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
    total = cash
    
    for sto in stock:
        total += sto["price"] * sto["sumshares"]
    return render_template("index.html", stock=stock, cash=cash, total=total, usd=usd)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
          symbol = request.form.get("symbol").upper()
          item = lookup(symbol)
          if not symbol:
              return apology("Invalied")
          elif not item:
              return apology("Invalied0")
          try:
              shares = int(request.form.get("shares"))
          except:
              return apology("must integer")
          if shares <= 0:
              return apology("must positive")
          user_id = session["user_id"]
          cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]['cash']
          item_name = item["name"]
          item_price = item["price"]
          total = item_price * shares
          if cash < total:
              return apology("Not enough!")
          else:
              db.execute("UPDATE users SET cash = ? WHERE id = ?", cash - total, user_id )
              db.execute("INSERT INTO portfolio (user_id, shares, name, price, symbol, type) VALUES(?, ?, ?, ?, ?, ?)",
              user_id, shares, item_name, item_price, symbol, 'buy')    
          return redirect("/")
              
              
    else:
        return render_template("buy.html")
 

@app.route("/history")
@login_required
def history(): 
    """Show history of transactions"""
    user_id = session["user_id"]
    hsitorical = db.execute("SELECT symbol, type, price, shares, timestamp FROM portfolio WHERE user_id = ?", user_id)
    return render_template("history.html", his=hsitorical, usd=usd)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("missing a symbol")
        elment = lookup(symbol)  
        if not elment:
            return apology("Invaild symbol")
        return render_template("quoted.html", elment = elment, usd=usd)    
    else:
         return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not username:
            return apology("username is unsuitable")
        elif not confirmation:
            return apology("confirmation is unsuitable")
        elif not password:
            return apology("password is unsuitable")
        if password != confirmation:
            return apology("your confirmation not equal password")
        hash = generate_password_hash(password)    
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
            return redirect("/")
        except:
            return apology("username has found")
    else:
        return render_template("register.html")
    


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session["user_id"]
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        if shares <= 0:
            return apology("Must posstive")
        price = lookup(symbol)["price"]
        name = lookup(symbol)["name"]
        price_o = shares * price
        shares_own = db.execute("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)[0]["shares"]
        if shares_own < shares:
            return apology("NOT enough")
        currnet_user = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        db.execute("UPDATE users SET cash = ? WHERE id = ?", currnet_user + price_o, user_id)
        db.execute("INSERT INTO portfolio (user_id, shares, name, price, symbol, type) VALUES(?, ?, ?, ?, ?, ?)",
              user_id, -shares, name, price, symbol, 'sell') 
        return redirect("/")      
    else:
        symbol = db.execute("SELECT symbol FROM portfolio WHERE user_id = ? GROUP BY symbol", user_id)
        return render_template("sell.html",symbol=symbol)

        
   


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
        
