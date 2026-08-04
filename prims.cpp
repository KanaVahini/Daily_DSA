#include<bits/stdc++.h>
using namespace std;

int primsMST(vector<vector<int>> adj[],int V ){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int>visited(V,0);
    pq.push({0,0});

    int sum=0;
    
    while(!pq.empty()){

        auto it=pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if(visited[node])
            continue;
        visited[node]=1;
        sum+=wt;

        for(auto neighbour:adj[node]){
            int adjNod=neighbour[0];
            int edgeWt = neighbour[1];

            if(!visited[adjNod]){
                pq.push({edgeWt,adjNod});
            }
        }
    }
    return sum;
}

int main(){
    int E,V;
    cout<<"Enter no of vertices:"<<endl;
    cin>>V;
    cout<<"Enter no of edges:"<<endl;
    cin>>E;

    vector<vector<int>> adj[V];


    cout<<"Enter edge and weight: "<<endl;
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});

    }
    cout<<"Weight of Minnimum Spanning Tree is: "<< primsMST(adj,V);
}