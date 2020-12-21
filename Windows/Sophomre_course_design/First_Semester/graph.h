//File's name:graph.h
//File's path:D:\VSCode\C++\graph.h
//==================================================//
//            Author:          Han,Shuoyu           //
//            Email:           syhan1228@vip.qq.com //
//            Creat Time:      2020-12-18  23:01:01 //
//==================================================//
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <string>
#include <vector>
#include <map>
using namespace std;
class graph
{
protected:
    int nv;
    vector<string> vectors;
    map<string, int> iov;

public:
    graph();
    virtual bool insertV(string);
    virtual bool insertE(string, string, int);
    virtual bool insertE(int first, int secend, int weight) = 0;
};

graph::graph()
{
    nv = 0;
}

bool graph::insertV(string v)
{
    if (iov.find(v) != iov.end())
    {
        return false;
    }
    vectors.push_back(v);
    iov[v] = nv;
    nv++;
    return true;
}

bool graph::insertE(string first, string secend, int weight)
{
    insertV(first);
    insertV(secend);
    return insertE(iov[first], iov[secend], weight);
}
#endif