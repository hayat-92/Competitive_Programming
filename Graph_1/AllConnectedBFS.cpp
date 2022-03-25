#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<int> *getpath(int **matrix, int n, int sv, bool *visited)
{
    queue<int> *q = new queue<int>();
    q->push(sv);
    visited[sv] = true;
    vector<int> *temp = new vector<int>();
    int front;
    while (!q->empty())
    {
        front = q->front();
        temp->push_back(front);
        q->pop();
        for (int i = 1; i < n; i++)
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
                    visited[i] = true;
                }
            }
        }
    }

    return temp;
}

vector<vector<int> *> *BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 1; i < n; i++)
    {
        visited[i] = false;
    }

    vector<vector<int> *> *v = new vector<vector<int> *>();

    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> *x = getpath(edges, n, i, visited);
            sort(x->begin(), x->end());
            v->push_back(x);
        }
    }

    delete[] visited;
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
        int **edges = new int *[V + 1];
        for (int i = 1; i <= V; i++)
        {
            edges[i] = new int[V + 1];
            for (int j = 1; j <= V; j++)
            {
                edges[i][j] = 0;
            }
        }

        for (int i = 1; i <= E; i++)
        {
            int f, s;
            cin >> f >> s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }

        // bool *visited = new bool[V+1];
        // for (int i = 1; i <= V; i++)
        // {
        //     visited[i] = false;
        // }

        vector<vector<int> *> *v = BFS(edges, V + 1);
        for (int i = 0; i < v->size(); i++)
        {
            vector<int> *value = v->at(i);
            for (int i = 0; i < value->size(); i++)
            {
                cout << value->at(i) << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < V; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
    
    }

    return 0;
}