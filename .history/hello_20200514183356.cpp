#include<iostream>
#include<string.h>
#include<string>
#include"Car.h"
using namespace std;
int main ( )
{
	car c1;
	c1.set_car_num ( "ÉÂAW6E67" );
	c1.set_color ( "×Ï" );
	c1.set_type ( "SUV" );
	c1.set_itime ( 16 , 24 , 36 );
	c1.set_outtime ( 22 , 26 , 15 );
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
