#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
int n;
#define rep(a) for(int a=1;a<=n;a++)
using namespace std;

unordered_map<int, int> dict;
int arr[105];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    rep(i) rep(j) rep(k) {
        dict[arr[i] + arr[j] * arr[k]]++;
    }
    int ans = 0;
    rep(i) rep(j) rep(k) {
        if (!arr[i]) {
            continue;
        }
        ans += dict[arr[i] * (arr[j] + arr[k])];
    }
    cout << ans;
}