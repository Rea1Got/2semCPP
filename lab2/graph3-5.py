import matplotlib.pyplot as plt 
import numpy as np
import matplotlib as mpl
# import math

max_ = 10000
loop_times = 4

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
    # for i in range(max_):
    #     tmp[k][i] += tmp[k][i+10000] + tmp[k][i+20000] + tmp[k][i+30000] + tmp[k][i+40000]
    #     tmp[k][i] /= 5
    #print(len(x[k]), len(tmp[k]))
    # for i in range(max_):
    #     tmp[k][i] = 0
    #     for j in range(loop_times):
    #         tmp[k][i] += tmp[k][i + max_*j]
    
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
x_fit = []
y_fit = []
for i in range(3):
    for j in range(max_):
        y[i].append(tmp[i][j])
        y[i][j] /= 1000000

    a.append(np.polyfit(x[i], y[i], 3))
    p = np.poly1d(a[i])
    x_fit.append(np.linspace(min(x[i]), max(x[i]), 500))
    y_fit.append(p(x_fit))





##########################################################################

fig = plt.figure(figsize=(12, 12))
ax1 = fig.add_subplot(311)
ax2 = fig.add_subplot(312)
ax3 = fig.add_subplot(313)
ax = []
ax.append(ax1)
ax.append(ax2)
ax.append(ax3)
########################
for i in range(3):
    sp = plt.subplot(310 + i + 1)
    ax[i].set_xscale('log')
    ax[i].plot(x[i], y[i], 'o-r', c='k', lw=0, alpha = 0.4, mec='r', mew=0, ms=2, label = 'Усредненное значение времени')
    ax[i].plot(x_fit[i], y_fit[0][0], 'o-r', alpha=0.6, c='r', lw=1, mec='r', mew=0, ms=0)
    plt.xlabel('N, количество элементов')
    plt.ylabel(r'$t, мс$')
    plt.title('Рис. 1(a) Добавление одного элемента', loc='left')
    plt.grid(True)
    plt.legend()

########################################################################## 

plt.show()

print('Clear files? y/n')
if (input().lower() == 'y'):
    for i in range(3):
        with open('D:\\Study\\Programming\\2 sem\\2semestry_cpp\\lab2\\' + files[i], 'w') as file:
            file = ''