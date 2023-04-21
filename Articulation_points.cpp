class Solution {
   int t=0;
  private:
  void dfs(int node, int parent,vector<int> &v,int tin[], int low[], vector<int>adj[], vector<int>& ans){
      v[node]=1;
      tin[node]=low[node]=t;
      t++;
      int child=0;
      for(auto it: adj[node]){
          
          if(it==parent) continue;
          
          if(v[it]==0){
              dfs(it,node,v,tin, low,adj,ans);
              low[node]=min(low[node],low[it]);
              
              if(tin[node]<=low[it] && parent!=-1){
                  ans[node]=1;
              }
                        child++;

          }
          
          else{
            low[node]=min(low[node],tin[it]);
          }
      }
      if(child>1 && parent==-1) 
        ans[node]=1;
  }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> v(V,0);
        vector<int> ans(V,0);
        vector<int> ap;

        int tin[V],low[V];
        for(int i=0;i<V;++i){
            if(!v[i]){
                dfs(i,-1,v,tin,low,adj,ans);
            }
        }
        //sort(ans.begin(),ans.end());
        for(int i=0;i<V;++i){
            if(ans[i]==1){
                ap.push_back(i);
            }
        }
        if(ap.size()!=0) return ap;
        ap.push_back(-1);
        return ap;
    }
};
