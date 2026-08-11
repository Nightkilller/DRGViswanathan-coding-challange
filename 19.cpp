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

        vector<long long> w(n);
        for (auto &x : w) cin >> x;

        if (n == 1) {
            cout << "NO\n";
            continue;
        }

        long long mnOdd = LLONG_MAX;
        long long mxEven = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                mnOdd = min(mnOdd, w[i]);
            else
                mxEven = max(mxEven, w[i]);
        }

        if (mxEven + 1 < mnOdd)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
