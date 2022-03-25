#include <iostream>
using namespace std;
void isConnected(int **edges, int n, int sv, bool *visited)
{
    // cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            isConnected(edges, n, i, visited);
        }
    }
    bool flag = true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        int **edges = new int *[V];
        for (int i = 0; i < V; i++)
        {
            edges[i] = new int[V];
            for (int j = 0; j < V; j++)
            {
                edges[i][j] = 0;
            }
        }

        for (int i = 0; i < E; i++)
        {
            int f, s;
            cin >> f >> s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        isConnected(edges, V, 0, visited);
        int flag = true;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}