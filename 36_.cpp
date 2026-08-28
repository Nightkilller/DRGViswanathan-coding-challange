#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        long long dp[2][2] = {};
        
        for (int first = 0; first <= 1; first++) {
            if (s[0] == '?' || s[0] - '0' == first)
                dp[first][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            long long ndp[2][2] = {};

            for (int prev = 0; prev <= 1; prev++) {
                for (int prevWeight = 0; prevWeight <= 1; prev++) {
                    if (dp[prev][prevWeight] == 0)
                        continue;

                    for (int cur = 0; cur <= 1; cur++) {
                        if (s[i] != '?' && s[i] - '0' != cur)
                            continue;

                        int weight = prev + cur;

                        if (i == 1 || weight != prevWeight) {
                            ndp[cur][weight] =
                                (ndp[cur][weight] + dp[prev][prevWeight]) % MOD;
                        }
                    }
                }
            }

            memcpy(dp, ndp, sizeof(dp));
        }

        long long ans = 0;

        for (int last = 0; last <= 1; last++) {
            for (int weight = 0; weight <= 1; weight++) {
                ans = (ans + dp[last][weight]) % MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
