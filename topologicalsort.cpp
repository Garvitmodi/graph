#include <bits/stdc++.h> 
using namespace std;


/* Topological sort   -  for a directed acyclic graph (DAG) , it is a linear ordering of vertices such that for every directed edge (u,v) u occurs before v.    */

stack<long long> stck;


void addEdge(vector<long long> adj[],int u, int v){
	
	adj[u].push_back(v);             //Adjacency List for Directed Graph

}

void topologicalfxn(long long u,vector <long long> adj[],long long n,bool vis[]){
	int i,j,z;
	
	 	
	vis[u]=true;

	for(auto x:adj[u]){
		if(!vis[x]){
			topologicalfxn(x,adj,n,vis);
		}	
	}
	stck.push(u);

}


void topologicalsort(vector <long long> adj[],long long n){
	bool vis[n];
	int i;
	
	for(int i = 0; i <n; i++) 
        vis[i] = false;
        
       
    for(i=0;i<n;i++){
        	if(!vis[i])
   			topologicalfxn(i,adj,n,vis);	     
	}
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
		long long int n,z;
		
		n=6;
		
		vector<long long> adj[n];
		
//		addEdge(adj,u,v);  
		addEdge(adj,0, 1); 
    	addEdge(adj,0, 2); 
    	addEdge(adj,1, 2); 
    	addEdge(adj,2, 3); 
    	addEdge(adj,4,5);

		cout<<"Topologically sorted vertices -  "<<endl;
		topologicalsort(adj,n);
		
		while(!stck.empty()){
			z=stck.top();
			cout<<z<<" ";
			stck.pop();
		}
		 
}
