#pragma once
#include<iostream>
using namespace std;
class Time
{
private:
	int hour , minute , second;
public:
	void set_time ( int h = 0 , int m = 0 , int s = 0 )
	{
		hour = h;
		minute = m;
		second = s;
	}
	int get_hour ( )
	{
		return hour;
	}
	int get_minute ( )
	{
		return minute;
	}
	int get_second ( )
	{
		return second;
	}
	Time ( int x = 0 , int y = 0 , int z = 0 )
	{
		hour = x;
		minute = y;
		second = z;
	}
	void print_time ( void );
};
void Time::print_time ( void )
{
	cout << hour << ':' << minute << ':' << second;
	if ( hour <= 12 && hour >= 0 )
	{
		cout << " AM";
	}
	else
	{
		cout << " PM";
	}
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-14 01:20:19        //                                                              
//==================================================//

