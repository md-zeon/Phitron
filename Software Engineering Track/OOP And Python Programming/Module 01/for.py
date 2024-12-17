"""
nums = [5, 10, 15, 20, 25]

# Iterate over the list using a for loop
sum = 0
for num in nums:
    print(num, end=' ')
    sum += num

print("\nSum =", sum)

text = "Hello World"
for letter in text:
    print(letter, end=' ')

print("\n")
"""

# Range based for loop

for i in range(1, 10, 2):
    print(i, end=' ')

print("\n")

friends = ["Rolf", "Charlie", "Anna", "Bob", "Jen"]

# for friend in friends:
#     print("Hi", friend)

for index, friend in enumerate(friends):
    print(index, friend)