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

const int N = 1e3 + 5;
int arr[N], A[N][N], brr[N], n, m;

main() {
//	int t; cin >> t; while (t--) olve();
	cin >> n >> m;
	rep(i, 1, n) {
		arr[i] = brr[i] = i;
		rep(j, 1, n) {
			cin >> A[i][j];
		}
	}
	while (m--) {
		int a, x, y;
		cin >> a >> x >> y;
		if (a) {
			swap(arr[x], arr[y]);
		} else {
			swap(brr[x] , brr[y]);
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			cout << A[arr[i]][brr[j]] << ' ';
		}
		cout << endl;
	}
	return 0;
}
