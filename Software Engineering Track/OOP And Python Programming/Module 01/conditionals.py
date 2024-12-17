a = 2
boss = False
if a > 5:
    print("a is greater than 5")
elif a > 3:
    print("a is greater than 3")
elif a == 2:
    print("a is equal to 2")
else:
    print("a is less than 5")


if boss is True:
    print("boss is true")
else:
    print("boss is false")

if boss is not True:
    print("boss is not true")
else:
    print("boss is true")


coin = "heads"

if boss == True:
    print("boss is true")
    if coin == 'tails':
        print("coin is tails")
    else:
        print("coin is heads")
else:
    print("boss is false")
    if 8 % 2 == 0 and 5 % 2 == 1:
        print("8 is even and 5 is odd")
        if 5 > 2 or boss != True:
            print ("5 is greater than 2 or boss is not true")
    else:
        print("8 is odd or 5 is even")
