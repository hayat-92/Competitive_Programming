#include <iostream>
#include <vector>
using namespace std;

// vector<int> *AllConnected(int **edges, int n, int sv, bool *visited)
// {
//     visited[sv] = true;
//     for (int i = 1; i < n; i++)
//     {
//         if (i == sv)
//         {
//             continue;
//         }

//         if (edges[sv][i] == 1)
//         {
//             if (visited[i])
//             {
//                 continue;
//             }
//             vector<int> *temp = AllConnected(edges, n, i, visited);
//             if (temp == NULL)
//             {
//                 return NULL;
//             }
//             temp->push_back(sv);
//             return temp;
//         }
//     }
//     vector<int> *fnl = new vector<int>();
//     fnl->push_back(sv);
//     return fnl;
// }



vector<int> *AllConnected(int **edges, int n, int sv, bool *visited)
{
    cout<<sv<<"fai"<<endl;
    // if (sv == b)
    // {
    //     vector<int> *e = new vector<int>();
    //     visited[sv] = true;
    //     // if(edges[])
    //     e->push_back(sv);
    //     return e;
    // }
    visited[sv] = true;
    for (int i = 1; i <n; i++)
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
            vector<int> *e = AllConnected(edges, n, i, visited);

            if (e != NULL)
            {
                e->push_back(sv);

                return e;
            }
            else
            {
                // vector<int> *e=new vector<int>();
                // e->push_back(sv);
                // return e;
                continue;
            }
        }
    }

    return NULL;
}

vector<vector<int> *> *DFS(int **edges, int n)
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
            vector<int> *x = AllConnected(edges, n, i, visited);
            // vector<int> *nw=new vector<int>();
            // for(int i=x->size()-1; i>=0; i--){
            //     nw->push_back(x->at(i));
            // }
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

        vector<vector<int> *> *v = DFS(edges, V + 1);
        for (int i = 0; i < v->size(); i++)
        {
            vector<int> *value = v->at(i);
            for (int i = 0; i < value->size(); i++)
            {
                cout << value->at(i) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}