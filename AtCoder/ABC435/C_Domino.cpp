#include <bits/stdc++.h>
using namespace std;

const int N = 5E5 + 5;
int endd = 1;
int arr[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >>arr[i];
    for (int i = 1; i <= n; i++) {
        if (endd < i) continue;
        endd = max(endd, i + arr[i] - 1);
    }
    cout << min(n, endd);
}