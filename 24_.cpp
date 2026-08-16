#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;

        int row = 0, col = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x <= h)
                row++;

            if (x <= l)
                col++;
        }

        cout << min({row, col, n / 2}) << '\n';
    }

    return 0;
}
