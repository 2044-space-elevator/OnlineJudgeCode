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

int n, m;
double xh, arr[25], ans = 1e18, sum[25], len[25];

double Rand() {
    return rand() / RAND_MAX;
}

struct qu {
    int pos;
    bool operator < (const qu &b) const {
        return sum[pos] > sum[b.pos];
    }
};

double get() {
    memset(sum, 0, sizeof sum);
    memset(len, 0, sizeof len);
    priority_queue<qu> q;
    rep(i, 1, m) {
        q.push({i});
    }
    rep(i, 1, n) {
        int t = q.top().pos; q.pop();
        sum[t] += arr[i];
        len[t]++;
        q.push({t});
    }
    double res =0;
    rep(i, 1, m) {
        res += (sum[i] - xh) * (sum[i] - xh);
    }
    res /= m;
    return sqrt(res);
}

void SA() {
    double t = 1000;
    while (t > 1e-6) {
        int obja = rand() % n + 1, objb = rand() % n + 1;
        swap(arr[obja], arr[objb]);
        double tmp = get();
        if (tmp < ans) {
            ans = tmp;
        } else if (exp((tmp - ans) / t) > Rand()) {
            swap(arr[obja], arr[objb]);
        }
        t *= 0.96;
    }
}

main() {
    srand(time(NULL));
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) cin >> arr[i];
    rep(i, 1, n) xh += arr[i];
    //arr[1] = 1, arr[2] = 6, arr[3] = 2, arr[4] = 5, arr[5] = 3, arr[6] = 4;
    xh /= m;
    ans = get();
    while ((double)clock() / CLOCKS_PER_SEC <= 0.95) SA();
    printf("%.2lf", ans);
	return 0;
}
