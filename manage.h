#pragma once
#include<iostream>
#include<string.h>
#include<Windows.h>
#include"Car.h"
#include"calculate.h"
using namespace std;
class manage :public car
{
	car cars [ 500 ] , k , * le;//��������acrs������ʱ�õ�k��������ʱ�õ� *le
	int count = 0;//�ܼ�¼��
	int ps , ps_s;//�ܳ�λ����ʣ�೵λ�� Parking space
	int capacity = 500;//����¼��
	int leave;//�뿪����ʱʹ��
	int car_s=0 , lorry_s=0 , lorry_m=0 , lorry_l=0;//С������С�����п�����
public:
	manage ( int ps0 );
	~manage ( ) { }
	int Add ( );//���
	int search ( );//����
	int change ( );//�޸�
	int car_leave ( );//���뿪����
	int car_delete ( );//ɾ��
	void sort ( );//���յ���ʱ�������
	void display ( );//��ʾ�ڳ�λ����ȫ����Ϣ
	void price_c (int n,int a );//������
	void statistics_model_plus (int n );//ͳ�Ƴ���,����
	void statistics_model_minus ( int n );//ͳ�Ƴ��ͣ�����
	void print_statistic ( );//���ͳ����Ϣ
};
manage::manage ( int ps0 )
{
	ps = ps0;
	ps_s = ps0;
	leave = 499;
}
int manage::Add ( )
{
	string a , b;//������Ϣ��a�������ƣ�b������ɫ
	int c;//����
	int l;
	int iy = 0 , imo = 0 , id = 0 , ih = 0 , im = 0 , is = 0;//���복��ʱ��
part1:
	{
		if ( ps_s == 0 )//�жϳ����Ƿ�����
		{
			cout << "��������" << endl;
			goto part2;
		}
		else
		{
			cout << "���⻹��" << ps_s << "��ͣ��λ" << endl;
			cout << "�Ƿ���복�⣺1.�� 2.��" << endl; cin >> l; cin.ignore ( );
			if ( l == 2 )
			{
				goto part2;
			}
		}
		cout << "����Ҫ���복��ĳ�����Ϣ" << endl;
		cout << "���ƺţ�";
		getline ( cin , a );
		for ( int i = 0; i < ps; i++ )
		{
			if ( a == cars [ i ].get_num ( ) )
			{
				cout << "�������Ѿ����" << endl;
				cout << "�Ƿ��޸�Ԥ��⳵����Ϣ��1.�� 2.��" << endl;
				int j = 0;
				cin >> j;
				cin.ignore ( );//����Իس������Ļ��������ݣ�������һ���������һ�������Ӱ��
				if ( j == 1 )
				{
					goto part1;
				}
				else goto part2;
			}
		}
		for ( int i = 0; i < ps_s; i++ )
		{
			int j = 0;
			for ( int k = 0; k < ps; k++ )
			{
				if ( cars [ k ].get_num ( ) == " " )
				{
					j = k;
					goto s;
				}
			}
		s:
			{
				cout << "�����복����ɫ��"; getline ( cin , b );
				cout << "�����복�ͣ����룩��1.С���� 2.С�� 3.�п� 4.��" << endl; cin >> c;
				cout << "��������복��ʱ��" << endl;
				cout << "�꣺"; cin >> iy;
				cout << "�£�"; cin >> imo;
				cout << "�գ�"; cin >> id;
				cout << "ʱ��"; cin >> ih;
				cout << "�֣�"; cin >> im;
				cout << "�룺"; cin >> is;
				statistics_model_plus ( c );
				le = &cars [ j ];
				le->set_car_num ( a );
				le->set_color ( b );
				le->set_type ( c );
				le->set_itime ( iy , imo , id , ih , im , is );
				if ( a == le->get_num ( ) && b == le->get_color ( ) )
				{
					count++;
					ps_s--;
					cout << "��" << count << "�������ɹ�    " << "���⻹��" << ps_s << "���ճ�λ" << endl;
				}
				sort ( );
				cout << "�Ƿ������ӣ�1.�� 2����" << endl;
				int j = 0;
				cin >> j;
				cin.ignore ( );
				if ( j == 2 )
				{
					system ( "CLS" );
					goto part2;
				}
				else goto part1;
			}
		}
	}
part2:
	return 0;
}
void manage::display ( )
{
	cout << "����Ϊ���⳵����Ϣ" << endl;
	for ( int i = 0; i < ps; i++ )
	{
		cars [ i ].car_base ( );
	}
	cout << endl;
}
int manage::search ( )
{
	int a , i;
	string b;//���ƺ�
	int c;//����
	cout << "�������ѯ������Ϣ��ʽ: 1.���ճ��ƺŲ�ѯ  2.���ճ��Ͳ�ѯ" << endl;
	cin >> a;
	cin.ignore ( );
	if ( count == 0 )
	{
		cout << "��ʷ��¼Ϊ��!" << endl;
	}
	switch ( a )
	{
		case 1:
			{
				cout << "��������Ҫ��ѯ�ĳ��ƺ�:" << endl;
				getline ( cin , b );
				for ( i = 0; i < capacity; i++ )
				{
					if ( b == cars [ i ].get_num ( ) )
					{
						if ( cars [ i ].get_state()=="in")
						{
							cars [ i ].car_base ( );
						}
						else
						{
							for ( int j = count; j < capacity; j++ )
							{
								if ( cars [ j ].get_state ( ) == "leave" )
								{
									cars [ j ].car_history ( );
								}
							}
						}
					}
					if ( i == capacity )
					{
						cout << "��ʷ��¼Ϊ�գ�" << endl;
						break;
					}
				}
			};	break;
		case 2:
			{
				cout << "�������ѯ�ĳ��ĳ�������(1.С���� 2.С�� 3.�п� 4.��):";
				cin >> c;
				for ( i = 0; i < capacity; i++ )
				{
					if ( c == cars[i].get_type_unm( ))
					{
						if ( cars [ i ].get_state( )=="in")
						{
							cars [ i ].car_base ( );
						}
						else
						{
							for ( int j = count; j < capacity; j++ )
							{
								if ( cars [ j ].get_state ( ) == "leave" )
								{
									cars [ j ].car_history ( );
								}
							}
						}
					}
					if ( i == capacity )
					{
						cout << "��ʷ��¼Ϊ��!" << endl;
						break;
					}
				}
			}; break;
	}
end0:
	return 0;
}
int manage::car_leave ( )
{
	int index = 0,lll=0;
	string b;
	display ( );
	cout << "�Ƿ��г���Ҫ�뿪 1.�� 2.��" << endl;
	cin >> lll; cin.ignore ( );
	if ( lll == 2 )
	{
		goto partend;
	}
	cout << "������Ԥ���뿪���ĳ��ƺ�:" << endl;
restart:
	{
		getline ( cin , b );
		for ( int i = 0; i < capacity; i++ )
		{
			if ( b == cars [ i ].get_num ( ) )
			{
				if ( cars [ i ].get_state()=="in" )
				{
					cout << "����Ϊ�ó���Ϣ" << endl;
					cars [ i ].car_base ( );
					index = i;
				}
				else
				{
					cout << "�ó����뿪���⣬����������" << endl;
					goto restart;
				}
				break;
			}
			if ( i == capacity - 1 )
			{
				cout << "��ʷ��¼Ϊ�գ�" << endl;
				goto partend;
			}
		}
	}
	price_c ( 1 , index );
partend:
	return 0;
}
void manage::price_c (int n,int a )
{
	switch ( n )
	{
		case 1:
			{
				int oy , omo , od , oh , om , os , inde = a, day_c , l = leave,p;
				cout << "������ó��뿪ʱ��" << endl;
				cout << "�꣺"; cin >> oy;
				cout << "�£�"; cin >> omo;
				cout << "�գ�"; cin >> od;
				cout << "ʱ��"; cin >> oh;
				cout << "�֣�"; cin >> om;
				cout << "�룺"; cin >> os;
				cin.ignore ( );
				cars [ leave ] = cars [ inde ];
				cars [ inde ] = cars [ leave - 1 ];
				le = &cars [ leave ];
				le->set_otime ( oy , omo , od , oh , om , os );
				le->set_state ( );
				day_c = d ( le );
				p = price_base ( day_c , le );
				le->set_price ( p );
				le->car_history ( );
				sort ( );
				leave--;
				ps_s++;
				break;
			}
		case 2:
			{
				int oy , omo , od , oh , om , os , inde = a,day_c,p;
				cout << "������ó��뿪ʱ��" << endl;
				cout << "�꣺"; cin >> oy;
				cout << "�£�"; cin >> omo;
				cout << "�գ�"; cin >> od;
				cout << "ʱ��"; cin >> oh;
				cout << "�֣�"; cin >> om;
				cout << "�룺"; cin >> os;
				cin.ignore ( );
				le = &cars [ a ];
				le->set_otime ( oy , omo , od , oh , om , os );
				day_c = d ( le );
				p = price_base ( day_c , le );
				le->set_price ( p );
				break;
			}
		case 3:
			{
				int iy , imo , id , ih , im , is , inde = a , day_c , p;
				cout << "������ó����ʱ��" << endl;
				cout << "�꣺"; cin >> iy;
				cout << "�£�"; cin >> imo;
				cout << "�գ�"; cin >> id;
				cout << "ʱ��"; cin >> ih;
				cout << "�֣�"; cin >> im;
				cout << "�룺"; cin >> is;
				cin.ignore ( );
				le = &cars [ a ];
				le->set_itime ( iy , imo , id , ih , im , is );
				day_c = d ( le );
				p = price_base ( day_c , le );
				le->set_price ( p );
				break;
			}
		default:
			break;
	}
}
void manage::sort ( )
{
	for ( int i = 0; i < ps + 1; i++ )
	{
		for ( int j = 0; j < ps + 1; j++ )
		{
			if ( cars [ j ].itime.get_time ( ) > cars [ j + 1 ].itime.get_time ( ) )
			{
				k = cars [ j ];
				cars [ j ] = cars [ j + 1 ];
				cars [ j + 1 ] = k;
			}
		}
	}
}
int manage::change ( )
{
	string a;//����һ�����泵�ƺŵı���
	int c;// ����ѡ���޸ķ�ʽ
	int b = 0;//�±�
	int i , t,kkk=0;
	string d;//�޸ĺ������
	cout << "�Ƿ�����޸�ϵͳ 1.�� 2.��" << endl;
	cin >> kkk; cin.ignore ( );
	if ( kkk == 2 )
	{
		goto finish;
	}
	cout << "��������Ҫ�޸ĳ��ĳ��ƺ�";
	getline ( cin , a );
	for ( i = 0; i < capacity; i++ )
	{
		if ( a == cars [ i ].get_num ( ) )
		{
			if ( cars [ i ].get_state ( ) == "in" )
			{
				cars [ i ].car_base ( );
			}
			else cars [ i ].car_history ( );
			b = i;
			break;
		}
		if ( i == capacity - 1 )
		{
			cout << "��¼Ϊ�գ�" << endl;
		}
	}
	cout << "1.�޸ĳ��ƺ�  2.�޸ĳ�����ɫ 3.�޸ĳ���  4.�޸Ľ���ʱ�� 5.�޸ĳ���ʱ�� 6.�˳��޸Ľ���" << endl;
	cout << "������ѡ��:" << endl;
	cin >> c;
	cin.ignore ( );
	switch ( c )
	{
		case 1:
			cout << "�����ƺ��޸�Ϊ��" << endl;
			getline ( cin , d );
			cars [ b ].set_car_num ( d );
			if ( cars [ b ].get_num ( ) == d )
			{
				cout << "�޸ĳɹ���" << endl;
			}
			break;
		case 2:
			cout << "��������ɫ�޸�Ϊ��"<<endl;
			getline ( cin , d );
			cars [ b ].set_color ( d );
			if ( cars [ b ].get_color ( ) == d )
			{
				cout << "�޸ĳɹ�" << endl;
			}
			break;
		case 3:
			cout << "�����͸ĳɣ����룩��1.С���� 2.С�� 3.�п� 4.��"<<endl;
			cin >> t;
			statistics_model_minus ( cars [ b ].get_type_unm ( ) );
			statistics_model_plus ( t );
			cars [ b ].set_type ( t );
			if ( t == cars [ b ].get_type_unm ( ) )
			{
				cout << "�޸ĳɹ�" << endl;
			}
			break;
		case 4:
			price_c ( 3 , b );
			cout << "�޸ĳɹ�,�������޸ĺ����Ϣ�� "<<endl;
			cars [ b ].car_history ( );
			sort ( );
			cout << endl;
			break;
		case 5:
			price_c ( 2 , b );
			cout << "�޸ĳɹ�,�������޸ĺ����Ϣ�� "<<endl;
			cars [ b ].car_history ( );
			break;
		case 6:
			cout << "���˳��޸�ϵͳ";
			break;
	}
finish:
	return 0;
}
int manage::car_delete( )
{
	string a;
	int i , j = 0,ddd;
	cout << "�Ƿ����ɾ��ϵͳ 1.�� 2.��" << endl;
	cin >> ddd; cin.ignore ( );
	if ( ddd == 2 )
	{
		goto endl_l;
	}
start:
	{
		cout << "��������Ҫɾ���ĳ�����Ϣ:  " << endl;
		cout << "���ƺ�: ";
		getline ( cin , a );
		if ( count == 0 ) cout << "��¼Ϊ��!" << endl;
		for ( i = 0; i < count; i++ )
		{
			if ( a == cars [ i ].get_num ( ) )
			{
				cars [ i ].set_car_num ( " " );
				statistics_model_minus ( cars [ i ].get_type_unm ( ) );
				count--;
				j = i;
			}
		}
		if ( cars [ j ].get_num ( ) == " " )
		{
			cout << "ɾ���ɹ�"<<endl;
			ps_s--;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ������¿�ʼ";
			goto start;
		}
		sort ( );
	}
endl_l:
	return 0;
}
void manage::statistics_model_plus ( int n )
{
	switch ( n )
	{
		case 1:
			car_s++;
			break;
		case 2:
			lorry_s++;
			break;
		case 3:
			lorry_m++;
			break;
		case 4:
			lorry_l++;
			break;
		default:
			break;
	}
}
void manage::statistics_model_minus(int n )
{
	switch ( n )
	{
		case 1:
			car_s--;
			break;
		case 2:
			lorry_s--;
			break;
		case 3:
			lorry_m--;
			break;
		case 4:
			lorry_l--;
			break;
		default:
			break;
	}
}
void manage::print_statistic ( )
{
	cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "ͣ��������"<<count<<"����¼" << endl;
	cout.fill ( ' ' ); cout.width ( 5 );
	cout << " " << "����" << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "С�����У�"<<car_s << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "С���У�"<<lorry_s << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "�п��У�"<<lorry_m << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "���У�"<<lorry_l << endl;
	cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-20 12:11:04        //
//==================================================//