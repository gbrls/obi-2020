/* gbrls (gas6) - UFPE, 24/10/2020 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 


#define ll long long int
#define ii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
using namespace __gnu_pbds;

const int inf = 0x3f3f3f;

int x,y;

int t(int a, int b) {
    if(a >= x && b >= y) {
        int A = (a-x)*y;
        int B = (b-y)*x;
        int C = (a-x)*(b-y);
        return A+B+C;
    } else {
        return inf;
    }
}

int main() {

    scanf("%d%d",&x,&y);
    int n;
    scanf("%d",&n);
    vector<ii> vec;

    int ans = inf;
    int ai = -2;

    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        int u = t(a,b);
        if(u < ans) {
            ai = i;
            ans = u;
        }
        u = t(b,a);
        if(u < ans) {
            ai = i;
            ans = u;
        }
    }
    printf("%d\n",ai+1);

    return 0;
}

    

