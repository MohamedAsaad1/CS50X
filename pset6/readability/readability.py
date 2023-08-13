from cs50 import get_string

string_name = get_string("Text: ")# get string from user:
l = 0
g = 0 
w = 0
for char in string_name: #counter for Letterand sentenc 
    
    if char.isalpha():
        l += 1
    if char == ' ':
        w += 1
    if char in ['!', '.' , '?']:
        g += 1
w +=1

total = round (0.0588 * (100 *  (l /  w) ) - 0.296 * (100 *  (g /  w) ) - 15.8) #calculate

if total < 16 and total >= 0:#print the result
    print(f"Grade {total}")
       
elif total >= 16:
    print("Grade 16+")
    
else:
    print("Before Grade 1")

