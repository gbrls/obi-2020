#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;cin>>x;

	x-=3;
	x%=8;

	int arr[8];
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 3;

	printf("%d\n", arr[x]);

	return 0;
}
