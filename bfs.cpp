#include<bits/stdc++.h>
using namespace std;
#define ll long long


void addEdge(vector<ll> adj[],ll u,ll v);
void bfs(vector<ll> adj[],ll u,bool vis[]);

int main(){
	
	ll i,n=8;                    //means their are 9 nodes starting from 0 to 8.
	vector<ll> adj[n+1];         //Created adjacency list of n+1 , due to index n
	bool vis[n+1];
	memset(vis,false,sizeof(vis));
 
    addEdge(adj,0, 2); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 0); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4);
    addEdge(adj,3, 3);
    addEdge(adj,3, 8);
    addEdge(adj,5, 7);

	cout<<"Complete Breadth First Traversal starting from  node 0"<<endl;

	for(i=0;i<n+1;i++){
		if(!vis[i]){
			bfs(adj,i,vis);
		}
	}
}

void addEdge(vector<ll> adj[],ll u, ll v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(vector<ll> adj[],ll u,bool vis[]){
	ll i,j,z;
	
	queue<ll> q;
	q.push(u);
	vis[u]=true;
	while(!q.empty()){	
	z=q.front();
	cout<<"  ->  "<<z;
	
	for(i=0;i<adj[z].size();i++){
		if(!vis[adj[z][i]]){
		q.push(adj[z][i]);
		vis[adj[z][i]]=true;
		}
	}
	q.pop();
}
}
