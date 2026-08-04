#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        string bestAlice = "";

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != '0') continue;

            // String after Alice deletes s[i]
            string afterAlice = s.substr(0, i) + s.substr(i + 1);

            string bestBob = "";
            bool first = true;

            for (int j = 0; j < (int)afterAlice.size(); j++) {
                if (afterAlice[j] != '1') continue;

                // String after Bob deletes afterAlice[j]
                string finalStr = afterAlice.substr(0, j) + afterAlice.substr(j + 1);

                if (first || finalStr < bestBob) {
                    bestBob = finalStr;
                    first = false;
                }
            }

            if (bestAlice.empty() || bestAlice < bestBob)
                bestAlice = bestBob;
        }

        cout << bestAlice << '\n';
    }

    return 0;
}
