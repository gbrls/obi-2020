#include <bits/stdc++.h>
using namespace std;

int main(){ 
   
    int a,l,n,bestx = 400,besty = 400,cont = 0,ans;

    cin>>a>>l>>n;

    int aux = a;
    a = min(aux,l);
    l = max(aux,l);
    int flag = 0;
    while(n--){
        cont++;
        int x,y;

        cin>>x>>y;
        aux = x;
        x = min(aux,y);
        y = max(aux,y);

        if(x >= a && y >= l){

            if(x*y < bestx*besty){
                bestx = x;
                besty = y;
                ans = cont;
            }

            flag=1;
        }

    }

    if(flag)cout<<ans<<endl;
    else cout<<-1<<endl;



return 0;
}
