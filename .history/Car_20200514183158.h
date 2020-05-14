#pragma once
#include<iostream>
#include<string.h>
#include"time.h"
using namespace std;
class car:public Time
{
protected:
	char *car_num;//车牌号 a
	char *color;//颜色 b
	char *type;//车的型号 c
	Time  itime;//到达时间
	Time outtime;//离开时间
public:
	car ( );
	void car_base ( );//输出车辆的基本信息
	void set_itime ( int ih , int im , int is );//设置到达时间
	void set_outtime ( int lh , int lm , int ls );//设置离开时间
	void itime_print ( );//输出到达时间
	void outtime_print ( );//输出离开时间
	void car_print ( );//查询时使用
	void set_car_num ( const char* a );//设置车牌号
	void set_color ( const char* b );//设置车的颜色
	void set_type ( const char* c );//设置车的车型
	void get_number();//得到车牌号
};
void car::car_base( )
{
	cout << "车辆信息: 车牌号:" << car_num << "  " << "车的颜色:" << color << "  " << "车型:" << type << "  " << endl;
}
void car::car_print ( )
{
	cout << "车牌号:" << car_num << "  " << "车的颜色:" << color << "  " << "车型:" << type<<"  ";
	itime_print ( ); 
	cout << "  ";
	outtime_print ( );
	cout << endl;
}
void car::set_itime ( int ih , int im , int is )
{
	itime.set_time ( ih , im , is );
}
void car::set_outtime ( int lh , int lm , int ls )
{
	outtime.set_time ( lh , lm , ls );
}
void car::itime_print ( )
{
	cout << "该车";
	itime.print_time ( );
	cout << "进入停车场";
}
void car::outtime_print ( )
{
	cout << "该车";
	outtime.print_time ( );
	cout << "离开停车场";
}
car::car ( )
{
	car_num = NULL;
	color = NULL;
	type = NULL;
}
void car::set_car_num( const char* a )
{
	int q;
	car_num = new char [ strlen ( a ) + 1 ];
	q = strlen ( a ) + 1;
	strcpy_s ( car_num , q , a );
}
void car::set_color ( const char* b )
{
	int w;
	color = new char [ strlen ( b ) + 1 ];
	w = strlen ( b ) + 1;
	strcpy_s ( color , w , b );
}
void car::set_type ( const char* c )
{
	int e;
	type = new char [ strlen ( c ) + 1 ];
	e = strlen ( c ) + 1;
	strcpy_s ( type , e , c );
}
void car::get_number()
{
	cout << "车牌号为:" << car_num;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-14 01:21:05        //                                                              
//==================================================//
