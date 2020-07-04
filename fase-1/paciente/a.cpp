#include <bits/stdc++.h>
const int N = 1e4+20;
using namespace std;

int indeg[N]={0};

int main() {
	int n,c;cin>>n>>c;

	for(int i=0;i<c;i++) {
		int id, m; cin>>id>>m;
		--id;
		for(int j=0;j<m;j++) {
			int other; cin>>other;
			--other;
			indeg[other]++;
		}
	}

	vector<int> ans;
	for(int i=0;i<n;i++) {
		if(indeg[i]==0) ans.push_back(i+1);
	}

	sort(ans.begin(), ans.end());

	for(auto e : ans) {
		cout<<e<<'\n';
	}

	return 0;
}
