#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include"time.h"
using namespace std;
class car:public Time
{
protected:
	string car_num;//���ƺ� a
	char *color;//��ɫ b
	char *type;//�����ͺ� c
	Time  itime;//����ʱ��
	Time  otime;//�뿪ʱ��
public:
	car ( );
	void car_base ( );//��������Ļ�����Ϣ
	void set_itime ( int ih , int im , int is );//���õ���ʱ��
	void set_otime ( int lh , int lm , int ls );//�����뿪ʱ��
	void itime_print ( );//�������ʱ��
	void otime_print ( );//����뿪ʱ��
	void car_print ( );//��ѯʱʹ��
	void set_car_num ( string a );//���ó��ƺ�
	void set_color ( const char* b );//���ó�����ɫ
	void set_type ( const char* c );//���ó��ĳ���
	void get_number();//�õ����ƺ�
};
void car::car_base( )
{
	cout << "������Ϣ: ���ƺ�:" << car_num << "  " << "������ɫ:" << color << "  " << "����:" << type << "  " << endl;
}
void car::car_print ( )
{
	cout << "���ƺ�:" << car_num << "  " << "������ɫ:" << color << "  " << "����:" << type<<"  ";
	itime_print ( ); 
	cout << "  ";
	otime_print ( );
	cout << endl;
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
	cout << "�ó�";
	itime.print_time ( );
	cout << "����ͣ����";
}
void car::otime_print ( )
{
	cout << "�ó�";
	otime.print_time ( );
	cout << "�뿪ͣ����";
}
car::car ( )
{
	car_num = ' ';
	color = NULL;
	type = NULL;
}
void car::set_car_num( string a )
{
	car_num=a;
}
void car::set_color ( const char* b )
{
	int w;
	color = new char [ strlen ( b ) + 1 ];
	w = strlen ( b ) + 1;
	strcpy( color, b );
}
void car::set_type ( const char* c )
{
	int e;
	type = new char [ strlen ( c ) + 1 ];
	e = strlen ( c ) + 1;
	strcpy ( type, c );
}
void car::get_number()
{
	cout << "���ƺ�Ϊ:" << car_num;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-14 01:21:05        //                                                              
//==================================================//
