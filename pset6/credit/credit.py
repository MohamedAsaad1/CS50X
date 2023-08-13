from cs50 import get_string 

def main():
    number_card = get_string("Number: ")
    length = len(number_card)
 
    if length == 15 and int(number_card[:2]) in [34, 37]:
        print("AMEX")
    if  length == 16 and int(number_card[:2]) in [51, 51, 53, 54, 55]:
         print("MASTERCARD")
    if  length in [13, 16] and int(number_card[0]) == 4:
         print("VISA")
    else:
         print("INVALID")
main() 
