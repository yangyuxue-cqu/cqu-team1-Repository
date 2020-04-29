#阶乘函数
def r(a):
    sum=1
    for i in range(1,a+1):
        sum*=i
    return sum

def sin(x):
    i=1
    f=-1
    s=0
    num=0
    while True:
        f=f*(-1)
        g=2*i-1
        b=r(g)
        t=2*i-1
        m=pow(x,t)
        s+=m*f/b
        i+=1
        num+=1
        if(num==n):
            break
    return s

def cos(x):
    i=0
    f=-1
    s=0
    num=0
    while True:
        f=f*(-1)
        g=2*i
        b=r(g)
        t=2*i
        m=pow(x,t)
        s+=m*f/b
        i+=1
        num+=1
        if(num==n):
            break
    return s

def tan(x):
    s=0
    i=0
    while i<=4:
        if i==0:
            m=1
        if i==1:
            m=1/3
        if i==2:
            m=2/15
        if i==3:
            m=17/315
        if i==4:
            m=62/2835
        t=pow(x,2*i+1)
        s+=t*m
        i+=1
    return s

def cot(x):
    s=0
    i=0
    while i<=4:
        if i==0:
            m=1
        if i==1:
            m=(-1)/3
        if i==2:
            m=(-1)/45
        if i==3:
            m=(-2)/945
        if i==4:
             m=(-1)/4725
        t=pow(x,2*i-1)
        s+=t*m
        i+=1
    return s


import random
import math

PI=3.1415926
n=5
num_test=0
count_sin=0
count_cos=0
count_tan=0
count_cot=0
while num_test<1000:
    a = random.uniform(0.01, PI)
    C = 2  # 随机数的精度round(数值，精度)
    ran=round(a, C)
    dis_sin=abs(sin(ran)-math.sin(ran))
    dis_cos = abs(cos(ran) - math.cos(ran))
    #dis_tan = abs(tan(ran) - math.tan(ran))
    #dis_cot = abs(cot(ran) - 1/math.tan(ran))
    dis_tan = abs(sin(ran)/cos(ran)-math.sin(ran)/math.cos(ran))
    dis_cot = abs(cos(ran)/sin(ran) - math.cos(ran)/math.sin(ran))
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

