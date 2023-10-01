#include <iostream>
#include <cmath>
#define int long long
using namespace std;

void solve() {
    int n, p, q, e, d;
    cin >> n >> e >> d;    
    int m = 2 + n - e * d;
    int p_q = sqrt(m * m - 4 * n);
    p = (p_q + m) / 2;
    q = m - p;
    if (p * q != n)  {
        cout <<"NO\n";
        return;
    } 
    if (p > q) {
        swap(p, q);
    }
    cout << p << ' ' << q << endl;
}

signed main() {
    int t; cin >> t; while (t--) solve();
}