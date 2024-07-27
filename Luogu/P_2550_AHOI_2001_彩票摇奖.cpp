#include <bits/stdc++.h>
using namespace std;

int sign[1005], inp[1005][1005];
int tot[8];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 7; i++) cin >> sign[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 7; j++) {
            int x;
            cin >> x;
            inp[i][x]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= 7; j++) {
            int x = sign[j];
            if (inp[i][x]) cnt++;
        }
        tot[cnt]++; 
    }
    for (int i = 7; i >=  1; i--) cout << tot[i] << ' ';
}