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

        vector<long long> a(n);
        for (auto &x : a)
        cin >> x;

        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > 0)
            ans++;

            if (i > 0 && a[i] > 0) {
                a[i - 1] += a[i];
            }
    }

cout << ans << '\n';
}

return 0;
}
