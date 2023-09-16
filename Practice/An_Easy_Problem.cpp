#include <iostream>
using namespace std;

int f(int x) {
    int cnt = 0;
	while (x) {
		cnt++;
		x &= x - 1;
	}
	return cnt;
}


int main() {
    int n;
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        int res = n + 1;
        while (f(res) != f(n)) {
            res++; 
        }
        cout << res << endl;
    }
}