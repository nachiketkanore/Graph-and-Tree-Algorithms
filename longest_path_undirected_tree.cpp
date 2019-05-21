#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    vector<int> *adj;
public:
    Graph(int V);
    void addEdge(int v , int w);
    void longestPathLength();
    pair<int,int> bfs(int u);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

pair<int,int> Graph::bfs(int u){

    int dist[V];
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(u);

    dist[u] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto it = adj[t].begin();
            it!= adj[t].end();it++){

                int vd = *it;

                if(dist[vd] == -1){
                    q.push(vd);
                    dist[vd] = dist[t] + 1;
                }

            }
    }
    int maxDistance = 0;
    int farthestNode = -1;

    for(int x = 0; x<V;x++){
        if(dist[x] > maxDistance){
            farthestNode = x;
            maxDistance= max(maxDistance , dist[x]);
        }
    }

    return make_pair(farthestNode,maxDistance);


}

void Graph::longestPathLength(){
    pair<int, int> t1,t2;

    t1 = bfs(6);
    t2 = bfs(t1.first);

    cout<<"longest path is from "<<t1.first<<" to "
    <<t2.first <<" of length ==>" <<t2.second;

}


int main(){
   
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 9);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);

    g.longestPathLength();

    return 0;
}


/*
    15
    0 1
    0 2
    1 3
    1 4
    3 5
    2 6
    2 7
    7 8
    7 9
    6 10
    6 11
    10 12
    11 14
    11 15
    0

*/