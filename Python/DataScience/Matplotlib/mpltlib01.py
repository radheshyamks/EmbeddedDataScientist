import os;
import sys;
import matplotlib;
from matplotlib import pyplot as plt;

x = [i for i in range(1,1000000)]
y = [i**4 for i in x]

plt.plot(x,y)
plt.legend(x,y)
plt.title("xy Graph")

plt.show()