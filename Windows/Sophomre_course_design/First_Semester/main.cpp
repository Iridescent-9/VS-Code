//File's name:main.cpp
//File's path:D:\VSCode\work\Windows\Sophomre_course_design\First_Semester\main.cpp
//==================================================//
//            Copyright© 2020 Han,Shuoyu            //
//            Author:    Han,Shuoyu                 //
//            Email:     syhan1228@vip.qq.com       //
//            Creat Time:      2020-12-18  22:56:38 //
//==================================================//
#include <iostream>
#include <fstream>
#include <windows.h>
#include "graph.h"
#include "lgraph.h"
using namespace std;

int main()
{
    system("chcp 65001");
    system("cls");
    ifstream fin("D:\\VSCode\\work\\Windows\\Sophomre_course_design\\First_Semester\\graph.txt");
    if (!fin)
    {
        cout << "文件打开失败" << endl;
        ofstream fout("D:\\VSCode\\work\\Windows\\Sophomre_course_design\\First_Semester\\graph.txt");
        fout.close();
        return 0;
    }
    int M, edge, weight;
    string n1, n2;
    fin >> M;
    fin >> edge;
    vector<string> v(M);
    for (int i = i; i < M; i++)
    {
        fin >> v[i];
    }
    lgraph g(v);
    for (int i = 0; i < edge; i++)
    {
        fin >> n1;
        fin >> n2;
        fin >> weight;
        g.insertE(n1, n2, weight);
    }
    g.print();
    g.CriticalPath();
    getchar();
    return 0;
}