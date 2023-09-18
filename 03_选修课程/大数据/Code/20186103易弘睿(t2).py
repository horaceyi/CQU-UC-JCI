import numpy as np
import pandas
import collections

alphabet = [chr(i) for i in range(97, 123)]                     #字母表生成
letters_random = np.random.choice(alphabet, 1000, replace=True) #生成1000个随机字母
count = dict(collections.Counter(letters_random))               #字母个数统计
for key, value in count.items():
    print("{} : {}".format(key, value))