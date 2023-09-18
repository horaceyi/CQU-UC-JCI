# 读取文件
def load_file(pathinp):
    file = open(pathinp, 'r', encoding='utf-8')
    allcharc = list(file.read())
    file.close()
    return allcharc

# 去除字符串的标点符号并统计字母出现次数
def statistics(inptchar):
    dictstastis={}
    for i in inptchar:
        if (97 <= ord(i) < 123) or (65 <= ord(i) < 91):
            if i.lower() in dictstastis:
                dictstastis[i.lower()] += 1
            else :
                dictstastis[i.lower()] = 1
    dictstastis = dict(sorted(dictstastis.items(), key=lambda item:item[1], reverse=True))
    return dictstastis

# 产生加密表
def cipher(num):
    cipher_dict = {}
    chri = [chr(i) for i in range(97, 123)]                      #产生26字母

    for i in range(26 - num):
        cipher_dict[chri[i]] = chr(ord(chri[i]) + num)           #字母整体移动
    for i in range(num):
        cipher_dict[chri[26 - num + i]] = chr(ord(chri[i]))
    return cipher_dict

# 加密
def encode(inpfile,cipher_dict):
    ciphertxt = []
    for m in inpfile:
        if  (97 <= ord(m) < 123) or (65 <= ord(m) < 91):
            ciphertxt.append(cipher_dict[m.lower()])
        else:
            ciphertxt.append(m)
    return ciphertxt

# 解密
def decode(cipher,sta):
    deco_dictstastis={}
    for n in cipher:
        if (97 <= ord(n) < 123) or (65 <= ord(n) < 91):
            if n in deco_dictstastis:
                deco_dictstastis[n] += 1
            else :
                deco_dictstastis[n] = 1
    deco_dictstastis = dict(sorted(deco_dictstastis.items(), key=lambda item:item[1], reverse=True))
    print('统计密文字母出现次数： ')
    print(deco_dictstastis)
    decode_dict=dict(list(zip(deco_dictstastis.keys(),sta.keys())))
    return decode_dict


def main():
    voatxt:list = []
    for i in range(60):
        path = 'VOA语料\\'+str(i)+'.txt'
        readtxt = load_file(path)
        voatxt = voatxt + readtxt
    occurrencessta = statistics(voatxt)
    print('统计明文文章中字母出现次数： ')
    print(occurrencessta)
    cipher_dict = cipher(6)
    print('定义的密码表为（字母向右移动六位）： ')
    print(cipher_dict)
    # 加密
    svoatxt: list = []
    for i in range(60):
        path2 = 'VOA语料\\'+str(i)+'.txt'
        sreadtxt = load_file(path2)
        svoatxt = svoatxt + sreadtxt
    endoce_txt = encode(svoatxt,cipher_dict)
    # print(''.join(endoce_txt))                         #如果需要输出密文可以取消注释
    # 解密
    decode_dict = decode(endoce_txt,occurrencessta)
    decode_table={}
    cipvalue = cipher_dict.values()
    for k in cipvalue:
       decode_table[k] = decode_dict[k]
    print('解码产生的密码表为： ')
    print(decode_table)

if __name__ == '__main__':
    main()