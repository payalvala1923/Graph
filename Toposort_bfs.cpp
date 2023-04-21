#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};



int main()
{

    	vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

    	Solution obj;
    	vector<int> v=obj.topo(6, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    

    return 0;
}
/*#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Wri>te your code here
    vector<int> adj[v+1];
    for(int i=0;i<e;++i)
    {
    
        adj[edges[i][0]].push_back(edges[i][1]);
    }
        
        
 
     queue<int> q; 
        vector<int> indegree(v+1, 0); 
        for(int i = 0;i<v;i++) {
            for(auto it: adj[i]) {
                indegree[it]++; 
            }
        }
        
        for(int i = 0;i<v;i++) {
            if(indegree[i] == 0) {
                q.push(i); 
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            topo.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it); 
                }
            }
        
      
    
}
      return topo;
}*/
