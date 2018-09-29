#include <bits/stdc++.h>
using namespace std;
 
vector<int> v;
vector<int> d;
vector<int> p;

void addEdge(vector <int> g[], int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void BFSSingleSource(vector <int> g[], int s)
{
    queue<int> q;

    q.push(s); 

    d[s] = 0;
    v[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        cout << u << " ";
 
        for (auto i = g[u].begin(); i != g[u].end(); i++)
        {
            if (v[*i] == 0)
            {
                v[*i] = 1;
                d[*i] = d[u] + 1;
                p[*i] = u;
                q.push(*i); 
            }
        }
    }
}
 
void BFSFull(vector <int> g[], int n)
{
    v.assign(n, 0);
    d.assign(n, 0);
    p.assign(n, -1);
 
    for (int i = 0; i < n; i++)     
        if (v[i] == 0)
            BFSSingleSource(g, i); 
}

int main()
{
    int n = 7;
    vector <int> g[n];
     
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 2, 6);
 
    BFSFull(g, n);
 
    return 0;
}
