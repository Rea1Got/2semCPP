import matplotlib.pyplot as plt 
import numpy as np
import matplotlib as mpl
# import math

min_ = 100
max_ = 500000
step = 500
loop_times = 200

###########################################################################
data_generated = [[] for _ in range(4)]
x = [[i for i in range(min_, max_, step)] for _ in range(4)]  # axes init
y = [[i for i in range(min_, max_, step)] for _ in range(4)] 

files = ['outputLinWorst.txt', 'outputLinAvg.txt', 'outputBinWorst.txt', 'outputBinAvg.txt']  # file read
for i in range(len(files)):
    with open(files[i], 'r') as file:
        for j in file:
            data_generated[i].append(j.split())
        file.close()

for i in range(len(data_generated)):
    for j in range(len(data_generated[i])):
        for k in range(len(data_generated[i][j])):
            data_generated[i][j][k] = int(data_generated[i][j][k])

for i in range(len(y)):
    for j in range(loop_times):
        for k in range(len(y[i])):
            for m in range(len(data_generated[i][j])):
                y[i][m] += data_generated[i][j][m]  # Accumulate values
    for j in range(len(y[i])):
        y[i][j] /= loop_times * 10**6



##########################################################################
a = [[] for _ in range(4)]
b = [[] for _ in range(4)]
for i in range(len(a)):
    a[i] = np.polyfit(x[i], y[i], 1)  # lin aprox
    b[i] = np.linspace(0, max_, 1000)

##########################################################################

fig = plt.figure(figsize=(12, 8))
ax1 = fig.add_subplot(221) # создали Axes (подграфик) ax1 в серии из 2 графиков, поставили на позицию [1,1] -- левый верхний угол
ax2 = fig.add_subplot(222) # создали Axes ax2 в серии из 2 графиков, поставили на позицию [1,2] -- первый график во второй "строке" графиков
ax3 = fig.add_subplot(223)
ax4 = fig.add_subplot(224)
########################
sp = plt.subplot(221)
ax1.plot(x[0], y[0], 'o-r', c='k', lw=0, alpha = 0.4, mec='r', mew=0, ms=2, label = 'Усредненное значение времени')
ax1.plot(b[0], b[0]*a[0][0] + a[0][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)
plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(a) Линейный поиск (случайное событие)', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(222)
ax2.plot(x[1], y[1], 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax2.plot(b[1], b[1]*a[1][0] + a[1][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(b) Линейный поиск (худший случай)', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(223)
ax3.plot(x[2], y[2], 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax3.plot(b[2], b[2]*a[2][0] + a[2][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 2(a) Бинарный поиск (случайное событие)', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(224)
ax4.plot(x[3], y[3], 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax4.plot(b[3], b[3]*a[3][0] + a[3][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 2(b) Бинарный поиск (худший случай)', loc='left')
plt.grid(True)
plt.legend()

########################################################################## 

plt.show()

print('Clear files? y/n')
if (input().lower() == 'y'):
    with open('outputLinWorst.txt', 'w') as file:
        file = ''
    with open('outputLinAvg.txt', 'w') as file:
        file = ''
    with open('outputBinAvg.txt', 'w') as file:
        file = ''
    with open('outputBinWorst.txt', 'w') as file:
        file = ''
