#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string a, b;
        cin >> a >> b;

        vector<int> pa(1, 0), pb(1, 0);

        for (char c : a)
            pa.push_back((pa.back() + (c - '0')) % 10);

        for (char c : b)
            pb.push_back((pb.back() + (c - '0')) % 10);

        if (pa.back() != pb.back()) {
            cout << -1 << '\n';
            continue;
        }

        int n = pa.size();
        int m = pb.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            fill(cur.begin(), cur.end(), 0);
            for (int j = 1; j <= m; j++) {
                if (pa[i - 1] == pb[j - 1])
                    cur[j] = prev[j - 1] + 1;
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            swap(prev, cur);
        }

        cout << prev[m] - 1 << '\n';
    }

    return 0;
}
