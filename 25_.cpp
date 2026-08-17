#include <bits/stdc++.h>
using namespace std;

int solve(long long white, long long dark) {
    long long w = white;
    long long d = dark;

    int layers = 0;
    long long size = 1;

    while (true) {
        if (layers % 2 == 0) {
            // Even index: white layer
            if (w < size)
            break;

            w -= size;
        } else {
        // Odd index: dark layer
        if (d < size)
        break;

        d -= size;
    }

layers++;
size *= 2;
}

return layers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        // Case 1: White on top
        int ans1 = solve(a, b);

        // Case 2: Dark on top
        int ans2 = solve(b, a);

        cout << max(ans1, ans2) << '\n';
    }

return 0;
}
