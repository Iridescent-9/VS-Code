#include<iostream>
#include<string.h>
#include<string>
#include<Windows.h>
#include"manage.h"
using namespace std;
int menu ( );
void start ( );
void copyright ( );
int main ( )
{
	start ( );
	copyright ( );
	menu ( );
	system ( "CLS" );
	system ( "color 05" );
	cout << endl<<endl<<endl<<"��лʹ�ã��ټ�";
	Sleep ( 2000 );
	return 0;
}
int menu ( )
{
	manage k1 ( 3 );
	while ( 1 )
	{
		cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "1.ͣ�����복��" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "2.�뿪����" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "3.��ѯ��Ϣ" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "4.�޸���Ϣ" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "5.��ʾ���ڳ��⳵����Ϣ" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "6.ɾ��������Ϣ" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "7.ͣ����ͳ����Ϣ" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "8.����" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "9.�˳�ϵͳ" << endl;
		cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
		cout << "���빦�����" << endl;
		int n;
		cin >> n; cin.ignore ( );
		switch ( n )
		{
			case 1:
				k1.Add ( );
				k1.display();
				break;
			case 2:
				k1.car_leave ( );
				break;
			case 3:
				k1.search ( );
				break;
			case 4:
				k1.change ( );
				k1.display( );
				break;
			case 5:
				k1.display ( );
				break;
			case 6:
				k1.car_delete ( );
				break;
			case 9:
				goto end0;
			case 7:
				k1.print_statistic ( );
				break;
			case 8:
				system ( "CLS" );
			default:
				break;
		}
	}
	end0:
	return 0;
}
void start ( )
{
	cout << endl << endl << endl<<endl<<endl<<endl;
	system ( " color 02" );
	int all_block_num = 100;
	for ( int i = 0; i < all_block_num; i++ )
	{
		if ( i < all_block_num - 1 )
		{
			printf ( "\r��ȡ��[%.3lf%%]:" , i * 100.0 / ( all_block_num - 1 ) );
		}
		else
		{
			printf ( "\r��ȡ���[%.3lf%%]:" , i * 100.0 / ( all_block_num - 1 ) );
		}
		int show_num = i * 10 / all_block_num;
		for ( int j = 1; j <= show_num; j++ )
		{
			cout << "��";
			Sleep ( 10 );
		}
	}
	system ( "CLS" );
	system ( "color 07" );
}
void copyright ( )
{
	cout << endl << endl << endl;
	cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
	cout << endl << endl << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "��ӭʹ��ͣ��������ϵͳ" << endl << endl << endl;
	cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
	Sleep ( 3000 );
	system ( "CLS" );
	cout << endl << endl << endl;
	system ( "color 05" );
	cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
	cout << endl << endl << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "Copyright@ HSY PFS 2020" << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "Author HSY PFS" << endl;
	cout.fill ( ' ' ); cout.width ( 10 );
	cout << " " << "Time 2020-5" << endl << endl << endl;
	cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
	Sleep ( 3000 );
	system ( "CLS" );
	system ( "color 07" );
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-20 12:11:20        //
//==================================================//