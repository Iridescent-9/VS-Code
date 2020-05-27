#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include"time.h"
using namespace std;
class car :public Time
{
private:
	string car_num;//���ƺ� a
	string color;//��ɫ b
	string type;//�����ͺ� c
	string state = "in";
	int price;//ͣ����
	int type_num;//���ͣ������͵�
public:
	Time  itime;//����ʱ��
	Time  otime;//�뿪ʱ��
	car ( );
	void car_base ( );//�����������Ϣ,����ͣ��λʱʹ��
	void car_history ( );//������ʷ��¼
	void set_itime ( int iy , int imo , int id , int ih , int imin , int is );//���õ���ʱ��
	void set_otime ( int oy , int omo , int od , int oh , int omin , int os );//�����뿪ʱ��
	void itime_print ( );//�������ʱ��
	void otime_print ( );//����뿪ʱ��
	void set_car_num ( string a );//���ó��ƺ�
	void set_color ( string b );//���ó�����ɫ
	void set_type ( int n );//���ó��ĳ���
	void set_state ( );
	void set_price ( int x );
	int get_type_unm ( );//�õ����������͵�
	string get_num ( );//�õ����ƺ�
	string get_color ( );//�õ�����ɫ
	string get_type ( );//�õ����ͺ�
	string get_state ( );//�õ�����״̬���뿪������λ
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
		cout << "�ճ�λ" << endl << endl << endl;
		cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
	}
	else
	{
		cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
		cout << " " << "������Ϣ:" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "���ƺ�:" << car_num << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "������ɫ:" << color << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "����:" << type << endl;
		cout.fill ( ' ' ); cout.width ( 10 ); cout << " ";
		itime_print ( ); cout << endl;
		cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
	}
}
void car::car_history ( )
{
	cout.fill ( '-' ); cout.width ( 80 ); cout << "-" << endl;
	cout << " " << "������Ϣ:" << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "���ƺ�:" << car_num << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "������ɫ:" << color << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "����:" << type << endl;
	cout.fill ( ' ' ); cout.width ( 10 ); cout << " ";
	itime_print ( ); cout << "  "; otime_print ( ); cout << endl;
	cout.fill ( ' ' ); cout.width ( 10 ); cout << " ";
	cout << "ͣ�����ã�" << price << "Ԫ" << endl;
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
	cout << "����ͣ����";
}
void car::otime_print ( )
{
	otime.print_time ( );
	cout << "�뿪ͣ����";
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
			type = "С����";
			break;
		case 2:
			type = "С��";
			break;
		case 3:
			type = "�п�";
			break;
		case 4:
			type = "��";
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