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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}


int main() {
//	int t; cin >> t; while (t--) solve();
    int n, S, A;
    cin >> n >> S >> A;
    int sum = 0;
    while (n--) {
        int s,q;
        cin >> s >> q;
        sum += s * q;
    }
    cout << (sum >= S ? sum : sum+ A);
	return 0;
}
