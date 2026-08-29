#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXX = 5;
const ll INF = (ll)4e18;

int n, q, x;

vector<ll> d, s;

// Segment tree:
// tree[node][i][j]
//
// Since x <= 5, MAXX = 5 is enough.
vector<array<array<ll, MAXX>, MAXX>> tree;


// ------------------------------------------------------------
// Set every entry of a matrix to INF
// ------------------------------------------------------------
void clearMatrix(array<array<ll, MAXX>, MAXX>& a) {
    for (int i = 0; i < MAXX; i++) {
        for (int j = 0; j < MAXX; j++) {
            a[i][j] = INF;
        }
    }
}


// ------------------------------------------------------------
// Min-plus matrix multiplication
//
// C[i][j] = min_k (A[i][k] + B[k][j])
// ------------------------------------------------------------
void multiply(
    array<array<ll, MAXX>, MAXX>& C,
    const array<array<ll, MAXX>, MAXX>& A,
    const array<array<ll, MAXX>, MAXX>& B
) {
    clearMatrix(C);

    for (int i = 0; i < x; i++) {
        for (int k = 0; k < x; k++) {

            if (A[i][k] >= INF)
                continue;

            for (int j = 0; j < x; j++) {

                if (B[k][j] >= INF)
                    continue;

                C[i][j] = min(
                    C[i][j],
                    A[i][k] + B[k][j]
                );
            }
        }
    }
}


// ------------------------------------------------------------
// Construct matrix for one platform
//
// mat[i][j]:
// Start i cells after platform beginning,
// first land j cells after platform end.
//
// Formula:
// ceil((d + j - i) / x) - 1
// multiplied by penalty.
//
// i must actually be inside the platform.
// ------------------------------------------------------------
void makeLeaf(
    array<array<ll, MAXX>, MAXX>& mat,
    ll len,
    ll penalty
) {
    clearMatrix(mat);

    for (int i = 0; i < x; i++) {

        // Starting position must be inside the platform.
        if (i >= len)
            continue;

        for (int j = 0; j < x; j++) {

            ll distance = len + j - i;

            // ceil(distance / x)
            ll jumps = (distance + x - 1) / x;

            // Last jump leaves the platform,
            // so it does not cost anything.
            ll cost = (jumps - 1) * penalty;

            mat[i][j] = cost;
        }
    }
}


// ------------------------------------------------------------
// Build segment tree
// ------------------------------------------------------------
void build(int node, int l, int r) {

    if (l == r) {
        makeLeaf(tree[node], d[l], s[l]);
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    multiply(
        tree[node],
        tree[node * 2],
        tree[node * 2 + 1]
    );
}


// ------------------------------------------------------------
// Point update
// ------------------------------------------------------------
void update(int node, int l, int r, int pos) {

    if (l == r) {
        makeLeaf(tree[node], d[l], s[l]);
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(node * 2, l, mid, pos);
    else
        update(node * 2 + 1, mid + 1, r, pos);

    multiply(
        tree[node],
        tree[node * 2],
        tree[node * 2 + 1]
    );
}


// ------------------------------------------------------------
// Query segment tree
//
// result = identity initially.
//
// We multiply:
// result = result * tree[node]
//
// This preserves left-to-right order.
// ------------------------------------------------------------
void query(
    int node,
    int l,
    int r,
    int ql,
    int qr,
    array<array<ll, MAXX>, MAXX>& result
) {

    if (ql <= l && r <= qr) {

        auto old = result;

        multiply(
            result,
            old,
            tree[node]
        );

        return;
    }

    int mid = (l + r) / 2;

    if (ql <= mid) {
        query(
            node * 2,
            l,
            mid,
            ql,
            qr,
            result
        );
    }

    if (qr > mid) {
        query(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr,
            result
        );
    }
}


// ------------------------------------------------------------
// Cost of completely traversing the final platform.
//
// We enter the platform with state `u`.
//
// We need to finally stand on its last cell.
//
// Every jump that remains inside the platform costs s.
// The final jump onto/leaving the last cell is handled
// according to the formula.
//
// ------------------------------------------------------------
ll finalCost(ll len, ll penalty, int u) {

    ll ans = INF;

    // We can choose the exact first landing position.
    //
    // `a` = number of cells after the beginning
    // where the first landing happens.
    for (int a = 1; a <= min<ll>(u, len); a++) {

        // Number of jumps needed after this point.
        ll jumps =
            (len - a + x - 1) / x;

        ll cost = jumps * penalty;

        ans = min(ans, cost);
    }

    return ans;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> x;

    d.resize(n + 1);
    s.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 1; i <= n; i++)
        cin >> s[i];

    tree.resize(4 * n + 5);

    build(1, 1, n);

    while (q--) {

        char type;
        cin >> type;

        // ----------------------------------------------------
        // Update length
        // ----------------------------------------------------
        if (type == '1') {

            int i;
            ll v;

            cin >> i >> v;

            d[i] = v;

            update(1, 1, n, i);
        }

        // ----------------------------------------------------
        // Update penalty
        // ----------------------------------------------------
        else if (type == '2') {

            int i;
            ll v;

            cin >> i >> v;

            s[i] = v;

            update(1, 1, n, i);
        }

        // ----------------------------------------------------
        // Query
        // ----------------------------------------------------
        else {

            int l, r;

            cin >> l >> r;

            // Only one platform.
            if (l == r) {

                cout
                    << finalCost(d[l], s[l], 1)
                    << '\n';

                continue;
            }

            // Identity matrix.
            array<array<ll, MAXX>, MAXX> result;

            clearMatrix(result);

            for (int i = 0; i < x; i++)
                result[i][i] = 0;

            // Process platforms [l, r-1].
            query(
                1,
                1,
                n,
                l,
                r - 1,
                result
            );

            ll answer = INF;

            // result[0][i] means:
            //
            // Start from the first cell of platform l
            // and reach platform r with state i.
            //
            // Then finish platform r.
            for (int i = 0; i < x; i++) {

                if (result[0][i] >= INF)
                    continue;

                int u = i + 1;

                ll last =
                    finalCost(
                        d[r],
                        s[r],
                        u
                    );

                answer = min(
                    answer,
                    result[0][i] + last
                );
            }

            cout << answer << '\n';
        }
    }

    return 0;
}
