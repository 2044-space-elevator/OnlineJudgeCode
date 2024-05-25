#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

int arr[(int)1e6 + 5], brr[(int)1e6 + 5];
main() {
//	int t; cin >> t; while (t--) solve();
	int n;
	cin >> n;
	int a = 0, b = 0;
	rep(i, 1, n) {
		cin >> arr[i];
	}	
	rep(i, 1, n) {
		cin >> brr[i];
	}
	rep(i, 1, n) {
		if (arr[i] > brr[i]) a++;
		if (brr[i] > arr[i]) b++;
	}
	cout << a << ' ' << b;
	cout << endl;
	if (a > b) cout << 'S';
	else if (a < b) cout << 'Q';
	else cout << "Tie";
	return 0;
}
