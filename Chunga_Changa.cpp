#include <iostream>
#define int long long
using namespace std;

int x, y, z;

inline int min(int x, int y, int z, int a) {
    return min(min(x, y), min(z, a));
}

signed main() {
    cin >> x >> y >> z;
    cout << (x + y) / z << ' ';
    if (!(x % z) || !(y % z)) cout << 0;
    else {
        if (x % z + y % z >= z) cout << min(x % z, y % z, z - x % z, z - y % z);
        else cout << 0;
    }
}