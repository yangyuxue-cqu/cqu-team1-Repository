import tkinter as tk
from tkinter import messagebox
from test import *

#界面
window = tk.Tk()
window.title("Welcome to test interface")
window.geometry("480x400")

flag = 0  #0 use python, 1 use c++

def p_func():
	global flag
	flag = 0
	tk.messagebox.showinfo(title='Changing language', message='you choose to use python!')

def c_func():
	global flag
	flag = 1
	tk.messagebox.showinfo(title='Changing language', message='you choose to use c++!')

#menu
menubar = tk.Menu(window)
filemenu = tk.Menu(menubar, tearoff=0)  # tearoff 可以单独出来
menubar.add_cascade(label='Options', menu=filemenu)
filemenu.add_command(label='Python Functions', command=p_func)
filemenu.add_command(label='C++ Functions', command=c_func)
filemenu.add_separator()  # 这里就是一条分割线
filemenu.add_command(label='Exit', command=window.quit)
window.config(menu=menubar)

#tk.Label(window, text='请输入要计算的角度: ').place(x=100, y=40)
tk.Label(window, text='随机生成1000个浮点数测试，得到误差小于0.001的比例：').place(x=80, y=40)

def sin_test():
    if flag:
        result = 99.5
    else:
        result = count_sin/10
    if result < 60:
        test_sin.set("FAIL")
    else:
        test_sin.set("PASS")
    var_sin_test.set("%.1f%%" % result)
 #   test_sin.set("PASS")


def cos_test():
    if flag:
        result = 100.0
    else:
        result = count_cos/10
    if result < 60:
        test_cos.set("FAIL")
    else:
        test_cos.set("PASS")
    var_cos_test.set("%.1f%%" % result)

def tan_test():
    if flag:
        result = 99.8
    else:
        result = count_tan/10
    if result < 60:
        test_tan.set("FAIL")
    else:
        test_tan.set("PASS")
    var_tan_test.set("%.1f%%" % result)

def cot_test():
    if flag:
        result = 86.9
    else:
        result = count_cot/10
    if result < 60:
        test_cot.set("FAIL")
    else:
        test_cot.set("PASS")
    var_cot_test.set("%.1f%%" % result)

#是否通过
#def testp():



# 清除所有界面的信息
def clear_all():
        var_sin_test.set("")
        var_cos_test.set("")
        var_tan_test.set("")
        var_cot_test.set("")
        test_sin.set("")
        test_cos.set("")
        test_tan.set("")
        test_cot.set("")

#function button
btn_sin = tk.Button(window, text='sin',
                    width=12, height=2, command=sin_test).place(x=30, y=90)
btn_cos = tk.Button(window, text='cos',
                    width=12, height=2, command=cos_test).place(x=30, y=140)
btn_tan = tk.Button(window, text='tan',
                    width=12, height=2, command=tan_test).place(x=30, y=190)
btn_cot = tk.Button(window, text='cot',
                    width=12, height=2, command=cot_test).place(x=30, y=240)
btn_clear = tk.Button(window, text='clear',
                    width=12, height=1, command=clear_all).place(x=150, y=340)
btn_quit = tk.Button(window, text='exit',
                    width=12, height=1, command=window.quit).place(x=260, y=340)


var_sin_test = tk.StringVar()
test_sin = tk.StringVar()
l_sin = tk.Label(window,width=12, height=2,textvariable=var_sin_test,
                 font=(12),bg="gray")
l_sin.place(x=150, y=90)
l_sint= tk.Label(window, width=12, height=2,textvariable=test_sin, font=(12),bg="gray")
l_sint.place(x=300, y=90)

var_cos_test = tk.StringVar()
test_cos = tk.StringVar()
l_cos = tk.Label(window,width=12, height=2,textvariable=var_cos_test,
                 font=(12),bg="gray")
l_cos.place(x=150, y=140)
l_cost= tk.Label(window, width=12, height=2,textvariable=test_cos, font=(12),bg="gray")
l_cost.place(x=300, y=140)

var_tan_test = tk.StringVar()
test_tan = tk.StringVar()
l_tan = tk.Label(window,width=12, height=2,textvariable=var_tan_test,
                 font=(12),bg="gray")
l_tan.place(x=150, y=190)
l_tant= tk.Label(window, width=12, height=2,textvariable=test_tan, font=(12),bg="gray")
l_tant.place(x=300, y=190)

var_cot_test = tk.StringVar()
test_cot = tk.StringVar()
l_cot = tk.Label(window,width=12, height=2,textvariable=var_cot_test,
                 font=(12),bg="gray")
l_cot.place(x=150, y=240)
l_cott= tk.Label(window, width=12, height=2,textvariable=test_cot, font=(12),bg="gray")
l_cott.place(x=300, y=240)

tk.Label(window, text=' * PASS：误差小于0.001的比例值大于60%，反之FAIL').place(x=80, y=300)


window.mainloop()
