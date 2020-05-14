#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include"time.h"
using namespace std;
class car:public Time
{
protected:
	string car_num;//车牌号 a
	string color;//颜色 b
	string type;//车的型号 c
	Time  itime;//到达时间
	Time  otime;//离开时间
public:
	car ( );
	void car_base ( );//输出车辆的基本信息
	void set_itime ( int ih , int im , int is );//设置到达时间
	void set_otime ( int lh , int lm , int ls );//设置离开时间
	void itime_print ( );//输出到达时间
	void otime_print ( );//输出离开时间
	void car_print ( );//查询时使用
	void set_car_num ( string a );//设置车牌号
	void set_color ( string b );//设置车的颜色
	void set_type ( string c );//设置车的车型
	void get_num();//得到车牌号
	void get_color();//得到车颜色
	void get_type();//得到车型号
};
car::car ( )
{
	car_num = ' ';
	color = ' ';
	type = ' ';
}
void car::car_base( )
{
	cout.fill('-');cout.width(70);cout<<"-"<<endl;
	cout<<" "<<"车辆信息:"<<endl;
	cout.fill(' ');cout.width(10);
	cout<<" "<<"车牌号:" << car_num <<endl;
	cout.fill(' ');cout.width(10);
	cout<<" "<< "车的颜色:" <<color<<endl; 
	cout.fill(' ');cout.width(10);
	cout<< " " << "车型:" << type<<endl;
	cout.fill('-');cout.width(70);cout<<"-"<<endl;
}
void car::car_print ( )
{
	cout.fill('-');cout.width(70);cout<<"-"<<endl;
	cout<<" "<<"车辆信息:"<<endl;
	cout.fill(' ');cout.width(10);
	cout<<" "<<"车牌号:" << car_num <<endl;
	cout.fill(' ');cout.width(10);
	cout<<" "<< "车的颜色:" <<color<<endl; 
	cout.fill(' ');cout.width(10);
	cout<< " " << "车型:" << type<<endl;
	cout.fill(' ');cout.width(10);cout<<" ";
	itime_print ( ); 
	cout << "  ";
	otime_print ( );
	cout<<endl;
	cout.fill('-');cout.width(70);cout<<"-"<<endl;
}
void car::set_itime ( int ih , int im , int is )
{
	itime.set_time ( ih , im , is );
}
void car::set_otime ( int lh , int lm , int ls )
{
	otime.set_time ( lh , lm , ls );
}
void car::itime_print ( )
{
	cout << "该车";
	itime.print_time ( );
	cout << "进入停车场";
}
void car::otime_print ( )
{
	cout << "该车";
	otime.print_time ( );
	cout << "离开停车场";
}
void car::set_car_num( string a )
{
	car_num=a;
}
void car::set_color ( string b )
{
	color=b;
}
void car::set_type ( string c )
{
	type=c;
}
void car::get_num()
{
	cout << "车牌号为:" << car_num;
}
void car::get_color()
{
	cout<<color;
}
void car::get_type()
{
	cout<<type;
}


//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-14 01:21:05        //                                                              
//==================================================//
