import matplotlib.pyplot as plt 
import numpy as np
import matplotlib as mpl
# import math

min_ = 100
max_ = 500000
step = 100
loop_times = 10000

###########################################################################
# Приводим данные к нужному виду

# Нужно избавиться от копипаста
data = []
with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputLinAvg.txt', 'r') as file:
    for i in file:
        data.append(i.split())

for i in range(len(data)):
    for j in range(len(data[0])):
        data[i][j] = int(data[i][j])

x1 = [i for i in range(min_, max_, step)]
y1 = [0]*((max_ - min_)//step)

for i in range(loop_times):
    for j in range(len(y1)):
        y1[j] += data[i][j]
for i in range(len(y1)):
    y1[i] /= loop_times
    y1[i] /= 1000000
file.close()
data.clear()

with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputLinWorst.txt', 'r') as file:
    for i in file:
        data.append(i.split())

for i in range(len(data)):
    for j in range(len(data[0])):
        data[i][j] = int(data[i][j])

x2 = [i for i in range(min_, max_, step)]
y2 = [0]*((max_ - min_)//step)

for i in range(loop_times):
    for j in range(len(y2)):
        y2[j] += data[i][j]
for i in range(len(y2)):
    y2[i] /= loop_times
    y2[i] /= 1000000
file.close()
data.clear()

with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputBinAvg.txt', 'r') as file:
    for i in file:
        data.append(i.split())

for i in range(len(data)):
    for j in range(len(data[0])):
        data[i][j] = int(data[i][j])

x3 = [i for i in range(min_, max_, step)]
y3 = [0]*((max_ - min_)//step)

for i in range(loop_times):
    for j in range(len(y3)):
        y3[j] += data[i][j]
for i in range(len(y3)):
    y3[i] /= loop_times
    y3[i] /= 1000000
file.close()
data.clear()

with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputBinWorst.txt', 'r') as file:
    for i in file:
        data.append(i.split())

for i in range(len(data)):
    for j in range(len(data[0])):
        data[i][j] = int(data[i][j])

x4 = [i for i in range(min_, max_, step)]
y4 = [0]*((max_ - min_)//step)

for i in range(loop_times):
    for j in range(len(y4)):
        y4[j] += data[i][j]
for i in range(len(y2)):
    y4[i] /= loop_times
    y4[i] /= 1000000
file.close()
data.clear()

##########################################################################

a1 = np.polyfit(x1, y1, 1)  # лин. апрокс.
a2 = np.polyfit(x2, y2, 1)
a3 = np.polyfit(x3, y3, 1)
a4 = np.polyfit(x4, y4, 1)

b1 = np.linspace(0, max_, 1000)  # пространство для отображения графика лин. апрокс.
b2 = np.linspace(0, max_, 1000)
b3 = np.linspace(0, max_, 1000)
b4 = np.linspace(0, max_, 1000)

##########################################################################

fig = plt.figure(figsize=(12, 8))
ax1 = fig.add_subplot(221) # создали Axes (подграфик) ax1 в серии из 2 графиков, поставили на позицию [1,1] -- левый верхний угол
ax2 = fig.add_subplot(222) # создали Axes ax2 в серии из 2 графиков, поставили на позицию [1,2] -- первый график во второй "строке" графиков
ax3 = fig.add_subplot(223)
ax4 = fig.add_subplot(224)
########################
sp = plt.subplot(221)
ax1.plot(x1, y1, 'o-r', c='k', lw=0, alpha = 0.4, mec='r', mew=0, ms=2, label = 'Усредненное значение времени')
ax1.plot(b1, b1*a1[0] + a1[1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)
plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(a) Линейный поиск (случайное событие)', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(222)
ax2.plot(x2, y2, 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax2.plot(b2, b2*a2[0] + a2[1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(b) Линейный поиск (худший случай)', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(223)
ax3.plot(x3, y3, 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax3.plot(b3, b3*a3[0] + a3[1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 2(a) Бинарный поиск (случайное событие)', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(224)
ax4.plot(x4, y4, 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax4.plot(b4, b4*a4[0] + a4[1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 2(b) Бинарный поиск (худший случай)', loc='left')
plt.grid(True)
plt.legend()

########################################################################## 

plt.show()

print('Clear files? y/n')
if (input().lower() == 'y'):
    with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputLinWorst.txt', 'w') as file:
        file = ''
    with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputLinAvg.txt', 'w') as file:
        file = ''
    with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputBinAvg.txt', 'w') as file:
        file = ''
    with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\outputBinWorst.txt', 'w') as file:
        file = ''
