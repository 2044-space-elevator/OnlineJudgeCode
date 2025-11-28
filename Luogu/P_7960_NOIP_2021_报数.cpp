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

const int N = 1E7 + 25;
bitset<N> va;
vector<int> inva;

void solve() {
	int x;
	cin >> x;
	if (va[x]) {
		cout << "-1\n";
		return;
	}
	cout << *upper_bound(inva.begin(), inva.end(), x)<< '\n';	
}

bool p(int n) {
	while (n) {
		if (n % 10 == 7) return 1;
		n /= 10;
	}
	return 0;
}

main() {
	// cout << p(270007);
	rep(i, 1, 1e7 + 21) {
		va[i] = va[i] | p(i);
		if (!va[i]) {
			inva.push_back(i);
			continue;
		}
		for (int j = 2; i * j <= 1e7 + 21; j++) {
			va[i * j] = 1;
		}
	}
	// rep(i, 1e7, 1e7 + 21) if (!va[i]) cout << 114514;
	int t; cin >> t; while (t--) solve();
	return 0;
}
