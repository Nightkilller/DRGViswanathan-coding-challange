#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Floor {
    ll a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll x;
        cin >> n >> x;

        vector<vector<Floor>> buildings(n);
        vector<pair<ll, ll>> all;

        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;

            vector<ll> a(m), b(m);

            for (auto &v : a) cin >> v;
            for (auto &v : b) cin >> v;

            buildings[i].resize(m);

            for (int j = 0; j < m; j++) {
                buildings[i][j] = {a[j], b[j]};
                if (b[j] >= a[j])
                    all.push_back({a[j], b[j]});
            }
        }

        sort(all.begin(), all.end());

        vector<ll> prefCost;
        vector<ll> prefProfit;

        ll cur = x;

        int ptr = 0;
        while (ptr < (int)all.size() && all[ptr].first <= cur) {
            cur += all[ptr].second - all[ptr].first;
            ptr++;
        }

        int bestHeight = 0;
        int bestIndex = 1;

        for (int i = 0; i < n; i++) {
            ll money = cur;
            int h = 0;

            for (auto [a, b] : buildings[i]) {
                if (a <= money) {
                    money += b - a;
                    h++;
                } else {
                    break;
                }
            }

            if (h > bestHeight) {
                bestHeight = h;
                bestIndex = i + 1;
            }
        }

        cout << bestHeight << ' ' << bestIndex << '\n';
    }

    return 0;
}
