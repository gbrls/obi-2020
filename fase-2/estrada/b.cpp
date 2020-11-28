#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>  ii;

int main(){ 
   
    int t,n;
    scanf("%d %d",&t,&n);

    double dist[20000] = {};

    dist[0] = 0;
    dist[n+1] = t;
    
    double ans = t;
    double visa,visp,vizi;
    for(int i=0;i<n;i++){
        scanf("%lf",&dist[i+1]);
    }
    sort(dist,dist+n+2);
    for(int i=0;i<n;i++){
        visa = (dist[i+1]-dist[i])/2;
        visp = (dist[i+2]-dist[i+1])/2;
        vizi = visa+visp;
        if(i>0 && i<n-1 && vizi<ans)ans = vizi;
    }
    visa = (dist[1] + (dist[2]-dist[1])/2);
    if(visa < ans)ans = visa;
    visa = (dist[n+1]-dist[n]+(dist[n]-dist[n-1])/2);
    if(visa < ans)ans = visa;
    
    printf("%.2lf\n",ans);

return 0;
}

