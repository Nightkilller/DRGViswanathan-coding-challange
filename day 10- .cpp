#include <bits/stdc++.h>
using namespace std;

bool isLucky(int x) {
    if (x == 0) return false;
    while (x > 0) {
        int d = x % 10;
        if (d != 4 && d != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    int cnt = 0;
    for (char c : n) {
        if (c == '4' || c == '7')
            cnt++;
    }

    cout << (isLucky(cnt) ? "YES" : "NO");

    return 0;
}
