//tc: O(n+2e)+ O(n)
// sc: O(n) +O(n)

bool check(int i, vector<int> adj[], int v[]){
      v[i]=1;
      queue<pair<int , int>> q;
      q.push({i,-1});
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(auto child: adj[node]){
              if(!v[child]){
                  v[child]=1;
                q.push({child,node});
              }
              else if(parent!=child){
                  return true;;
              }
          }
      }
      return false;
  }
 // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int v[V]={0};
        for(int i=0;i<V;++i){
            if(!v[i]){
               if(check(i,adj,v)) return true;
            }
        }
        return false;
    }
