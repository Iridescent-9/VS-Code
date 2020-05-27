#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include"time.h"
using namespace std;
class car :public Time
{
private:
	string car_num;//车牌号 a
	string color;//颜色 b
	string type;//车的型号 c
	string state = "in";
	int price;//停车费
	int type_num;//车型，数字型的
public:
	Time  itime;//到达时间
	Time  otime;//离开时间
	car ( );
	void car_base ( );//输出车辆的信息,车在停车位时使用
	void car_history ( );//车辆历史记录
	void set_itime ( int iy , int imo , int id , int ih , int imin , int is );//设置到达时间
	void set_otime ( int oy , int omo , int od , int oh , int omin , int os );//设置离开时间
	void itime_print ( );//输出到达时间
	void otime_print ( );//输出离开时间
	void set_car_num ( string a );//设置车牌号
	void set_color ( string b );//设置车的颜色
	void set_type ( int n );//设置车的车型
	void set_state ( );
	void set_price ( int x );
	int get_type_unm ( );//得到车型数字型的
	string get_num ( );//得到车牌号
	string get_color ( );//得到车颜色
	string get_type ( );//得到车型号
	string get_state ( );//得到车的状态，离开或是在位
};
car::car ( )
{
	car_num = ' ';
	color = ' ';
	type = ' ';
	itime.set_time ( 99999 , 12 , 31 , 23 , 59 , 59 );
}
void car::car_base ( )
{
	if ( get_num ( ) == " " )
	{
		cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl << endl << endl;
		cout.fill ( ' ' ); cout.width ( 35 ); cout << " ";
		cout << "空车位" << endl << endl << endl;
		cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
	}
	else
	{
		cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
		cout << " " << "车辆信息:" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "车牌号:" << car_num << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "车的颜色:" << color << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "车型:" << type << endl;
		cout.fill ( ' ' ); cout.width ( 10 ); cout << " ";
		itime_print ( ); cout << endl;
		cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
	}
}
void car::car_history ( )
{
	cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
	cout << " " << "车辆信息:" << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "车牌号:" << car_num << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "车的颜色:" << color << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "车型:" << type << endl;
	cout.fill ( ' ' ); cout.width ( 10 ); cout << " ";
	itime_print ( ); cout << "  "; otime_print ( ); cout << endl;
	cout.fill ( ' ' ); cout.width ( 10 ); cout << " ";
	cout << "停车费用：" << price << "元" << endl;
	cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
}
void car::set_itime ( int iy , int imo , int id , int ih , int imin , int is )
{
	itime.set_time ( iy , imo , id , ih , imin , is );
}
void car::set_otime ( int oy , int omo , int od , int oh , int omin , int os )
{
	otime.set_time ( oy , omo , od , oh , omin , os );
}
void car::itime_print ( )
{
	itime.print_time ( );
	cout << "进入停车场";
}
void car::otime_print ( )
{
	otime.print_time ( );
	cout << "离开停车场";
}
void car::set_car_num ( string a )
{
	car_num = a;
}
void car::set_color ( string b )
{
	color = b;
}
void car::set_type ( int n )
{
	switch ( n )
	{
		case 1:
			type = "小汽车";
			break;
		case 2:
			type = "小卡";
			break;
		case 3:
			type = "中卡";
			break;
		case 4:
			type = "大卡";
			break;
		default:
			break;
	}
	type_num = n;
}
string car::get_num ( )
{
	return car_num;
}
string car::get_color ( )
{
	return color;
}
string car::get_type ( )
{
	return type;
}
void car::set_state ( )
{
	state = "leave";
}
string car::get_state ( )
{
	return state;
}
void car::set_price ( int x )
{
	price = x * 5;
}
int car::get_type_unm ( )
{
	return type_num;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-20 12:11:11        //
//==================================================//