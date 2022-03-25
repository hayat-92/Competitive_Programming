#include <iostream>
#include <queue>
using namespace std;

bool hasPath(int **matrix, int n, int sv, int b)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        if (b == front)
        {
            return true;
        }

        for (int i = 0; i < n; i++)
        {
            if (front == i)
            {
                continue;
            }
            if (matrix[front][i] == 1)
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    return false;
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

        int a, b;
        cin >> a >> b;

        bool value = hasPath(edges, V, a, b);
        if (value)
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