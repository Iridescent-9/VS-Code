#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    int set(string test);
    int a;
    string b;
start:
{
    cin >> b;
    if (set(b) != 0)
    {
        a = set(b);
    }
    else
    {
        cout << "请重新输入";
        goto start;
    }
}
    cout<<a;
    getchar();
    return 0;
}
int set(string test)
{
    int x;
    if (test != "1"&& test!="2")
    {
        cout << "违法输入" << endl;
        return 0;
    }
    else
    {
        x = stoi(test, 0, 10);
        return x;
    }
}
