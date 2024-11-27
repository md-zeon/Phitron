#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e5 + 5;
// vector<int> adjList[N];
vector<pair<int, int>> adjList[N]; // first -> node, second -> weight

int main()
{   
    init_code();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // adjList[u].push_back(v);
        // adjList[v].push_back(u);
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    for(int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for(auto j : adjList[i])
        {
            cout << "(" << j.first << ", " << j.second << ") ";
        }
        cout << endl;
    }

    return 0;
}