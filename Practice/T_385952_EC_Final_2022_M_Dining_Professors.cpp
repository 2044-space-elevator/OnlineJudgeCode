// Writen by 2044_space_elevator
#include <bits/stdc++.h>
using namespace std;
    
void solve() {
    
    // For many test cases
    
}

int n, a;
bool arr[114514];
bool vis[114514];
vector<pair<int, int> > one_near_zero;

int main() {
    cin >> n >> a;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        one_near_zero.push_back({arr[i] + arr[(i % n) + 1] + arr[((i + n - 2) % n) + 1], i});
    }
    sort(one_near_zero.begin(), one_near_zero.end(), greater<pair<int, int> >());
    for (int i = 0; i < a; i++) {
        
        vis[one_near_zero[i].second] = 1;
    }  
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i]) {
            ans += 3;
        } else {
            if (!vis[i]) ans++;
            if (!vis[(i % n) + 1]) ans++;
            if (!vis[((i + n - 2) % n) + 1]) ans++;
        }
    }
    cout << ans;
    return 0;
}