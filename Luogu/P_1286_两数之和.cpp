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

int Matrix[105][105], per[105], arr[105];
int n;

bool Gauss() {
    memset(Matrix, 0, sizeof Matrix);
    int cnt = 0;
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            Matrix[++cnt][i] = Matrix[cnt][j] = 1;
        }
    }
    rep(i, 1, n * (n - 1) / 2) {
        Matrix[i][n + 1] = arr[per[i]];
    }
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            if (Matrix[j][i]) {
                swap(Matrix[i], Matrix[j]);
            }
        }
        if (!Matrix[i][i]) {
            return 0;
        }
        rrep(j, i, n + 1) {
            Matrix[i][j] /= Matrix[i][i];
        }
        rep(j, i + 1, n) {
            rrep(k, i, n + 1) {
                Matrix[j][k] -= Matrix[j][i] * Matrix[i][k];
            }
        }
    }
    rrep(i, 1, n - 1) {
        rep(j, i + 1, n) {
            Matrix[i][n + 1] -= Matrix[i][j] * Matrix[j][n + 1];
        }
    }
    return 1;
}

main() {
    while (cin >> n) {
        vct<int> ans;
        rep(i, 1, n * (n - 1) / 2) {
            cin >> arr[i];
            per[i] = i;
        }
        do {
            if (Gauss()) {
                rep(i, 1, n) {
                    ans.push_back(Matrix[i][n + 1]);
                }
                sort(ans.begin(), ans.end());
                for (int v : ans) {
                    cout << v << ' ';
                } 
                cout << endl;
                goto _;
            }
        } while (next_permutation(per + 1, per + n * (n - 1) / 2 + 1));
        cout << "Impossible\n";
        _:;
    }
//	int t; cin >> t; while (t--) solve();
	return 0;
}
