 private:
  bool check(int i,int par, vector<int> adj[], int v[]){
      v[i]=1;
      for(auto child:adj[i]){
          if(!v[child]){
              if(check(child,i, adj,v)) return true;
          }
          else if(par!=child) return true;
      }
      
          return false;

  }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int v[V]={0};
        for(int i=0;i<V;++i){
            if(!v[i]){
               if(check(i,-1,adj,v)) return true;
            }
        }
        return false;
    }
