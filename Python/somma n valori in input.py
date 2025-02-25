n = int(input("How many values?")) 
total = 0
i = 0

while i < n:
    val = int(input("Val? "))

    total += val # total = total + val
    i += 1 # i = i + 1

print("The sum is", total)