#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(long long x, const vector<int>& a, int n, int m, int w) {
    vector<long long> diff(n, 0);
    long long cur = 0;
    long long need = 0;
    for (int i = 0; i < n; i++) {
        cur += diff[i];
        if (a[i] + cur < x) {
            long long add = x - (a[i] + cur);
            need += add;
            if (need > m) {
                return false;
            }
            cur += add;
            if (i + w < n) {
                diff[i + w] -= add;
            }
        }
    }
    return need <= m;
}

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min_val = *min_element(a.begin(), a.end());
    long long low = min_val;
    long long high = min_val + static_cast<long long>(m);
    long long ans = min_val;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid, a, n, m, w)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}