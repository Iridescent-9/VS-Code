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
	//start ( );
	//copyright ( );
	menu ( );
	system ( "CLS" );
	system ( "color 05" );
	cout << endl << endl << endl << "感谢使用，再见";
	Sleep ( 2000 );
	return 0;
}
int menu ( )
{
	manage k1;
	while ( 1 )
	{
		cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "1.停车进入车库" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "2.离开车库" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "3.查询信息" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "4.修改信息" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "5.显示已在车库车辆信息" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "6.删除车辆信息" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "7.停车场统计信息" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "8.清屏" << endl;
		cout.fill ( ' ' ); cout.width ( 10 );
		cout << " " << "9.退出系统" << endl;
		cout << "停车每小时3元，停车半小时内不收费" << endl;
		cout.fill ( '-' ); cout.width ( 50 ); cout << "-" << endl;
		cout << "输入功能序号" << endl;
		int n = 0;
		string c;
		n = choice_19 ( c );
		cin.ignore ( );
		switch ( n )
		{
			case 1:
				k1.Add ( );
				k1.display ( );
				break;
			case 2:
				k1.car_leave ( );
				break;
			case 3:
				k1.search ( );
				break;
			case 4:
				k1.change ( );
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
	cout << endl << endl << endl << endl << endl << endl;
	system ( " color 02" );
	int all_block_num = 100;
	for ( int i = 0; i < all_block_num; i++ )
	{
		if ( i < all_block_num - 1 )
		{
			printf ( "\r读取中[%.3lf%%]:" , i * 100.0 / ( all_block_num - 1 ) );
		}
		else
		{
			printf ( "\r读取完成[%.3lf%%]:" , i * 100.0 / ( all_block_num - 1 ) );
		}
		int show_num = i * 10 / all_block_num;
		for ( int j = 1; j <= show_num; j++ )
		{
			cout << "█";
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
	cout << " " << "欢迎使用停车场管理系统" << endl << endl << endl;
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
//            Time:      2020-06-02 19:03:26        //
//==================================================//