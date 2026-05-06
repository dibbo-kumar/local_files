# name ="   dibbo kumar    ".strip().title()
#first,second = name .split(" ")
#name = name.strip().title()
#name = name.capitalize()
#name = name.title()
# print(f"its okay {name}")
# x = 5
# y= 12121
# z = x+y
# print(f"{z:,}")
# x = 5
# y = 5
# if (x<y):

#     print("ok")
# elif x>y:
#     print("okkk")
# else:
#     print("k")
# for i in range(4):
# print("dibbo\n" *3 , end ="")
# n = int(input("n? :"))
# students = ["dibbo", "hridoy", "suvro"]

# for s in range(len(students)):
#     print(s,students[s])
# students = {"dibbo":"jhe",
#             "hri":"can",
#             "suv":"farid",}

# for s in students:
#     print(s,students[s],sep=",")
# from random import choice
# coin = choice(["head","tail"])
# print(coin)
# import random
# choice = random.randint(1,10)
# print(choice)
import matplotlib.pyplot as plt
import numpy as np

# Given data points
x = [-0.91, -1.46, -1.94, -2.44, -2.97, -3.50, -4.00, -4.48, -4.98]
y = [-0.00075, -0.00066, -0.0005, -0.0005, -0.00025, -0.000167, -0.000166, -0.0001, -0.00001]

# Fit a line of best fit
coefficients = np.polyfit(x, y, 1)
linear_fit = np.poly1d(coefficients)

# Generate x values for the fit line
x_fit = np.linspace(min(x), max(x), 100)
y_fit = linear_fit(x_fit)

# Plot
plt.figure(figsize=(10, 6))
plt.plot(x, y, 'o', label='Data Points', color='blue')
plt.plot(x_fit, y_fit, '-', label='Line of Best Fit', color='red')
plt.title('Data Points and Line of Best Fit')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
