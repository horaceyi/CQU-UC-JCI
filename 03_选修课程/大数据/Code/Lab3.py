import tushare as ts
import pandas as pd
import os       # 引用操作目录用来下载和分类每个industry的日k
import shutil
import time     # 用作每分钟500次的权限

# #清空数据集的文件夹
# def clearData():
#     basedir = r".\data"
#     if os.path.exists(basedir):
#         shutil.rmtree(basedir)
#     os.mkdir(basedir)
#
# #获取全部股票列表
# def getStockBasic():
#     stock_basic = pro.stock_basic(exchange='', list_status='L', fields='ts_code,symbol,name,area,industry,list_date')
#     return stock_basic
#
# #获取不重复的工业领域列表
# def getCodesAndIndusrty(stock_basic):
#     industries=stock_basic['industry'].values
#     industries=list(set(industries))
#     return industries
#
# #获取指定工业的股票代码列表
# def getIndustryCodes(stock_basic,industry):
#     industry_codes=stock_basic[stock_basic.industry==industry].ts_code.values
#     return industry_codes
#
# #下载指定工业的股票的交易数据
# def downloadStockTrans(industry,industry_codes):
#     basedir = r".\data"
#     #创建存放指定工业交易数据的文件夹
#     subdir = os.path.join(basedir, industry)
#     os.mkdir(subdir)
#
#     for code in industry_codes:
#         trans_filename=os.path.join(subdir,code+".txt")
#         print(code,trans_filename)
#         stock_trans=pro.daily(ts_code=code, start_date='20210101', end_date='20211231')
#         #按照交易日期进行升序排列
#         stock_trans=stock_trans.sort_values(by='trade_date',ascending=True)
#         #讲pandas的dataframe写入文件，指定写入时去掉行索引
#         stock_trans.to_csv(trans_filename,index=False)
#
# #处理所有工业领域的数据
# def processIndustries(industries):
#     for i in range(0,len(industries),3):
#         for industry in industries[i:i+3]:
#             industry_codes = getIndustryCodes(stock_basic, industry)
#             print(industry,":",industry_codes)
#             downloadStockTrans(industry, industry_codes)
#         # 等待30s以解决访问限制500次/min的问题
#         time.sleep(30)
#
# #连接数据库获取工业列表
# pro = ts.pro_api('0ff3b82a52cd617c7590b7204cf959ce951cec5e8f6a9385bb6bd655')
# stock_basic=getStockBasic()
# industries=getCodesAndIndusrty(stock_basic)
# print(industries)
# clearData()
#
# #去除工业类别为NONE的类并完成下载
# industries1 = [k for k in industries if k != None]
# print(industries1)
# processIndustries(industries1)

# 得到每只股票在2021年的总成交量
filename=os.listdir('./data/')
all_2021=dict()
for i in filename:
    one_type=dict()
    for j in os.listdir('./data/'+i+'/'):
        data=pd.read_csv('./data/'+i+'/'+j)
        one_type[j[:-4]]=round(sum(data['vol']),2)
    all_2021[i]=one_type
print('每只股票在2021年的总成交量',all_2021)

# 得到每个工业类别中成交量最大的股票
all_max=dict()
for i,j in all_2021.items():
    li=sorted(j.items(), key=lambda d: d[1], reverse=True)
    all_max[i]=li[0]
print('每个工业类别中成交量最大的股票',all_max)

# 得到所有工业类别的成交量最大股票的数据集并按照成交量降序排列后输出
lii=sorted(all_max.items(), key=lambda d: d[1][1], reverse=True)
print('按照成交量降序排列后输出',lii)
name=['类别','data']
lii=pd.DataFrame(columns=name,data=lii)
lii.to_csv('成交量最大股票降序排列.csv',encoding='gbk')

