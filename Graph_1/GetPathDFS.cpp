#include <iostream>
#include <vector>
using namespace std;

vector<int> *getpath(int **edges, int n, int sv, int b, bool *visited)
{
    // cout<<sv<<"fai"<<b<<endl;
    if (sv == b)
    {
        vector<int> *e = new vector<int>();
        visited[sv] = true;
        // if(edges[])
        e->push_back(sv);
        return e;
    }
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
            // visited[i] = true;
            vector<int> *e = getpath(edges, n, i, b, visited);

            if (e != NULL)
            {
                e->push_back(sv);

                return e;
            }
            else
            {
                continue;
            }
        }
    }

    return NULL;
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

        // print(edges, V, 0, visited);
        int a, b;
        cin >> a >> b;

        vector<int> *ans = getpath(edges, V, a, b, visited);
        if (ans != NULL)
        {
            for (int i = 0; i < ans->size(); i++)
            {
                cout << ans->at(i) << " ";
            }
            cout << endl;
        }

        delete[] visited;

        for (int i = 0; i < V; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
    }

    return 0;
}