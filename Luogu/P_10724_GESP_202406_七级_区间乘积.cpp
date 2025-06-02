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

int cnt[(int)1e5 + 5], prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, n, fy[31], rec[1 << 10], arr[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    repq(i, 0, 10) {
        fy[prime[i]] = i;
    }
    cin >> n;
    rep(i, 1, 30) {
        int tmp = i;
        repq(p, 0, 10 ){
            while (tmp % prime[p] == 0) {
                cnt[i] ^= 1 << p;
                tmp /= prime[p];
                
            }
        }
    }
    ll re = 0, px = 0;
    rec[0] = 1;
    rep(i, 1, n ){
        cin >> arr[i];
        px ^= cnt[arr[i]];
        re += rec[px]++;
    } 
    cout << re;
	return 0;
}
