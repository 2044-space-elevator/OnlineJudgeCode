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


const int N = 4E4 + 4;
int pri[N], phi[N];
bool vis[N];
int cnt;
main() {
//	int t; cin >> t; while (t--) solve();
    repq(i, 2, N) phi[i] =i;
    repq(i, 2, N) {
        if (phi[i] == i) {
            rep(j, 1, N / i) {
                phi[i * j] = phi[i * j] / i * (i - 1);
            }
        }
    }
    int n;
     cin>> n;
     if (n == 1) { cout << 0; return 0; } 
    int ans = 0;
    repq(i, 2 ,n) {
        ans += phi[i];
    }
    cout << 3 + 2 * ans;
	return 0;
}
