import matplotlib
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

X = np.arange(16).reshape(4, 4)
fig = plt.figure()
ax = fig.add_subplot(111)
plt.title("Rectangles")
rect1 = matplotlib.patches.Rectangle((1.3,1.6), 1.1, 2, color='blue', fc = 'none',lw = 2)
rect2 = matplotlib.patches.Rectangle((1.5,1.8), .65, 1.6, color='orange',fc = 'none', lw = 2)
ax.add_patch(rect1)
ax.add_patch(rect2)
plt.xlim([1.2, 2.5])
plt.ylim([1.5, 3.7])
plt.xlabel("x - axis")
plt.ylabel("y - axis")
plt.grid()
plt.show()