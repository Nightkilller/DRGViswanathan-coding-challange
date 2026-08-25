#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                cnt++;
            }
        }

        int ans = n;

        for (int i = 1; i < n - 1; i++) {
            int cur = cnt;

            if (s[i] != s[i - 1])
                cur--;

            if (s[i] != s[i + 1])
                cur--;

            if (s[i - 1] != s[i + 1])
                cur++;

            ans = min(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}
