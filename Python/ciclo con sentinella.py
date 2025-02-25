total = 0
count = 0 

val = int(input("Enter a number: (0 to finish)"))

while val != 0:
    total += int(val)
    count += 1
    val = int(input("Enter a number: (0 to finish)"))

if count != 0:
    print("The average is", total/count)
else:
    print("No numbers were entered.")