import matplotlib.pyplot as plt
import numpy as np

a = -1.0
x_lst = []
y_lst = []

def x_calculate(a):
    lst = []
    for phi in np.arange(1, 26, np.pi / 50):
        r = a / np.sqrt(phi)
        lst.append(r * np.cos(phi))
    return lst

def y_calculate(a):
    lst = []
    for phi in np.arange(1, 26, np.pi / 50):
        r = a / np.sqrt(phi)
        lst.append(r * np.sin(phi))
    return lst

def draw_graphic(x, y):
    fig = plt.figure()
    plt.plot(x, y)
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid(True)
    plt.show()

x_lst = x_calculate(a)
y_lst = y_calculate(a)

print(x_lst)
print(y_lst)

draw_graphic(x_lst, y_lst)