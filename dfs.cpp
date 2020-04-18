#include <bits/stdc++.h> 
using namespace std;


void addEdge(vector<long long> adj[],int u, int v){
	
	adj[u].push_back(v);
	adj[v].push_back(u);

}

void dfsfxn(long long u,vector <long long> adj[],long long n,bool vis[]){
	int i,j,z;
	
	 	
	vis[u]=true;

	cout<<u<<" ";
	for(auto x:adj[u]){
		if(!vis[x]){
			dfsfxn(x,adj,n,vis);
		}
	
	}
	

}


void dfs(long long u,vector <long long> adj[],long long n){
	bool vis[n];
	int i;
	
	for(int i = 0; i <n; i++) 
        vis[i] = false;
        
        
   dfsfxn(u,adj,n,vis);	     

}




/*
void printGraph(vector<long long> adj[],int n){
	int i,j;
	for(i=0;i<n;i++){
		cout<<"For vertex " <<i<<" Adjency List is - "<<endl;
		cout<<"head ";
		for(auto it : adj[i])
		cout<<" -->  "<<it;
		cout<<endl;	
	}

}*/

int main()
{
		long long int n;
		
		n=6;
		
		vector<long long> adj[n];
		
//		addEdge(adj,u,v);  
		addEdge(adj,0, 1); 
    	addEdge(adj,0, 2); 
    	addEdge(adj,1, 2); 
    	addEdge(adj,2, 0); 
    	addEdge(adj,2, 3); 
    	addEdge(adj,3, 3); 

		dfs(2,adj,6);
		 
}
