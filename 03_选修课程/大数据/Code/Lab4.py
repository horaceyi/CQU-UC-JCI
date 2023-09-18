import pandas as pd
import numpy as np


def read_files(path):
    with open(path) as f:
        lines = f.readlines()
    return lines


def line_process(sub_line, headers, stud_dict):
    sub_line = sub_line.split()
    student_inf = sub_line[11:]
    saving_inf = [[] for _ in headers]
    for student_index in range(0, len(student_inf), 10):
        for inf_index, sub_inf in enumerate(saving_inf):
            if inf_index == len(saving_inf)-1:
                sub_inf.append(None)
            else:
                sub_inf.append(student_inf[student_index+inf_index])
    if len(stud_dict.get(headers[0], [])) == 0:
        new_dict = dict(zip(headers, saving_inf))
    else:
        for index_inf, (keys, values) in enumerate(stud_dict.items()):
            values.extend(saving_inf[index_inf])
        new_dict = stud_dict
    return new_dict


def read_in_pandas(path):
    total_lines = read_files(path=path)
    sample_line = total_lines[0].split()
    header = sample_line[:11]

    student_dict = {}
    for line in total_lines:
        student_dict = line_process(line, header, student_dict)

    total_df = pd.DataFrame(student_dict)
    total_df = total_df.set_index("序号")
    total_df["初试总分"] = total_df["初试总分"].values.astype(int)
    total_df["复试总分"] = total_df["复试总分"].values.astype(float)
    total_df["综合成绩"] = total_df["综合成绩"].values.astype(float)
    # 返回学生表
    return total_df


def Q1(stud_df, threshold):
    print("所有学生的成绩分布如下：")
    categories = set(stud_df["报考专业"])
    for category in categories:
        category_df = stud_df[stud_df["报考专业"] == category]
        print("专业: {} 总人数: {}".format(category, len(category_df)))
        category_low_grade = threshold[category]
        category_high_grade = category_df["初试总分"].max()
        for grade in range(category_low_grade, category_high_grade, 10):
            nums = len(category_df[(category_df["初试总分"] >= grade) & (category_df["初试总分"] < grade+10)])
            print("分数区间: {} - {} 人数: {}".format(grade, grade+10, nums))


def Q2(stud_df, threshold):
    print("已通过复试的成绩分布如下：")
    categories = set(stud_df["报考专业"])
    for category in categories:
        category_df = stud_df[(stud_df["报考专业"] == category) & (stud_df["录取结果"] == "录取")].copy(deep=True)
        print("专业: {} 通过人数: {}".format(category, len(category_df)))
        category_low_grade = threshold[category]
        category_high_grade = category_df["初试总分"].max()
        for grade in range(category_low_grade, category_high_grade, 10):
            nums = len(category_df[(category_df["初试总分"] >= grade) & (category_df["初试总分"] < grade+10)])
            print("分数区间: {} - {} 人数: {}".format(grade, grade+10, nums))


def Q3(stud_df, enroll):
    stud_df["录取结果"] = "待定"
    categories = set(stud_df["报考专业"])
    for category in categories:
        category_df = stud_df[stud_df["报考专业"] == category].copy(deep=True)
        special_student = category_df[(category_df["专项计划"] != "无") & (category_df["复试总分"] >= 60)]
        for special_index in special_student.index:
            stud_df.loc[special_index, "录取结果"] = "录取"
            category_df = category_df.drop([special_index], axis=0)
        remain_nums = enroll[category] - len(special_student)
        category_df.sort_values(by=['综合成绩'], ascending=False, inplace=True)
        for change_index in category_df.iloc[:remain_nums].index:
            stud_df.loc[change_index, "录取结果"] = "录取"
    print(stud_df)
    return stud_df


def Q4(stud_df):
    stud_df["奖学金等级"] = None
    categories = set(stud_df["报考专业"])
    for category in categories:
        category_df = stud_df[(stud_df["报考专业"] == category) & (stud_df["录取结果"] == "录取")].copy(deep=True)
        category_df.sort_values(by=['综合成绩'], ascending=False, inplace=True)
        category_df["奖学金等级"] = pd.qcut(list(category_df["综合成绩"]), [0, 0.2, 0.6, 1], labels=["C", "B", "A"])
        special_student = category_df[category_df["专项计划"] != "无"]
        category_df.loc[special_student.index, "奖学金等级"] = "A"
        for changing_index in category_df.index:
            stud_df.loc[changing_index, "奖学金等级"] = category_df.loc[changing_index, "奖学金等级"]
    writer = pd.ExcelWriter("研究生奖学金.xlsx")
    stud_df.to_excel(writer)
    writer.save()


file_path = "计算机学院2022年硕士研究生复试成绩公示.txt"
stu_df = read_in_pandas(file_path)
lowest_grade = {"081200计算机科学与技术": 330, "085400电子信息": 360}
enroll_nums = {"081200计算机科学与技术": 13, "085400电子信息": 70}
Q1(stu_df, lowest_grade)
stu_df = Q3(stu_df, enroll_nums)
Q2(stu_df, lowest_grade)
Q4(stu_df)