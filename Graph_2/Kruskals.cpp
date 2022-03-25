#include <iostream>
#include <algorithm>
using namespace std;
class Edge
{
public:
    int src;
    int des;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}


// <<------------ UNION FIND ALGORITHM ------------->>
int getParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }

    return getParent(parent[v], parent);
}

Edge *kruskals(Edge *edges, int n, int E)
{
    sort(edges, edges + E, compare);
    Edge *output = new Edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count < (n - 1))
    {
        Edge currentEdge = edges[i];
        int srcParent = getParent(currentEdge.src, parent);
        int desParent = getParent(currentEdge.des, parent);
        if (srcParent != desParent)
        {
            output[count] = currentEdge;
            count++;
            
            // <<----------------- UNION FIND ALGORITHM Top Parent Change ----------------->>
            parent[srcParent] = desParent;
        }
        i++;
    }

    return output;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, E;
        cin >> n >> E;
        Edge *edges = new Edge[E];

        for (int i = 0; i < E; i++)
        {
            int s, d, w;
            cin >> s >> d >> w;
            edges[i].src = s;
            edges[i].des = d;
            edges[i].weight = w;
        }

        Edge *output = kruskals(edges, n, E);
        int weightSum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // if (output[i].src < output[i].des)
            // {
            //     cout << output[i].src << " " << output[i].des << " " << output[i].weight << endl;
            // }
            // else
            // {
            //     cout << output[i].des << " " << output[i].src << " " << output[i].weight << endl;
            // }

            weightSum += (output[i].weight);
        }

        cout << weightSum << endl;
    }

    return 0;
}