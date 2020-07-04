#include <bits/stdc++.h>
#define ii pair<int,int>
const int N = 505;
using namespace std;

char mat[505][505];
int n;
int f;

void print() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%c",mat[i][j]);
		}
		putchar('\n');
	}
}

void dfs(int x, int y) {

	if(x<0||y<0||x>=n||y>=n) return;
	if(mat[x][y] == '*') return;
	if(mat[x][y]-'0' > f)  return;
	
	mat[x][y]='*';

	vector<ii> around;

	around.push_back({x, y+1});
	around.push_back({x, y-1});
	around.push_back({x-1, y});
	around.push_back({x+1, y});

	for(auto p : around) {
		dfs(p.first, p.second);
	}
}

int main() {

	cin>>n>>f;

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf(" %c", &mat[i][j]);
		}
	}

	dfs(0,0);

	print();

	return 0;
}
