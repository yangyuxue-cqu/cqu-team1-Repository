import random
import math
import function

PI=3.1415926
num_test=0
count_sin=0
count_cos=0
count_tan=0
count_cot=0
while num_test<1000:
    a = random.uniform(0.01, PI)
    C = 2  # 随机数的精度round(数值，精度)
    ran=round(a, C)
    dis_sin=abs(function.sin(ran)-math.sin(ran))
    dis_cos = abs(function.cos(ran) - math.cos(ran))
    #dis_tan = abs(tan(ran) - math.tan(ran))
    #dis_cot = abs(cot(ran) - 1/math.tan(ran))
    dis_tan = abs(function.sin(ran)/function.cos(ran)-math.sin(ran)/math.cos(ran))
    dis_cot = abs(function.cos(ran)/function.sin(ran) - math.cos(ran)/math.sin(ran))
    if dis_sin<0.001:
        count_sin+=1
    if dis_cos<0.001:
        count_cos+=1
    if dis_tan<0.001:
        count_tan+=1
    if dis_cot<0.001:
        count_cot+=1
    num_test+=1

#print('Function sin(x) test completed,', '%.2f%%' % (count_sin/10) ,'passed verification')
#print('Function cos(x) test completed,', '%.2f%%' % (count_cos/10) ,'passed verification')
#print('Function tan(x) test completed,', '%.2f%%' % (count_tan/10) ,'passed verification')
#print('Function cot(x) test completed,', '%.2f%%' % (count_cot/10) ,'passed verification')

