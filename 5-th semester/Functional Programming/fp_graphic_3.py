import matplotlib.pyplot as plt
import numpy as np

a = 1.0
k = 1.0
omega = 10.0
x_lst = []
y_lst = []

def y_calculate(a, k, omega):
    lst = []
    for x in np.arange(0, 4, 0.01):
        lst.append(a * np.exp(-k * x) * np.sin(omega * x + a))
    return lst

def draw_graphic(x, y):
    fig = plt.figure()
    plt.plot(x, y)
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid(True)
    plt.show()

x_lst = np.arange(0, 4, 0.01)
y_lst = y_calculate(a, k, omega)

print(x_lst)
print(y_lst)

draw_graphic(x_lst, y_lst)