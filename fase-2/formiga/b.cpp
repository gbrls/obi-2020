#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>  ii;
vector<int> adj[300];
vector<int> alt(300);
int counti = 0, ans;
set<int> vis;
void dfs(int u){
    if(vis.count(u)) return;

    vis.insert(u);

    if(adj[u].size() == 0){
        if(counti>ans)ans = counti;
        counti = 0;
        return;
    }

    for(auto e : adj[u]){
        counti++;
        dfs(e);
    }

}

int main(){ 
   
    int s,t,p;

    //cin>>s>>t>>p;
    scanf("%d%d%d",&s,&t,&p);
    --p;

    int height;
    
    for(int i=0 ; i<s;i++){
        cin>>height;
        alt[i] = height;
    }

    int a,b;

    for(int i=0;i<t;i++){
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        --a, --b;
        if(alt[a] < alt[b]){
          adj[b].push_back(a);
        }
        else if(alt[b] < alt[a]){
            adj[a].push_back(b);

        }
    }

    
    dfs(p);

    //cout<<ans<<endl;
    printf("%d\n",ans);

    return 0;
}

