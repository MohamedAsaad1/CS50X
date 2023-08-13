from cs50 import get_string

string_name = get_string("Text: ")
l = 0
g = 0 
w = 0
for char in string_name:
    
    if char.isalpha():
        l += 1
    if char in [' ']:
        w += 1
    if char in ['!', '.' , '?']:
        g += 1
          
w += 1
total = int (0.0588 * (100 *  (l /  w) ) - 0.296 * (100 *  (g /  w) ) - 15.8)


if total < 16 and total >= 0:
    print(f"Grade{total}")
       
elif total >= 16:
    print("Grade 16+")
    
else:
    print("Before Grade 1")
Letter = (l * 100.0) / w
sentenc = (g * 100.0) / w
total = round(0.0588 * Letter - 0.296 * sentenc -15.8)
