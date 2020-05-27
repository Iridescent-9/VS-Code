#pragma once
#include<iostream>
using namespace std;
class Time
{
private:
	int year , month , day , hour , minute , second;
public:
	Time ( );
	void set_time ( int y , int mo , int d , int h , int min , int s );
	int get_year ( );
	int get_month ( );
	int get_day ( );
	int get_hour ( );
	int get_minute ( );
	int get_second ( );
	void print_time ( );
	long long int get_time();
};
Time::Time ( )
{
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
	second = 0;
}
void Time::set_time ( int y , int mo , int d , int h , int min , int s )
{
	year = y;
	month = mo;
	day = d;
	hour = h;
	minute = min;
	second = s;
}
int Time::get_year ( )
{
	return year;
}
int Time::get_month ( )
{
	return month;
}
int Time::get_day ( )
{
	return day;
}
int Time::get_hour ( )
{
	return hour;
}
int Time::get_minute ( )
{
	return minute;
}
int Time::get_second ( )
{
	return second;
}
void Time::print_time ( void )
{
	cout << year << "Äê" << month << "ÔÂ" << day << "ÈÕ  " << hour << ':' << minute << ':' << second;
}
long long int Time::get_time( )
{
	long long int a;
	a = year * pow(10, 10) + month * pow(10, 8) + day * pow(10, 6) + hour * pow(10, 4) + minute * pow(10, 2) + second;
	return a;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-19 22:19:47        //
//==================================================//