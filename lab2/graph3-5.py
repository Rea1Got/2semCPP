import matplotlib.pyplot as plt 
import numpy as np
import matplotlib as mpl
# import math

min_ = 10000
max_ = 150000
step = 100
loop_times = 100

files = ["3-5_firstTest.txt", "3-5_secondTest.txt", "3-5_thirdTest.txt"]

###########################################################################
# Приводим данные к нужному виду
x = [[],[],[]]
y = [[],[],[]]

for k in range(3):
    data = []
    with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab2\\' + files[k], 'r') as file:
        for i in file:
            data.append(i.split())

    for i in range(len(data)):
        for j in range(len(data[1])):
            data[i][j] = int(data[i][j])

    x[k] = [i for i in range(min_, max_+step, step)]
    y[k] = [0]*((max_ - min_)//step + 1)

    for i in range(len(data)):
        for j in range(len(y[k])):
            y[k][i] += data[i][j]
    for i in range(len(y[k])):
        y[k][i] /= loop_times
        y[k][i] /= 1000000
    file.close()
    data.clear()

##########################################################################

a = []
for i in range(3):
    a.append(np.polyfit(x[i], y[i], 1))
b = [np.linspace(0, max_, 1000)]*3



##########################################################################

fig = plt.figure(figsize=(12, 12))
ax1 = fig.add_subplot(311)
ax2 = fig.add_subplot(312)
ax3 = fig.add_subplot(313)
########################
sp = plt.subplot(311)
ax1.plot(x[0], y[0], 'o-r', c='k', lw=0, alpha = 0.4, mec='r', mew=0, ms=2, label = 'Усредненное значение времени')
ax1.plot(b[0], b[0]*a[0][0] + a[0][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)
plt.xlabel('N, количество элементов')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(a) Полный перебор', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(312)
ax2.plot(x[1], y[1], 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax2.plot(b[1], b[1]*a[1][0] + a[1][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(b) Линейный поиск', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(313)
ax3.plot(x[2], y[2], 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax3.plot(b[2], b[2]*a[2][0] + a[2][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(b) Линейный поиск', loc='left')
plt.grid(True)
plt.legend()

########################################################################## 

plt.show()

print('Clear files? y/n')
if (input().lower() == 'y'):
    for i in range(3):
        with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\' + files[i], 'w') as file:
            file = ''

