#include <iostream>
#include <algorithm>
using namespace std;

struct elevator {
    int h, a, c;
};

elevator elevators[405];
int n;
bool dp[(int)4e5];

#define h(i) elevators[i].h
#define a(i) elevators[i].a
#define c(i) elevators[i].c

bool cmp(elevator a, elevator b) {
    return a.a < b.a;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h(i) >> a(i) >> c(i);
    }
    dp[0] = 1;
    sort(elevators + 1, elevators + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c(i); j++) {
            for (int k = a(i); k >= h(i); k--) {
                dp[k] |= dp[k - h(i)];
            }
        }   
    }
    for (int i = a(n); i; i--) {
        if (dp[i]) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}