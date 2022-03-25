#include <iostream>
#include <queue>
using namespace std;

void print(int **matrix, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";

        // visited[front] = true;
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
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print(edges, n, i, visited);
        }
    }

    delete[] visited;
}
int main()
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

    BFS(edges, V);

    return 0;
}