#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool isevenYear(int n) {
    if (n % 100) {
        return !(n % 4);
    }
    return !(n % 400);
}

int arr[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    string a, b;
    cin >> a >> b;                                  
    int cnt = 0;
    string yearA = a.substr(0, 4), yearB = b.substr(0, 4);
    int iyearA, iyearB;
    sscanf(yearA.c_str(), "%d", &iyearA); sscanf(yearB.c_str(), "%d", &iyearB);
    for (int i = iyearA; i <= iyearB; i++) {
        string stri = to_string(i);
        string tmp = stri; reverse(tmp.begin(), tmp.end());
        stri += tmp;
        if (stri > b) {
            continue;
        } 
        string strYear = tmp.substr(0, 2), strMonth = tmp.substr(2, 2);
        int iMonth, iDay ;
        sscanf(strYear.c_str(), "%d", &iMonth);
        sscanf(strMonth.c_str(), "%d", &iDay);
        if (!iMonth || !iDay) {
            continue;
        }
        if (iMonth > 13) {
            continue;
        }
        if (iMonth == 2) {
            if (isevenYear(i) && iDay <= 29) {
                cnt++;
                continue;
            }
            if (!isevenYear(i) && iDay <= 28) {
                cnt++;
                continue;
            }
        }
        if (iDay <= arr[iMonth]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}