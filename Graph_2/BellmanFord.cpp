#include <iostream>
using namespace std;
class Edge
{
public:
    int v1;
    int v2;
    int weight;
};

void bellmanFord(Edge **edges, int V, int E, int src, int dest)
{
    int *distance = new int[V+1];
    for (int i = 0; i <= V; i++)
    {
        distance[i] = INT_MAX;
    }

    distance[src] = 0;

    for (int j = 1; j <= V; j++)
    {

        for (int i = 1; i <= E; i++)
        {
            int v1 = edges[i]->v1;
            int v2 = edges[i]->v2;
            int weight = edges[i]->weight;

            if (distance[v1] != INT_MAX && distance[v2] > (distance[v1] + weight))
            {
                distance[v2] = distance[v1] + weight;
            }
        }
    }

    // for(int i=0; i<=V; i++){
    //     cout<<i<<" "<<distance[i]<<endl;
    // }

    int value=distance[dest]-distance[src];
    cout<<value<<endl;


}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        int s, d;
        cin >> s >> d;
        Edge **edges = new Edge *[E+1];
        for (int i = 1; i <= E; i++)
        {
            // edges[i]=new Edge();
            edges[i] = new Edge();
            cin >> edges[i]->v1 >> edges[i]->v2 >> edges[i]->weight;
        }

        bellmanFord(edges, V, E, s, d);
    }

    return 0;
}