birth_year = int(input("Birth year? "))
birth_month = int(input("Birth month? "))
birth_day = int(input("Birth day? "))

current_year = int(input("current year? "))
current_month= int(input("current month? "))
current_day = int(input("current day? "))
 #se ho già compiuto gli anni, basta fare la sottrazione
if (current_month > birth_month or (current_month == birth_month and current_day >= birth_day)): 
    age = current_year -  birth_year
 #in caso non li avessi già compiuti, tolgo 1
else:
    age = current_year - birth_year - 1 

print ("Your age is", age)
