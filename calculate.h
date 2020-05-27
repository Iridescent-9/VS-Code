#pragma once
#include<iostream>
#include<math.h>
#include"Car.h"
using namespace std;
int lapeyear ( int year2 )//�����жϺ���
{
	if ( ( year2 % 400 == 0 ) || ( year2 % 4 == 0 && year2 % 100 != 0 ) )
	{
		return 1;
	}
	else 
	{
		return 0; 
	}
}
int years1 ( int year1 , int year2 )//��������������
{
	int d = 0 , i , r = 0 , z = 0;
	if ( year1 < year2 )
	{
		for ( i = year1 + 1; i < year2; i++ )
		{
			if ( lapeyear ( i ) ) 
			{
				r++; 
			}//����֮���ж��ٸ�����
		}
		d = ( year2 - year1 - 1 ) * 365 + r;
	}
	else
	{
		for ( i = year2 + 1; i < year1; i++ )
		{
			if ( lapeyear ( i ) )
			{
				r++;
			}//����֮���ж��ٸ�����
		}
		d = ( year1 - year2 - 1 ) * 365 + r;
	}
	return d;
}
int months2 ( int year , int month , int date )//���㵽����ղ�ĺ���
{
	int i , d = 0;
	int years [ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ( lapeyear ( year ) ) 
	{
		years [ 1 ] = 29; 
	}
	for ( i = 0; i < month - 1; i++ )
	{
		d += years [ i ];
	}
	d += date;
	return d;
}
int months1 ( int year , int month , int date )//���㵽����ղ�ĺ���
{
	int i , d = 0;
	int years [ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ( lapeyear ( year ) )
	{
		years [ 1 ] = 29;
	}
	for ( i = 11; i > month - 1; i-- )
	{
		d += years [ i ];
	}
	d = d + years [ month - 1 ] - date;
	return d;
}
int d ( car *l )
{
	int year1 , year2 , month1 , month2 , date1 , date2;
	int d = 0 , i , m = 0;
	int x1 , x2;//��¼�������ڷֱ��������׵�����
	int years [ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	year1 = l->itime.get_year ( );
	year2 = l->otime.get_year ( );
	month1 = l->itime.get_month ( );
	month2 = l->otime.get_month ( );
	date1 = l->itime.get_day ( );
	date2 = l->otime.get_day ( );
	if ( year1 == year2 )//��ǰ�ᣬͬ��ʱ
	{
		if ( lapeyear ( year1 ) )
		{
			years [ 1 ] = 29;
		}
		if ( month1 == month2 )
		{
			d = date1 > date2 ? date1 - date2 : d = date2 - date1;
		}//ͬ��ͬ��
		if ( month1 != month2 )//ͬ�겻ͬ��
		{
			//���㷽��Ϊ�������֮ǰ��������Ȼ����ǰһ����ʣ��������ͺ�һ�����Ѿ���ʼ������
			if ( month1 < month2 )
			{
				{
					for ( i = month1; i < month2 - 1; i++ )
					{
						m += years [ i ];
					}
				}
				d = years [ month1 - 1 ] - date1;
				d += m + date2;
			}
			else
			{
				for ( i = month2; i < month1 - 1; i++ )
				{
					m += years [ i ];
				}
				d = years [ month2 - 1 ] - date2;
				d += m + date1;
			}
		}
	}
	else//��ͬ����������ڵ�������
	{
		if ( year1 > year2 )
		{
			x1 = months1 ( year2 , month2 , date2 );//x1Ϊ����׵��ղx2Ϊ��������ղ�
			x2 = months2 ( year1 , month1 , date1 );
			d = years1 ( year2 , year1 );
			d += x1 + x2;
		}
		else
		{
			x2 = months2 ( year2 , month2 , date2 );
			x1 = months1 ( year1 , month1 , date1 );
			d = years1 ( year1 , year2 );
			d += x1 + x2;
		}
	}
	return d;
}
int price_base ( int day,car *d )
{
	double all_s;
	int i;
	int h,h1 , m , m1 , s , s1;
	h = d->itime.get_hour ( );
	h1 = d->otime.get_hour ( );
	m = d->itime.get_minute ( );
	m1 = d->otime.get_minute ( );
	s = d->itime.get_second ( );
	s1 = d->otime.get_second ( );
	if ( day != 0 )
	{
		if ( h1 > h )
		{
			all_s = day * 86400 + ( h1 - h ) * 3600 + ( m1 - m ) * 60 + ( s1 - s );
			i = ceil ( all_s / 3600 );
		}
		else
		{
			day--;
			all_s = day * 86400 + 86400 - (( h - h1 ) * 3600 + ( m1 - m ) * 60 + ( s1 - s ));
			i = ceil ( all_s / 3600 );
		}
	}
	else
	{
		all_s = ( h1 - h ) * 3600 + ( m1 - m ) * 60 + ( s1 - s );
		if ( all_s <= 1800 )
		{
			return 0;
		}
		else
		{
			i = ceil ( all_s / 3600 );
		}
	}
	return i;
}
//==================================================//
//            Copyright@ Han 2020                   //
//            Author:    Han                        //
//            Email:     syhan1228@vip.qq.com       //
//            Time:      2020-05-19 22:19:26        //
//==================================================//
