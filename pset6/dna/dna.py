import csv
import sys
def main():
#check argumant
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
#open file
    file_base = open(sys.argv[1])
    file_dna = open(sys.argv[2])
#read file
    reader = csv.DictReader(file_base)
    STR = reader.fieldnames[1:]
#copy dna as string
    dna = file_dna.read()
    file_dna.close()
    
    dna_d = {}
    for str in STR:
        dna_d[str] = consec(str, dna)
        
    for row in reader:
        if matches(STR, dna_d, row):
            print(f"{row['name']}")
            file_base.close()
            return
        
    print("No match")
    file_base.close()
    
def consec(str, dna):
    i = 0
    while str*(i+1) in dna:
        i +=1
    return i
def matches(STR, dna_d, row):
    for str in STR:
        if dna_d[str] != int(row[str]):
            return False
        
    return True
main()