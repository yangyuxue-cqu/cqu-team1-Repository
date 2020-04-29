n=5
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
    return sin(x)/cos(x)

def cot(x):
    return cos(x)/sin(x)
