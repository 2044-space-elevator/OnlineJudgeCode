#include <iostream>
#include <cmath>
using namespace std;

int T;

void solve() {
    double a, b, c; 
    cin >> a >> b >> c;
    cout << (int)ceil(abs(a - b) / 2 / c) << endl;
}

int main() {
    cin >> T;
    while (T--) solve();
}