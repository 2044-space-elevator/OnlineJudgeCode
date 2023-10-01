#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, t;
struct point {
    int hs;
    int x;
    int y;
};

bool cmp(point a, point b) {
    return a.hs > b.hs;
}

vector<point> arr;

int main() {
    cin >> n >> m >> t;  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x; 
            if (x) {
                arr.push_back({x, i, j});
            }
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    int nowx = arr[0].x, nowy = arr[0].y, nowt = nowx + 1, cnt = arr[0].hs;
    if (nowt > t) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i < arr.size(); i++) {
        if (nowx + arr[i].x > t) {
            cout << cnt << endl;
            return 0;
        } else {
            cnt += arr[i].hs;
            nowx = arr[i].x;
            nowy = arr[i].y;
            nowt += abs(arr[i].x - arr[i - 1].x) + abs(arr[i].y - arr[i - 1].y) + 1;
            if (nowt > t) {
                cnt -= arr[i].hs;
                cout << cnt << endl;
                return 0; 
            }
        }
    }
    cout << cnt;
}