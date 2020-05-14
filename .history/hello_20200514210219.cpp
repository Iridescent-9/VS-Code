#include<iostream>
#include<string.h>
#include<string>
#include"Car.h"
using namespace std;
int main ( )
{
	/*string car_num,color,type;
	cout<<"输入车牌号：";getline(cin,car_num);
	cout<<"输入车颜色：";getline(cin,color);
	cout<<"输入车型：";getline(cin,type);
	c1.set_car_num ( car_num );
	c1.set_color ( color );
	c1.set_type ( type );
	*/
	car c1;
	c1.set_car_num ( "陕AW6E67" );
	c1.set_color ( "紫色" );
	c1.set_type ( "SUV" );
	c1.set_itime ( 16 , 24 , 36 );
	c1.set_otime ( 22 , 26 , 15 );
	c1.car_base ( );
	c1.car_print ( );
	c1.get_number( );
	getchar();
	return 0;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-14 17:14:12        //                                                              
//==================================================//
