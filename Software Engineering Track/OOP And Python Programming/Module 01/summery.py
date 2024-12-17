""" 
What did we learn in this module?
1. Variables
2. Data Types
3. Basic Operators
4. Commenting
5. Type Conversion
6. Basic Input/Output Operations
7. Basic Control Structures
8. Loops
"""


"""
Homework
1. Take 3 numbers from user and print the largest number
2. Take 3 numbers from user and print the sum
3. print the odd numbers between 39 to 68
4. Grade Calculator
 """

num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))
num3 = float(input("Enter third number: "))

if num1 > num2 and num1 > num3:
    print(num1, "is the largest number")
elif num2 > num1 and num2 > num3:
    print(num2, "is the largest number")
else:
    print(num3, "is the largest number")

sum = num1 + num2 + num3
print("Sum = ", sum)

for i in range(39, 69):
    if i % 2 != 0:
        print(i, end=' ')

print("\n")

grade = int(input("Enter your grade: "))

if grade >= 80:
    print("A+")
elif grade >= 70:
    print("A")
elif grade >= 60:
    print("A-")
elif grade >= 50:
    print("B")
elif grade >= 40:
    print("C")
else:
    print("Fail")