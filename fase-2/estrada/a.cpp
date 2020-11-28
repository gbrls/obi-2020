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

const int inf = 0x3f3f3f3f;

int main() {

    int t,n;
    scanf("%d%d",&t,&n);
    double ans = inf;

    vector<int> vec {0, t};
    for(int i=0;i<n;i++) {
        int aux;
        scanf("%d",&aux);
        vec.push_back(aux);
    }

    sort(vec.begin(), vec.end());

    for(int i=1;i<vec.size()-1;i++) {
        double d = 0;
        if(i == 1) {
            d += vec[i];
            d += abs(((double)vec[i])-((vec[i+1]+(double)vec[i])/2.0));
        } else if(i == vec.size()-2) {
            d += t-vec[i];
            d += abs(((double)vec[i])-((vec[i-1]+(double)vec[i])/2.0));
        } else {
            d += abs(((double)vec[i])-((vec[i-1]+(double)vec[i])/2.0));
            d += abs(((double)vec[i])-((vec[i+1]+(double)vec[i])/2.0));
        }

        ans = min(ans, d);
    }

    printf("%0.2lf\n",ans);

    return 0;
}

    

