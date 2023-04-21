#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, m;
   // cout<<"Enter No. of Nodes and Edges : "<<endl;
    cin>>n>>m;
    //cout<<"Enter Starting, Ending Node and Weight : \n";
    unordered_map<int, vector<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        u--,v--;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<int> key(n), par(n);
    vector<bool> mst(n);

    for(int i=0;i<n;i++){
        mst[i] = false;
        par[i] = -1;
        key[i] = INT_MAX;
    }
    key[0] = 0;

    for(int i=0;i<n;i++){
        int mi = INT_MAX;
        int k;
        for(int j=0;j<n;j++){
            if(mst[j] == false and key[j] < mi){
                mi = key[j];
                k = j;
            }
        }
        mst[k] = true;

        for(auto &x : adj[k]){
            int a = x.first;
            int b = x.second;

            if(key[a] > b and mst[a] == false){
                key[a] = b;
                par[a] = k;
            }
        }
    }
    cout<<"\nPath : \n";
    for(int i=1;i<n;i++){
        cout<<i+1<<" "<<par[i]+1<<" "<<endl;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=key[i];
    }
    cout<<"\nMinimum Cost of MST is : "<<sum<<endl;
}
