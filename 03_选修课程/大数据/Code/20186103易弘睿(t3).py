import pandas as pd

def read_txt(file_name):
    with open(file_name) as file:
        count = file.readlines()
    blank=''
    for i in count:
        blank+=i.strip()
    lines=blank.strip().split(' ')
    return lines

lines=read_txt('计算机学院2022年硕士研究生复试成绩公示.txt')
data=[]
temp=[]
for i in range(len(lines)):
    temp.append(lines[i])
    if i!=0 and i%10==0:
        data.append(temp)
        temp=[]
title=data[0]
data=data[1:]
df=pd.DataFrame(data,columns=title[:-1])
df.index=df['序号']
df=df.drop('序号', axis=1)
print(df)