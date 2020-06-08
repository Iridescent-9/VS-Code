//克隆至本地后请先修改manage.h中void manage::info ( car* info )函数打开文件的路径
#include<iostream>
#include<string.h>
#include<string>
#include<Windows.h>
#include"manage.h"
using namespace std;
int main ( )
{
	start ( );
	copyright ( );
	menu ( );
	system ( "CLS" );
	system ( "color 05" );
	cout << endl << endl << endl << "感谢使用，再见";
	Sleep ( 2000 );
	return 0;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-06-02 19:03:26        //
//==================================================//