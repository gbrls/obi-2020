/* gbrls (gas6) - UFPE, 24/10/2020 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#define ll long long int
#define ii pair<int,int>

using namespace std;

const int S = 1e3;
int vis[S] = {0};
int h[S];
vector<int> G[S];

int dfs(int cur) {
    int ans = 1;
    vis[cur] = 1;

    for(auto adj : G[cur]) {
        if(vis[adj] == 0) {
            ans += dfs(adj);
        }
    }

    return ans;
}

int main() {

    int s,t,p;
    scanf("%d%d%d",&s,&t,&p);

    for(int i=0;i<s;i++) {
        scanf("%d",&h[i]);
    }

    for(int i=0;i<t;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;
        --b;
        if(h[a] > h[b]) G[a].push_back(b);
        else if(h[b] > h[a]) G[b].push_back(a);
    }

    int ans = dfs(p-1)-1;
    printf("%d\n",ans);

    return 0;
}
