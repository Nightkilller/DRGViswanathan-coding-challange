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

        int even = 2;
        int odd = 1;

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                cout << even << " ";
                even += 2;
            } else {
            cout << odd << " ";
            odd += 2;
        }
}
cout << "\n";
}

return 0;
}
