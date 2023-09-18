import random
import operator

def cal(a, x, y):
    if a == 0:
        return x + y
    elif a == 1:
        return x - y
    elif a == 2:
        return x * y
    else:
        return x / y

file_handle = open('Arithmetic.txt', mode='a')
file = open("Arithmetic.txt", 'w').close()
op = ('+', '-', '×', '÷')
res = []
i = 1

m,n=eval(input("请输入行数和列数（m,n）:"))
print(m,n)
res = ""
exist = []

while i <= m*n:
    flag=True
    while flag:
        x = random.randint(10, 50)
        y = random.randint(10, 50)
        a = random.randint(0, 3)
        result = cal(a, x, y)
        if a == 0:
            res = "%d %s %d = " % (x, op[a], y)
        elif a == 1:
            res = "%d %s %d = " % (x, op[a], y)
        elif a == 2:
            res = "%d %s %d = " % (x, op[a], y)
        elif a == 3:
            res = "%d %s %d = " % (x, op[a], y)
            if y == 0:
                continue
        if res not in exist:
            flag=False
            file_handle.writelines(res)
            file_handle.write('    ')
            if i % n == 0:
                file_handle.write(' \n')
            exist.append(res[:])
            print(exist)
            print(res)
    i += 1
file_handle.close()