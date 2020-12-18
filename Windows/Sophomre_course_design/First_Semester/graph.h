//File's name:graph.h
//File's path:D:\VSCode\work\Windows\Sophomre_course_design\First_Semester\graph.h
//==================================================//
//            Author:          Han,Shuoyu           //
//            Email:           syhan1228@vip.qq.com //
//            Creat Time:      2020-12-18  21:47:49 //
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
    graph(vector<string>);
    virtual bool insertV(string);
    virtual bool insertE(string, string, int);
    virtual bool insertE(int first, int secend, int weight) = 0;
};

graph::graph(vector<string> v)
{
    nv = v.size();
    vectors = v;
    for (int i = 0; i < nv; i++)
    {
        iov[v[i]] = i;
    }
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