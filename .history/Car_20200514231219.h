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
	string color;//��ɫ b
	string type;//�����ͺ� c
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
	void set_color ( string b );//���ó�����ɫ
	void set_type ( string c );//���ó��ĳ���
	void get_num();//�õ����ƺ�
	void get_color();//�õ�����ɫ
	void get_type();//�õ����ͺ�
};
car::car ( )
{
	car_num = ' ';
	color = ' ';
	type = ' ';
}
void car::car_base( )
{
	int i;
	cout.fill('-');
	cout.width(70);
	cout<<"-"<<endl;
	cout<<" "<<"������Ϣ:"<<endl;
	cout.fill(' ');
	cout.width(10);
	cout<<" ";cout<<"���ƺ�:" << car_num << "  " << "������ɫ:" << color << "  " << "����:" << type << "  " << endl;
	cout<<car_num.length();
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
	cout << "���ƺ�Ϊ:" << car_num;
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
