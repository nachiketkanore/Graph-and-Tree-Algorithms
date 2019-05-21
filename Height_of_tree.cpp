/*Program to find Height of a rooted tree*/

#include<bits/stdc++.h>
using namespace std;

class Graph{

private:
    int V;
    vector<int> *adj;
public:
    Graph(int V);
    void addEdge(int u , int v);
    pair<int,int> bfs(int u);
    void findHeight(int root);

};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

pair<int,int> Graph::bfs(int u){
    queue<int> q;
    q.push(u);
    int dist[V];
    memset(dist,-1,sizeof(dist));
    dist[u] = 0;

    while(!q.empty()){
        int adjnode = q.front();
        q.pop();
        for(auto it = adj[adjnode].begin();it!=adj[adjnode].end();it++){

            int temp = *it;
            if(dist[temp] == -1){ //If the node is unvisited (i.e its dist[that_particular_node] = -1)
                q.push(temp);
                dist[temp] = dist[adjnode] +1;
            }

        }

    }

    int maxDistance = -1;
    int farthestNode = -1;

    for(int x= 0;x<V;x++){
        if(maxDistance < dist[x]){
            maxDistance = max(maxDistance, dist[x]);
            farthestNode = x;
        }
    }

    return make_pair(farthestNode , maxDistance);

}

void Graph::findHeight(int root){
    pair<int,int> ans;

    ans = bfs(root);


    cout<<"The height of the tree from " <<root<<" as root is "<<ans.second<<endl;
    cout<<"The path is from " <<root<<" to "<<ans.first<<" with distance "<<ans.second<<endl;
}




int main(){
    int vertices ;
    cout<<"Enter the number of vertices in the tree :";
    cin>>vertices;
    
    Graph tree(vertices);
    cout<<"Enter the pairwise edges in the tree\n";

    for(int x=1;x<vertices;x++){
        int aa, bb;
        cin>>aa>>bb;
        tree.addEdge(aa,bb);
    }
    
    int root = 0;
    tree.findHeight(root);

    return 0;
}

/*
    Example
    vertices = 15;
    edges = 
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
    11 13
    root = 0;

*/