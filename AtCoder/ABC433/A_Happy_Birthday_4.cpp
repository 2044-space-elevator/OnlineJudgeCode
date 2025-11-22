#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    for (int i = 1; i <= 1000000; i++) {
        if (x % y == 0 && x / y == z) {
            cout <<"Yes\n"; return 0;
        }
        x++, y++;
    }
    cout <<"No\n";
}