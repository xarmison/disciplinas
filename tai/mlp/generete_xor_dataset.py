import numpy as np
import matplotlib.pyplot as plt

rng = np.random.RandomState(0)

x = np.around(rng.randn(2000, 2), decimals=2)

y = np.logical_xor(x[:, 0] > 0, x[:, 1] > 0)
y = np.where(y == False, 0, 1)

file = open("./xor.csv", "w")
for (index, item) in enumerate(x):
    file.write(np.array2string(item[0])+ "," + np.array2string(item[1]) + "," + np.array2string(y[index]) + "\n")
file.close()

plt.title("XOR")
plt.scatter(x[:, 0], x[:, 1], c=y)
plt.tight_layout()
plt.show()