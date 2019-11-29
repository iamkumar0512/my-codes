#include <bits/stdc++.h>
using namespace std;
 
vector<int> v;
vector<int> p;

void addEdge(vector <int> g[], int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void DFS(vector <int> g[], int s)
{
    v[s] = 1;
    
    cout<<s<<" ";
 
    for (auto i = g[s].begin(); i != g[s].end(); i++)
    {
        if (v[*i] == 0)
        {
            v[*i] = 1;
            p[*i] = s;
            DFS(g,*i);
        }
    }
}
 
void DFS_Visit(vector <int> g[], int n)
{
    v.assign(n, 0);
    p.assign(n, -1);
 
    for (int i = 0; i < n; i++)     
        if (v[i] == 0)
           DFS(g, i); 
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
 
    DFS_Visit(g, n);
 
    return 0;
}
