#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int ans = 0;

int bits(int n) {
    int ans = 0;
    while (n) {
        n /= 10;
        ans++; 
    }
    return ans;
}

inline int addAllBit(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

inline int replace(int n) {
    int a = n;
    int lena;
    while (a >= 10) { 
        a = addAllBit(a);
    }
    return a;
}

void solve() {
    int ans = 0;
    int n;
    cin >> n;
    int len = bits(n);
    int omega = 1;
    for (int i = 1; i <= len; i++) {
        if (i % 2 == 0) {
            ans += (n / omega % 10) * omega;
        } else {
            ans += replace((n / omega % 10) * 7) * omega;
        }
        omega *= 10;
        // cout << ans << ' ';
    }
    if (addAllBit(ans) % 8 == 0) {
        cout << 'T' << endl;
    } else {
        cout << 'F' << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- ) solve();
}
