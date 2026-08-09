#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k, m;
        cin >> n >> k >> m;

        // Impossible
        if (k > m) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // First k-1 elements are 1
        for (int i = 1; i < k; i++) {
            cout << 1 << " ";
        }

        // kth element makes the sum of first k elements exactly m
        cout << m - k + 1;

        // Remaining elements
        for (int i = k + 1; i <= n; i++) {
            cout << " " << 1;
        }

        cout << "\n";
    }

    return 0;
}
