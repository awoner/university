import matplotlib.pyplot as plt
import numpy as np

a = 1.0
x_lst = []
y_lst = []

def y_calculate(a):
    lst = []
    for x in np.arange(-2, 2, 0.1):
        lst.append(pow(a, 3) / (pow(x, 2) + pow(a, 2)))
    return lst

def draw_graphic(x, y):
    fig = plt.figure()
    plt.plot(x, y)
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid(True)
    plt.show()

x_lst = np.arange(-2, 2, 0.1)
y_lst = y_calculate(a)

print(x_lst)
print(y_lst)

draw_graphic(x_lst, y_lst)