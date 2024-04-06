import matplotlib.pyplot as plt 
import numpy as np
import matplotlib as mpl
# import math

min_ = 1000
max_ = 1000000
step = 1000
loop_times = 100

files = "3-5_firstTest.txt", "3-5_secondTest.txt", "3-5_thirdTest"

###########################################################################
# Приводим данные к нужному виду
x = [[],[],[]]
y = [[],[],[]]
# Нужно избавиться от копипаста
for k in range(1):
    data = []
    with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab2\\' + files[k], 'r') as file:
        for i in file:
            data.append(i.split())

    for i in range(len(data)):
        for j in range(len(data[1])):
            data[i][j] = int(data[i][j])

    x[k] = [i for i in range(min_, max_+step, step)]
    y[k] = [0]*((max_ - min_)//step + 1)

    for i in range(loop_times):
        for j in range(len(y[k])):
            y[k][j] += data[j][i]
    for i in range(len(y[k])):
        y[k][i] /= loop_times
        y[k][i] /= 1000000
    file.close()
    data.clear()

##########################################################################

a1 = np.polyfit(x[0], y[0], 1)  # лин. апрокс.
# a2 = np.polyfit(x[1], y[1], 1)

b1 = np.linspace(0, max_, 1000)  # пространство для отображения графика лин. апрокс.
# b2 = np.linspace(0, max_, 1000)


##########################################################################

fig = plt.figure(figsize=(12, 8))
ax1 = fig.add_subplot(211) # создали Axes (подграфик) ax1 в серии из 2 графиков, поставили на позицию [1,1] -- левый верхний угол
# ax2 = fig.add_subplot(212) # создали Axes ax2 в серии из 2 графиков, поставили на позицию [1,2] -- первый график во второй "строке" графиков
########################
sp = plt.subplot(211)
ax1.plot(x[0], y[0], 'o-r', c='k', lw=0, alpha = 0.4, mec='r', mew=0, ms=2, label = 'Усредненное значение времени')
ax1.plot(b1, b1*a1[0] + a1[1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)
plt.xlabel('N, количество элементов')
plt.ylabel(r'$t, 10^{-3} с$')
plt.title('Рис. 1(a) Полный перебор', loc='left')
plt.grid(True)
plt.legend()

#######################
# sp = plt.subplot(212)
# ax2.plot(x2, y2, 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
# ax2.plot(b2, b2*a2[0] + a2[1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

# plt.xlabel('N, количество переменных')
# plt.ylabel(r'$t, 10^{-3} с$')
# plt.title('Рис. 1(b) Линейный поиск', loc='left')
# plt.grid(True)
# plt.legend()

########################################################################## 

plt.show()

print('Clear files? y/n')
if (input().lower() == 'y'):
    for i in range(3):
        with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab1\\' + files[i], 'w') as file:
            print('lol')

