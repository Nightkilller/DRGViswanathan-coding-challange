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

        vector<int> freq(n * n + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                freq[x]++;
            }
    }

int limit = n * (n - 1);

bool possible = true;

for (int color = 1; color <= n * n; color++) {
    if (freq[color] > limit) {
        possible = false;
        break;
    }
}

cout << (possible ? "YES" : "NO") << '\n';
}

return 0;
}
