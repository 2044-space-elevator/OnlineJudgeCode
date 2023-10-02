#include <bits/stdc++.h>
using namespace std;

int n, m, k, l, d;
pair<int,int> col[2005];
pair<int,int> row[2005];

int main() {
    cin >> n >> m >> k >> l >> d;
    for (int i = 1; i <= max(n, m); i++) {
        col[i].second = i;
        row[i].second = i;
    }
    for (int i = 1; i <= d; i++) {
        int xa, ya,xb, yb;
        cin >> xa >> ya >> xb >> yb;
        if (xa != xb) {
            col[min(xa, xb)].first++;
        }  else {
            row[min(ya, yb)].first++;
        }
    }
    sort(col + 1, col + n + 1, greater<pair<int, int> >());
    sort(row + 1, row + m + 1, greater<pair<int, int> >());
    vector<int> ans1, ans2;
    for (int i = 1; i <= k; i++) {
        ans1.push_back(col[i].second);
    } 
    for (int i = 1; i <= l; i++) {
        ans2.push_back(row[i].second);
    }
    sort(ans1.begin(), ans1.end()); sort(ans2.begin(), ans2.end());
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << ' ';
    }
}