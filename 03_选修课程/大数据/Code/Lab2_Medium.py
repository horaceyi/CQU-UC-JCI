import unicodedata as ucd

def de_duplication(str):
    dedup_str = ''
    for char in str:
        if not char in dedup_str:
            dedup_str += char
    return dedup_str

#读取文件
with open('三国演义.txt ', 'r', encoding="utf-8") as f:
    data = f.read()
word = ucd.normalize('NFKC',data).replace(',', '').replace('.', '').replace('。', '').replace('\‘', '').replace('“', '')\
    .replace('”','').replace('《', '').replace('》', '').replace('’', '').replace(';', "").replace('\n', '')\
    .replace('? ', '').replace(':', '').replace('；','' ).replace( '-', '').replace('!', '')\
    .replace( '、', '').replace( '(', '').replace( ')', '').replace('——', '').replace(' ', '')
word = list(word)
word_list = de_duplication(word)

#创建密码
code = []
for i in range(1,10000):
    code1 = []
    p = "{:0>4d}".format(i)
    code1.extend(p)
    for j in range(1, 21):
        code2 = []
        code2.extend(code1)
        r = "{:0>2d}".format(j)
        code2.extend(r)
        for k in range(1,21):
            code3 = []
            code3.extend(code2)
            c = "{:0>2d}".format(k)
            code3.extend(c)
            code.append("".join(code3))

#解密
decrypt = dict(zip(code, word))

#加密
vs = decrypt.values()
ks = decrypt.keys()
encrypt = dict(zip(vs,ks))

#交互
x = list(input('请输入语句：'))
for key in x:
    print(encrypt.get(key),'\t',end="")
print('\n')

y = input('请输入代码： ')
y = y.split(' ')
for key in y:
    print(decrypt.get(key), '\t', end="")