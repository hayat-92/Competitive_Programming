#include <iostream>
using namespace std;

void fxn(int **edges, int n, bool *visited, int sv)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                fxn(edges, n, visited, i);
            }
        }
    }
}

int island(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {
            count++;
            fxn(edges, n, visited, i);
        }
    }

    return count;
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

        int count = island(edges, V);
        cout << count << endl;
    }
    return 0;
}