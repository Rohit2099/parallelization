from matplotlib import pyplot as plt
import numpy as np
import seaborn as sns
import pickle 

sns.set()

dimensions = [32, 64, 128, 256, 512, 1024, 2048, 4096]
x_label = [str(x) +'x' + str(x) for x in dimensions]
data = {}

with open("data.pkl", "rb") as pkl_handle:
	data = pickle.load(pkl_handle)

print(data)

fig = plt.figure(figsize=(15,10))
x_bound = np.arange(len(dimensions))
legend = [key for key, val in data.items()]

for i, (key, val) in enumerate(data.items()):
    x = np.arange(len(dimensions))
    plt.plot(x, val, label = legend[i], marker='o')


plt.yticks(np.arange(0, 1000, 100))
plt.legend(loc="upper left")
plt.xlabel('Matrix size')
plt.ylabel('Time taken(s)')
plt.xticks(x_bound, x_label, rotation=15)
plt.title('Time taken vs Matrix size for matrix multiplication programs coded using Sequential, OpenMP and Pthreading logic')
# plt.show()
# fig.savefig('performance.png')


fig_2 = plt.figure(figsize=(15,10))

for i, (key, val) in enumerate(data.items()):
    x = np.arange(len(dimensions))
    plt.plot(x, val, label = legend[i], marker='o')


plt.yscale("log")
plt.legend(loc="upper left")
plt.xlabel('Matrix size')
plt.ylabel('Time taken(s)')
plt.xticks(x_bound, x_label, rotation=15)
plt.title('log(Time taken) vs Matrix size for matrix multiplication programs coded using Sequential, OpenMP and Pthreading logic at lower input size')
# plt.show()
# fig_2.savefig('performance_log.png')