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

const int N = 1000005;

int n, m, k, ans, arr[N][3], brr[N], pre[N];
double sum = -1;

struct tmp {
    int x, y;
    double p;
}crr[N];

bool cmp(tmp a, tmp b) { return a.p < b.p; }
int find(int x) {
    return (
        pre[x] == x ? x :
        pre[x] = find(pre[x])
    );
}

void solve() {
	
}


main() {
//	int t; cin >> t; while (t--) solve();
    cin >> m;
    rep(i, 1, m) {
        cin >> brr[i];
    }
    cin >> n;
    rep(i, 1, n) {
        cin >> arr[i][1] >> arr[i][2];
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (i == j) {
                continue;
            }
            crr[k++] = {
                i,
                j,
                sqrt(
                    pow(arr[i][1] - arr[j][1], 2) +
                    pow(arr[i][2] - arr[j][2], 2)
                )
            };
        }   
    }
    int cnt = n;
    sort(crr + 1, crr + k + 1, cmp);
    rep(i, 1, n) {
        pre[i] = i;
    }
    rep(i, 1, k) {
        if (cnt == 1) {
            break;
        }
        int nod1 = find(crr[i].x), nod2 = find(crr[i].y);
        if (nod1 == nod2) {
            continue;
        }
        pre[nod1] = nod2;
        cnt--;
        sum = crr[i].p;
    }
    rep(i, 1, m) {
        ans += sum <= brr[i];
    }
    cout << ans << endl;
	return 0;
}
