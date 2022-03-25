#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int v1;
    int v2;
};

void floydWarshall(int **edges, int V, Edge **queries, int q)
{
    int **dist = new int *[V + 1];
    for (int i = 1; i <= V; i++)
    {
        dist[i] = new int[V + 1];
        for (int j = 1; j <= V; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = edges[i][j];
        }
    }

    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[j][k] != INT_MAX && dist[i][j] > (dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int v1 = queries[i]->v1;
        int v2 = queries[i]->v2;
        cout << dist[v1][v2] << endl;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        int **edges = new int *[V + 1];
        // for (int i = 1; i < V+1; i++)
        // {
        for (int i = 1; i <= V; i++)
        {
            edges[i] = new int[V + 1];
            for (int j = 1; j < V + 1; j++)
            {
                edges[i][j] = INT_MAX;
            }
        }
        // }

        for (int i = 0; i < E; i++)
        {
            int x, y, weight;
            cin >> x >> y >> weight;
            edges[x][y] = min(weight, edges[x][y]);
            edges[y][x] = min(weight, edges[y][x]);
        }

        int q;
        cin >> q;

        Edge **queries = new Edge *[q];
        for (int i = 0; i < q; i++)
        {
            queries[i] = new Edge();
            cin >> queries[i]->v1 >> queries[i]->v2;
        }

        floydWarshall(edges, V, queries, q);
    }

    return 0;
}