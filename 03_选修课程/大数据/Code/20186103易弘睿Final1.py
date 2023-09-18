"""
Name:           易弘睿
Number:         20186103
Project:        Test_1
Time:           April 28 2022
"""

import math

# 要求1:数字输入(5分)
a = input("请输入第一个阿凡达数字: ")
b = input("请输入第二个阿凡达数字: ")
# print(a, b)

# 要求2:数字交换(5分)
def replaceBigger2First(m, n):
    if len(m) > len(n):
        _m, _n = m, n
    else:
        _m, _n = n, m
    return _m, _n
a, b = replaceBigger2First(a, b)
# print(a, b)

# 要求3:数字对齐(10分)
def addZero2Smaller(m, n):
    _m, _n = replaceBigger2First(m, n)
    _n = '{}{}'.format('#' * (len(_m) - len(_n)), n)
    return _m, _n
a, b = addZero2Smaller(a, b)
# print(a, b)

# 要求4:数字相加(20分)
dict2num = {'#': 0, '%': 1, '&': 2} # 字符到数字的映射
num2dict = {0: '#', 1: '%', 2: '&'} # 数字到字符的映射

# 进制转换
def translateStr2Num(t):
    return sum((dict2num[t[len(t) - 1 - i]] * (3 ** i)) for i in range(len(t)))

# 不断从两个计算数的低位向高位循环进行(1)和(2)
def add(m, n):
    _m, _n = m, n
    resString = ''
    resNumber = translateStr2Num(_m) + translateStr2Num(_n)
    l = math.ceil(math.log(resNumber, 3))
    while resNumber:
        resString += num2dict[resNumber % 3]
        resNumber //= 3
    if len(resString) != l:
        resString = '{}{}'.format(resString, '#' * (l - len(resString)))
    return resString[::-1]

# print(translateStr2Num(a), translateStr2Num(b))
res = add(a, b)
print('求和后输出结果为：', res)
print('转换十进制后结果：', translateStr2Num(res))
