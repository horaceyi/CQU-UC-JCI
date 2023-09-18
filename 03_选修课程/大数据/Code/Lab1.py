"""
Name:           易弘睿
Number:         20186103
Project:        Laboratory_1
Time:           Feb 19 2022
"""

import math
import numpy as np

#定义积分函数
def y(x):
    y = pow(x,2)+4*x*math.sin(x)
    return y

#定义积分范围、点的个数
x_range = [2,3]
points = 1000000
hits = 0
x_list = []
y_list = []

#确定函数在区间内的最大值
# y_max = 0
# for index in np.arange(2,3.00001,0.00001):
#     y_test = pow(index,2)+4*math.sin(index)
#     if y_test >= y_max:
#         y_max = y_test

# 生成points个随机点
for i in range(points):
    # 3：在矩形内生成随机点（x，y）
    rand_x = np.random.uniform(x_range[0], x_range[1], size=1)
    # y起始值为0，y的函数值一定会小于遍历出的最大值
    # rand_y = np.random.uniform(0, y_max, size=1)
    rand_y = np.random.uniform(0, 20, size=1)
    x_list.append(rand_x)
    y_list.append(rand_y)

    # 判断随机点是否在曲线下方，如果在曲线下方则计数器加1
    if y(rand_x) >= rand_y:
       hits += 1

# 根据曲线下方点个数和总点数的比例就是面积比
# rectangle_area = (x_range[1] - x_range[0]) *y_max
rectangle_area = (x_range[1] - x_range[0]) *20
curve_area = (float(hits) / float(points)) * rectangle_area
print('integral is: ',curve_area)

