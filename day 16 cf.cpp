#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long prefix = 0;
        bool possible = true;

        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;

            prefix += x;

            long long required = 1LL * i * (i + 1) / 2;

            if (prefix < required) {
                possible = false;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
