#pragma once
#include<iostream>
#include<string.h>
#include"time.h"
using namespace std;
class car:public Time
{
protected:
	char *car_num;//���ƺ� a
	char *color;//��ɫ b
	char *type;//�����ͺ� c
	Time  intime;//����ʱ��
	Time outtime;//�뿪ʱ��
public:
	car ( );
	void car_base ( );//��������Ļ�����Ϣ
	void set_intime ( int ih , int im , int is );//���õ���ʱ��
	void set_outtime ( int lh , int lm , int ls );//�����뿪ʱ��
	void intime_print ( );//�������ʱ��
	void outtime_print ( );//����뿪ʱ��
	void car_print ( );//��ѯʱʹ��
	void set_car_num ( const char* a );//���ó��ƺ�
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
	intime_print ( ); 
	cout << "  ";
	outtime_print ( );
	cout << endl;
}
void car::set_intime ( int ih , int im , int is )
{
	intime.set_time ( ih , im , is );
}
void car::set_outtime ( int lh , int lm , int ls )
{
	outtime.set_time ( lh , lm , ls );
}
void car::intime_print ( )
{
	cout << "�ó�";
	intime.print_time ( );
	cout << "����ͣ����";
}
void car::outtime_print ( )
{
	cout << "�ó�";
	outtime.print_time ( );
	cout << "�뿪ͣ����";
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
	cout << "���ƺ�Ϊ:" << car_num;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-14 01:21:05        //                                                              
//==================================================//
