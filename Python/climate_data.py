import numpy as np
import pandas
import matplotlib
from matplotlib import pyplot as plt
import time;
arr = np.array([i for i in range(1,51) if i%4==0 and i>0 ])
plt.plot(arr,arr**2,"^--",color='y',markersize=5)
plt.plot(arr,arr**2.01)
plt.xlabel("x-axis")
plt.ylabel('y-axis')
plt.title("Square of 4 table")
# this funciton will on the minor grid
plt.minorticks_on()
plt.grid(True,which='both',axis='both',color='b')
# block=False will execute the program till end
# execution will not stop at show function.
plt.show(block=True)