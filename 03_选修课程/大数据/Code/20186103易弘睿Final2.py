"""
Name:           易弘睿
Number:         20186103
Project:        Test_2
Time:           April 28 2022
"""

import pandas as pd
import numpy as np

np.random.seed(1)

# 要求1：利用Numpy和Pandas一次产生三位玩家10轮抛的结果，并输出如图1所示。(10分)
sheet = np.random.randint(1, 7, size=(10, 3))
col = ['玩家{}'.format(i + 1) for i in range(3)]
idx = ['第{}轮'.format(i + 1) for i in range(10)]
df = pd.DataFrame(data=sheet, columns=col, index=idx)
print(df)

# 提示1&2：找到每一轮中的骰子的最大值，将每一行的数字除以该行最大值
sheet = np.array([i / max(i) for i in sheet])
# print(sheet)

# 提示3：将提示2中结果中的每一个小于1的数字全部置为0
for i in range(len(sheet)):
    for j in range(len(sheet[i])):
        sheet[i][j] = 0 if abs(sheet[i][j] - 1) >= 10e-4 else sheet[i][j]
cntSheet = pd.DataFrame(data=sheet, columns=col, index=idx)
# print(cntSheet)

# 提示4：按列统计每位玩家的获胜次数
cnt = np.array([[sum(cntSheet.loc[:, col[i]])] for i in range(3)], dtype='float64')
# print(cnt)

# 要求2：每位玩家获胜次数的统计结果如图2所示。(20分)
res = pd.DataFrame(data=cnt, columns=['次数'], index=['玩家{}'.format(i + 1) for i in range(3)])
print(res)
