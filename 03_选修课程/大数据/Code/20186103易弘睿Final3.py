"""
Name:           易弘睿
Number:         20186103
Project:        Test_3
Time:           April 28 2022
"""

import re
import numpy as np
import pandas as pd

docs = ["In 2007,this is ill.",
        "They remove animal story.",
        "They adapted this story."]

# 要求1：利用正则表达式对文档进行分词。(10分)
r = "([0-9a-zA-Z]{1,100})"
resSheet = [re.findall(r, i) for i in docs]
words = [j for i in resSheet for j in i]
word = []
for i in words:
    if i not in word:
        word.append(i)
    if ' ' not in word and i == 'ill':
        word.append(' ')

# 要求2：按照图3所示对文档进行表示和输出。(20分)
data = np.array([[j.count(i) for i in word] for j in resSheet], dtype='float64')

# 题目中有对空格计数,此处将该行置1
df = pd.DataFrame(data=data, columns=word, index=['文档{}'.format(i + 1) for i in range(3)])
for i in range(3):
    df[' '][i] = 1
print(df)
