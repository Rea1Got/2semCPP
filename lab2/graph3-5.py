import matplotlib.pyplot as plt 
import numpy as np
import matplotlib as mpl
# import math

max_ = 10000
step = 10
loop_times = 10

files = ["3-5_firstTest.txt", "3-5_secondTest.txt", "3-5_thirdTest.txt"]

###########################################################################
# Приводим данные к нужному виду
x = [[],[],[]]
tmp = [[],[],[]]

for k in range(3):
    data = []
    with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab2\\' + files[k], 'r') as file:
        for i in file:
            for j in i.split():
                #if (int(j) != 0 and int(j) != 1163005939):
                data.append(int(j))
    x[k] = [i for i in range(max_)]
    tmp[k] = data.copy()
    for i in range(max_):
        tmp[k][i] += tmp[k][i+10000] + tmp[k][i+20000] + tmp[k][i+30000] + tmp[k][i+40000]
        tmp[k][i] /= 5
    print(len(x[k]), len(tmp[k]))
    file.close()
    data.clear()

    
# for k in range(3):
#     data = []
#     with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab2\\' + files[k], 'r') as file:
#         for i in file:
#             data.append(i.split())

#     for i in range(len(data)):
#         for j in range(len(data[0])):
#             data[i][j] = int(data[i][j])

#     x[k] = [i for i in range(min_, max_, step)]
#     y[k] = [0]*((max_ - min_)//step)

#     for i in range(len(data)):
#         y[k][i] += sum(data[i])
#     for i in range(len(y[k])):
#         y[k][i] /= loop_times
#         y[k][i] /= 1000
#     file.close()
#     data.clear()

##########################################################################

a = []
y = [[],[],[]]
for i in range(3):
    for j in range(max_):
        y[i].append(tmp[i][j])
    print(len(x[i]), len(y[i]))
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
plt.ylabel(r'$t, 10^{-6} с$')
plt.title('Рис. 1(a) Добавление одного элемента', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(312)
ax2.plot(x[1], y[1], 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax2.plot(b[1], b[1]*a[1][0] + a[1][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-6} с$')
plt.title('Рис. 1(б) Добавление фиксированного числа элементов', loc='left')
plt.grid(True)
plt.legend()

#######################
sp = plt.subplot(313)
ax3.plot(x[2], y[2], 'o-r', c='k', lw=0, mec='r', alpha=0.4, mew=0, ms=2, label = 'Усредненное значение времени')
ax3.plot(b[2], b[2]*a[2][0] + a[2][1], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)

plt.xlabel('N, количество переменных')
plt.ylabel(r'$t, 10^{-6} с$')
plt.title('Рис. 1(в) создание массива удвоенного размера', loc='left')
plt.grid(True)
plt.legend()

########################################################################## 

plt.show()

print('Clear files? y/n')
if (input().lower() == 'y'):
    for i in range(3):
        with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab2\\' + files[i], 'w') as file:
            file = ''