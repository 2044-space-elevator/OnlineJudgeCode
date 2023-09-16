#include <cmath>
#include <iostream>
#define int long long
using namespace std;

signed main() {
    int a, b;
    cin >> a >> b;
    long long res = pow(a, b) + pow(b, a); 
    cout << res;
}