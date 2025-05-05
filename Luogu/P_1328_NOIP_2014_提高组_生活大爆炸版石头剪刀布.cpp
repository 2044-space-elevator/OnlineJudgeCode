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

int arr[205], brr[205], na, nb, n;
int pd[6][6];

main() {
//	int t; cin >> t; while (t--) solve();
    pd[0][1] = -1;
    pd[0][2] = 1;
    pd[1][2] = -1;
    pd[0][3] = 1;
    pd[1][3] = 1;
    pd[2][3] = -1;
    pd[0][4] = -1;
    pd[1][4] = -1;
    pd[2][4] = 1;
    pd[3][4] = 1;
    cin >> n >> na >> nb;
    rep(i, 1, na) cin >> arr[i];
    rep(i, 1, nb) cin >> brr[i];
    int pta = 1, ptb = 1;
    int ansa = 0, ansb = 0;
    rep(i, 1, n) {
        int x = arr[pta], y = brr[ptb];
        pta++, ptb++;
        if (pta > na) pta = 1;
        if (ptb > nb) ptb = 1;
        int tmp = 1;
        if (x > y) swap(x, y), tmp = -tmp;
        tmp *= pd[x][y];
        if (tmp > 0) ansa++;
        if (tmp < 0) ansb++; 
    }
    cout << ansa << ' ' << ansb;
	return 0;
}
