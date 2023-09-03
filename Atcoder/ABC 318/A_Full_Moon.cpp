#include <iostream>
using namespace std;

int main()
{
    int n, m, p;
    cin >> n >> m >> p; 
    int cnt = 0;
    for (int i = m; i <= n; i += p, cnt++);
    cout << cnt;
}