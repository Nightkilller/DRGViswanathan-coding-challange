#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long S;
        int q;
        cin >> S >> q;

        vector<long long> divisors;

        for (long long d = 1; d * d <= S; d++) {
            if (S % d == 0) {
                divisors.push_back(d);

                if (d * d != S)
                    divisors.push_back(S / d);
            }
        }

        sort(divisors.begin(), divisors.end());

        int n = divisors.size();

        vector<long long> pref(n + 1, 0);

        long long previous = 0;

        for (int i = 0; i < n; i++) {
            long long d = divisors[i];

            pref[i + 1] =
                pref[i] +
                (d - previous) * (S / d);

            previous = d;
        }

        while (q--) {
            long long x, y;
            cin >> x >> y;

            int k = lower_bound(divisors.begin(),
                                divisors.end(), x)
                    - divisors.begin();

            long long limit = S / y;

            int m = upper_bound(divisors.begin(),
                                divisors.end(), limit)
                    - divisors.begin();

            int full = min(k, m);

            long long answer = 0;

            if (full > 0)
                answer += divisors[full - 1] * y;

            answer += pref[k] - pref[full];

            if (k < n) {
                long long previousDivisor =
                    (k == 0 ? 0 : divisors[k - 1]);

                long long length = x - previousDivisor;

                answer += length *
                          min(y, S / divisors[k]);
            }

            cout << answer << '\n';
        }
    }

    return 0;
}
