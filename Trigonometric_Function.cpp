// Trigonometric_Function.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;
#define N 5

class Trigonmetric_Func//三角函数类
{
	public:
		double Radian;//弧度数据
		Trigonmetric_Func(double x)
		{
			Radian=x;
		}
		double sin(double x);
		double cos(double x);
		double tan(double x);
		double cot(double x);
		double My_pow(double x,int n);//自定义x的n次方
		
};



double Trigonmetric_Func::sin(double x)
{
	double sum=0;//泰勒展开式之和
	int n_n=0;//泰勒展开式每项前正负符号
	for(int n=0;n<N;n++)//5次循环，求5项泰勒展开式之和
	{
		int m=1;//泰勒展开式分母
		double X;//泰勒展开式每项的分子
		for(int j=1;j<=2*n+1;j++)//泰勒展开式分母阶乘
		{
			m*=j;
		}
		n_n=(int)My_pow(-1,n);//泰勒展开式每项前正负符号（奇正偶负）
		X=My_pow(x,2*n+1);//泰勒展开式每项的分子（X的(2*n+1)次方）
		sum+=(X/m)*n_n;//泰勒展开式之和即所求正弦函数的近似值
		//cout<<"m="<<m<<endl;
		//cout<<"n_n="<<n_n<<endl;
		
		
	}
	return sum;
	
}

double Trigonmetric_Func::cos(double x)
{
	double sum=0;//泰勒展开式之和
	int n_n=0;//泰勒展开式每项前正负符号
	for(int n=0;n<N;n++)//5次循环，求5项泰勒展开式之和
	{
		int m=1;//泰勒展开式分母
		double X;//泰勒展开式每项的分子
		for(int j=1;j<=2*n;j++)//泰勒展开式分母阶乘
		{
			m*=j;
		}
		n_n=(int)My_pow(-1,n);//泰勒展开式每项前正负符号（奇正偶负）
		X=My_pow(x,2*n);//泰勒展开式每项的分子（X的(2*n)次方）
		sum+=(X/m)*n_n;//泰勒展开式之和即所求余弦函数的近似值
		
		
	}
	return sum;
	
}


double Trigonmetric_Func::tan(double x)
{
	double sum=0;//泰勒展开式之和
		double m=0.00000;//泰勒展开式分母

	for(int n=1;n<=N;n++)//5次循环，求5项泰勒展开式之和
	{
		double X;//泰勒展开式每项的分子
		if(n==1)
		{
			m=1;
			
		}
		if(n==2)
		{
			m=(double)1/3;
			
		}
		if(n==3)
		{
			m=(double)2/15;
			
		}
		if(n==4)
		{
			m=(double)17/315;
			
		}
		if(n==5)
		{
			m=(double)62/2835;
			
		}
		
		X=My_pow(x,2*n-1);//泰勒展开式每项的分子（X的(2*n)次方）
		
		sum+=(X*m);//泰勒展开式之和即所求余弦函数的近似值
		
		
	}
	return sum;
	
}


double Trigonmetric_Func::cot(double x)
{
	double sum=0;//泰勒展开式之和
		double m=0.00000;//泰勒展开式分母

	for(int n=0;n<N;n++)//5次循环，求5项泰勒展开式之和
	{
		double X;//泰勒展开式每项的分子
		if(n==0)
		{
			m=1;
			
		}
		if(n==1)
		{
			m=(double)-1/3;
			cout<<"m="<<m<<endl;
		}
		if(n==2)
		{
			m=(double)-1/45;
			cout<<"m="<<m<<endl;
		}
		if(n==3)
		{
			m=(double)-2/945;
			cout<<"m="<<m<<endl;
		}
		if(n==4)
		{
			m=(double)-1/4725;
			cout<<"m="<<m<<endl;
		}
		
		X=My_pow(x,2*n-1);//泰勒展开式每项的分子（X的(2*n)次方）
		
		sum+=(X*m);//泰勒展开式之和即所求余弦函数的近似值
		
		
	}
	return sum;
	
}


double Trigonmetric_Func::My_pow (double x,int y)
{
	double x_x=x;
	if(y>=0)
	{
		if(y==0)
		{
			x_x=1;	
		}
		else
		{
			double accumulate=x;
			for(int j=1;j<=y-1;j++)
			{
				accumulate=accumulate*x;
			}
			x_x=accumulate;
		}
		
	}
	if(y<0)
	{
		double accumulate=x;
		for(int j=-2;j>=y;j--)
			{
				accumulate=x*accumulate;
			}
		x_x=1/accumulate;
	}
	return x_x;
}




void Show_Input(int &number,double &x)
{
	
	cout<<"1、sin(x);"<<endl;
	cout<<"2、cos(x);"<<endl;
	cout<<"3、tan(x);"<<endl;
	cout<<"4、cot(x);"<<endl;
	cout<<"请输入对应三角函数前的序号，选择需要计算的三角函数类型"<<endl;
	cin>>number;
	cout<<"请输入弧度值：";
	cin>>x;
	
}

int main()
{
	int number;//三角函数选项序号
	double x;//待计算三角函数弧度值
	double result;//三角函数计算结果

	
	
	
	Show_Input(number,x);//字符输入界面
	Trigonmetric_Func* ptr=new Trigonmetric_Func(x);
		if(number==1)
		{
				result=ptr->sin(x);
				cout<<"sin("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result<<endl;//保留小数点后四位输出函数计算结果
		}
			
		if(number==2)
		{
				result=ptr->cos(x);
				cout<<"cos("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result<<endl;//保留小数点后四位输出函数计算结果
		}
		if(number==3)
		{
				result=ptr->tan(x);
				cout<<"tan("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result<<endl;//保留小数点后四位输出函数计算结果
		}
		if(number==4)
		{
				result=ptr->cot(x);
				cout<<"cot("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result<<endl;//保留小数点后四位输出函数计算结果
		}
		delete ptr;

	system("pause");
	return 0;
}

