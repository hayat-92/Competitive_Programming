#include <iostream>
#include<algorithm>
using namespace std;

int getMinVertex(bool *visited, int *weight, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((minVertex == -1) || (weight[minVertex] > weight[i])))
        {
            minVertex = i;
        }
    }

    return minVertex;
}
void prims(int **edges, int n)
{
    bool *visited = new bool[n]();
    for(int i=0; i<n; i++){
    } 
    int *parent = new int[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
    }

    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        int minVertex = getMinVertex(visited, weight, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != INT_MAX && !visited[j])
            {
                if (weight[j] > edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    int weightx=0;

    for (int i = 1; i < n; i++)
    {
        // if (parent[i] > i)
        // {
        //     cout << parent[i] << " " << i << " " << weight[i] << endl;
        // }
        // else
        // {
        //     cout << i << " " << parent[i] << " " << weight[i] << endl;
        // }
        weightx+=weight[i];
    }

    cout<<weightx<<endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        int e;
        cin >> n >> e;
        int **edges = new int *[n];
        for (int i = 0; i < n; i++)
        {
            edges[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                edges[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < e; i++)
        {
            int f, s, weight;
            cin >> f >> s >> weight;
            edges[f][s] = min(edges[f][s], weight);
            edges[s][f] = min(edges[s][f], weight);
        }

        prims(edges, n);
        for (int i = 0; i < n; i++)
        {
            delete[] edges[i];
        }

        delete[] edges;
    }
    return 0;
}