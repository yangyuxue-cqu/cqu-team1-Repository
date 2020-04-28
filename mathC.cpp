/*
 * mathC.cpp
 *
 *  Created on: 2020年4月27日
 *      Author: hi
 */

#include<iostream>
#include<iomanip>
#include<stdlib.h>//rand函数使用库函数
#include<time.h>
#include<math.h>//对比精度用

using namespace std;
#define N 7
#define pi 3.1415926

class Trigonmetric_Func//三角函数类
{
	public:
		double Radian;//弧度数据
		Trigonmetric_Func(double x)
		{
			Radian=x;
		}
		double mysin(double x);
		double mycos(double x);
		double mytan(double x);
		double mycot(double x);
		double My_pow(double x,int n);//自定义x的n次方

};



double Trigonmetric_Func::mysin(double x)
{
	double sum=0;//泰勒展开式之和
	int n_n=0;//泰勒展开式每项前正负符号
	 while(x>=2*pi)
	{
		 x=x-2*pi;       //最多只有2π个弧度
	 }

	  while(x<=0)
	{
		 x=x+2*pi;       //最多只有2π个弧度
	 }
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

double Trigonmetric_Func::mycos(double x)
{
	double sum=0;//泰勒展开式之和
	int n_n=0;//泰勒展开式每项前正负符号
	while(x>=2*pi)
	{
		 x=x-2*pi;       //最多只有2π个弧度
	 }
	while(x<=0)
	{
		 x=x+2*pi;       //最多只有2π个弧度
	 }
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


double Trigonmetric_Func::mytan(double x)
{
	double sum=0;//泰勒展开式之和
		double m=0.00000;//泰勒展开式分母
	while(x>=(pi/2))
	{
		 x=x-pi;       //最多只有π个弧度
	 }
	while(x<=-(pi/2))
	{
		 x=x+pi;       //最多只有π个弧度
	 }
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


double Trigonmetric_Func::mycot(double x)
{
	double sum=0;//泰勒展开式之和
		double m=0.00000;//泰勒展开式分母
	while(x>=pi)
	{
		 x=x-pi;       //最多只有π个弧度
	 }
	while(x<=0)
	{
		 x=x+pi;       //最多只有π个弧度
	 }
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

		}
		if(n==2)
		{
			m=(double)-1/45;

		}
		if(n==3)
		{
			m=(double)-2/945;

		}
		if(n==4)
		{
			m=(double)-1/4725;

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
//	cout<<"请输入弧度值：";  //wyp
//	cin>>x;

}

int main()
{
//	int number;//三角函数选项序号
//	double x;//待计算三角函数弧度值
	double result1,  result2;//三角函数计算结果
    double sum=0.0;

	srand((unsigned int)time(0));//初始化种子为随机值

for(int i=0;i<1000;i++){
	double x= pi*(rand() / double(RAND_MAX));//随机产生1-100之间的数(弧度值)  wyp

//	Show_Input(number,x);//字符输入界面
	Trigonmetric_Func* ptr=new Trigonmetric_Func(x);

			//	result1=ptr->mysin(x);
			//	double a=result1-sin(x);

	        //  result1=ptr->mycos(x);
			//	double a=result1-cos(x);

//	            result1=ptr->mysin(x);
//	            result2=ptr->mycos(x);
//	            double a=result1/result2-tan(x);

            	result1=ptr->mysin(x);
		        result2=ptr->mycos(x);
		        double a=result2/result1-(cos(x)/sin(x));

				if(a<0)
					a=-a;
//				cout<<"mysin("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result1
//						<<"       "<<"sin("<<x<<")="<<sin(x)<<"       "<<"误差为mysin(x)-sin(x)="<<a<<endl;//保留小数点后四位输出函数计算结果
				if(a<0.001)
					sum+=1;
//
//            	result1=ptr->mycos(x);
//				cout<<"mycos("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result1
//						<<"       "<<"cos("<<x<<")="<<cos(x)<<"       "<<"误差为mycos(x)-cos(x)="<<result1-cos(x)<<endl;//保留小数点后四位输出函数计算结果
//
		//		result1=ptr->mytan(x);
//				cout<<"mytan("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result1
//						<<"       "<<"tan("<<x<<")="<<tan(x)<<"       "<<"误差为mytan(x)-tan(x)="<<result1/result2-tan(x)<<endl;//保留小数点后四位输出函数计算结果
//
//				result4=ptr->mycot(x);
				cout<<"mycot("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result2/result1
			     		<<"       "<<"cot("<<x<<")="<<cos(x)/sin(x)<<"       "<<"误差为mycot(x)-cot(x)="<<a<<endl;//保留小数点后四位输出函数计算结果
//
				cout<<"****************************************"<<endl;

		delete ptr;
}
    double p=(sum/1000)*100;
    cout<<"共测试了1000组数据，误差小于0.001的有"<<sum<<"组，符合率达到"<<p<<"%"<<endl;

	system("pause");
	return 0;
}


