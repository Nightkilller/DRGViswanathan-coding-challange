#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> words(n);
        vector<string> abbr(m);

        // Letters that can initially be used
        bool available[26] = {};

        for (int i = 0; i < n; i++) {
            cin >> words[i];
            available[words[i][0] - 'a'] = true;
        }

        for (int i = 0; i < m; i++) {
            cin >> abbr[i];
        }

        bool changed = true;
        vector<bool> created(m, false);

        while (changed) {
            changed = false;

            for (int i = 0; i < m; i++) {
                if (created[i])
                    continue;

                bool possible = true;

                for (char c : abbr[i]) {
                    if (!available[c - 'A']) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    created[i] = true;
                    changed = true;

                    // The abbreviation itself becomes a word.
                    // Its first letter is already available,
                    // but keeping this makes the logic explicit.
                    available[abbr[i][0] - 'A'] = true;
                }
            }
        }

        bool ok = true;

        for (int i = 0; i < m; i++) {
            if (!created[i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
