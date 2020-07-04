#include <bits/stdc++.h>
const int C = 1e5+20;
using namespace std;

int cart[C] = {0};

int main() {
	int n,k,u; cin>>n>>k>>u;

	stack<int> nums[u];

	for(int i=0;i<n;i++) {
		cart[i] = k;
		for(int j=0;j<k;j++) {
			int aux; cin>>aux;
			--aux;
			nums[aux].push(i);
		}
	}

	int f=0;

	for(int i=0;i<u;i++) {
		int x; cin>>x;
		--x;
		vector<int> ans;

		while(!nums[x].empty()) {
			int v = nums[x].top(); nums[x].pop();
			cart[v]--;
			if(cart[v]==0) ans.push_back(v);
		}

		if(!f && ans.size() > 0) {

			sort(ans.begin(), ans.end());

			for(auto x : ans) cout<<(x+1)<<' ';
			
			putchar('\n');
			f=1;
		}
	}

	return 0;
}
