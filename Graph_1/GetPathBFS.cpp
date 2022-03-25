#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> *getpath(int **matrix, int n, int sv, int b, bool *visited)
{
    queue<int> *q = new queue<int>();
    q->push(sv);
    visited[sv] = true;
    map<int, int> *m = new map<int, int>();
    while (!q->empty())
    {
        int front = q->front();
        q->pop();
        if (sv == b)
        {
            break;
        }

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
                    q->push(i);
                    m->insert({i, front});
                    visited[i] = true;
                }
            }
        }
    }

    vector<int> *v = new vector<int>();
    if (m->find(b) == m->end())
    {
        return NULL;
    }
    v->push_back(b);
    int x = m->at(b);
    while (x != sv)
    {
        v->push_back(x);
        x = m->at(x);
    }

    v->push_back(x);
    return v;
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