from cs50 import get_int

def main():
    while True:
        n = get_int("Height:")
        if n >= 1 and n <= 8:
            break
    for hash_a in range( n + 1):
      space = n - hash_a 
      print(" " * space, end="")
      print("#" * hash_a, end="")
      print(" ", end=" ")
      print("#" * hash_a)  
main() 