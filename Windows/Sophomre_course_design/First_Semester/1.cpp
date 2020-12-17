#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
#include <windows.h>
using namespace std;
class graph
{
protected:
    int nv;
    vector<string> vectors;
    map<string, int> iov;

public:
    graph(int n = 0)
    {
        nv = n;
    }
    graph(vector<string> v)
    {
        nv = v.size();
        vectors = v;
        for (int i = 0; i < nv; i++)
        {
            iov[v[i]] = i;
        }
    }
    virtual bool insertV(string v)
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
    virtual bool insertE(string first, string secend, int weight)
    {
        insertV(first);
        insertV(secend);
        return insertE(iov[first], iov[secend], weight);
    }
    virtual bool insertE(int first, int secend, int weight) = 0;
};
class lgraph : public graph
{
protected:
    vector<map<int, int>> adjL;
    vector<int> topo;
    void setadjL()
    {
        adjL.resize(nv);
        for (auto x : adjL)
        {
            x.clear();
        }
    }

public:
    lgraph(int nv) : graph(nv) {}
    lgraph(vector<string> v) : graph(v)
    {
        setadjL();
    }
    void print()
    {
        cout << "图的邻接表:" << endl;
        for (int i = 0; i < nv; i++)
        {
            cout << vectors[i] << "-->";
            for (auto x : adjL[i])
            {
                cout << "  ";
                cout << vectors[x.first] << "(" << x.second << ")";
                cout << "  ";
            }
            cout << endl;
        }
    }
    bool insertV(string v)
    {
        if (!graph::insertV(v))
        {
            return false;
        }
        adjL.push_back(map<int, int>());
        return true;
    }
    bool insertE(string first, string secend, int weight)
    {
        return graph::insertE(first, secend, weight);
    }
    bool insertE(int first, int secend, int weight)
    {
        if (first < 0 || secend < 0 || first >= nv || secend >= nv)
        {
            return false;
        }
        if (adjL[first].find(secend) != adjL[first].end())
        {
            return false;
        }
        adjL[first].insert(pair<int, int>(secend, weight));
        return true;
    }
    bool topsort()
    {
        vector<int> inDegree(nv, 0);
        for (auto vl : adjL)
        {
            for (auto w : vl)
            {
                inDegree[w.first]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < nv; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0, v;
        while (!q.empty())
        {
            v = q.front();
            topo.push_back(v);
            q.pop();
            count++;
            for (auto x : adjL[v])
            {
                inDegree[x.first]--;
                if (inDegree[x.first] == 0)
                {
                    q.push(x.first);
                }
            }
        }
        if (count != nv)
        {
            return false;
        }
        return true;
    }
    bool CriticalPath()
    {
        if (!topsort())
        {
            cout << "错误，图中有环" << endl;
            return false;
        }
        int count1 = 0, aet, alt;
        vector<int> ve(nv, INT_MIN); //事件最早发生时间
        vector<int> anode;           //关键路径前一节点
        vector<int> bnode;           //关键路径后一节点
        ve[0] = 0;
        for (int i = 0; i < nv; i++) //求每个事件最早发生时间
        {
            for (auto x : adjL[i])
            {
                if (ve[x.first] < x.second + ve[topo[i]])
                {
                    ve[x.first] = x.second + ve[topo[i]];
                }
            }
        }
        vector<int> vl(nv, ve[nv - 1]); //事件最晚发生时间
        for (int i = nv - 1; i >= 0; i--)
        {
            for (auto x : adjL[i])
            {
                if (vl[topo[i]] > vl[x.first] - x.second)
                {
                    vl[topo[i]] = vl[x.first] - x.second;
                }
            }
        }
        cout << "关键活动为:";
        for (int i = 0; i < nv; i++)
        {
            for (auto x : adjL[i])
            {
                count1++;
                aet = ve[i];
                alt = vl[x.first] - x.second;
                if (aet == alt)
                {
                    cout << "a" << count1 << " ";
                    anode.push_back(i);
                    bnode.push_back(x.first);
                }
            }
        }
        cout << endl;
        cout << "关键路径为:" << endl;
        for (int i = 0; i < anode.size(); i++)
        {
            cout << vectors[anode[i]] << "-->" << vectors[bnode[i]] << endl;
        }
        auto max_time = max_element(vl.begin(), vl.end());
        cout << "花费的时间至少为:" << *max_time << endl;
        return true;
    }
};
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