#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = (1LL << 60);

const int MAXX = 10;
const int B = 16;

int n, q, x;

vector<int> d, s;

struct Matrix {
    ll a[MAXX][MAXX];

    Matrix() {
        for (int i = 0; i < MAXX; i++)
            for (int j = 0; j < MAXX; j++)
                a[i][j] = INF;
    }
};

/*
    Matrix for one platform.

    a[i][j]:

    Start i cells after the left boundary,
    finish j cells after the right boundary.
*/
Matrix makeMatrix(int len, int cost) {
    Matrix m;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {

            ll v = (ll)len - j - (i + 1);

            if (v <= 0) {
                m.a[i][j] = 0;
            } else {
                ll jumps = (v + x - 1) / x;
                m.a[i][j] = jumps * cost;
            }
        }
    }

    return m;
}

/*
    Merge two consecutive segments.

    C[i][j] =
        min_k A[i][x-1-k] + B[k][j]
*/
Matrix mergeMatrix(const Matrix &A, const Matrix &B) {
    Matrix C;

    for (int i = 0; i < x; i++) {

        for (int j = 0; j < x; j++) {

            ll best = INF;

            for (int k = 0; k < x; k++) {

                best = min(
                    best,
                    A.a[i][x - 1 - k] + B.a[k][j]
                );
            }

            C.a[i][j] = best;
        }
    }

    return C;
}

/*
    Segment tree over blocks.
*/
struct SegTree {

    int size;
    vector<Matrix> tree;

    SegTree(int n) {

        size = 1;

        while (size < n)
            size <<= 1;

        tree.resize(2 * size);
    }

    void update(int pos, const Matrix &value) {

        pos += size;

        tree[pos] = value;

        pos >>= 1;

        while (pos) {

            tree[pos] =
                mergeMatrix(tree[pos << 1],
                            tree[pos << 1 | 1]);

            pos >>= 1;
        }
    }

    Matrix query(int l, int r) {

        Matrix leftResult, rightResult;

        bool hasLeft = false;
        bool hasRight = false;

        l += size;
        r += size;

        while (l < r) {

            if (l & 1) {

                if (!hasLeft) {
                    leftResult = tree[l];
                    hasLeft = true;
                } else {
                    leftResult =
                        mergeMatrix(leftResult, tree[l]);
                }

                l++;
            }

            if (r & 1) {

                --r;

                if (!hasRight) {
                    rightResult = tree[r];
                    hasRight = true;
                } else {
                    rightResult =
                        mergeMatrix(tree[r], rightResult);
                }
            }

            l >>= 1;
            r >>= 1;
        }

        if (!hasLeft && !hasRight)
            return Matrix();

        if (!hasLeft)
            return rightResult;

        if (!hasRight)
            return leftResult;

        return mergeMatrix(leftResult, rightResult);
    }
};

/*
    Build matrix for platforms [L, R).

    Used for partial blocks and rebuilding
    one complete block.
*/
Matrix buildRange(int L, int R) {

    Matrix result;

    bool first = true;

    for (int i = L; i < R; i++) {

        Matrix cur = makeMatrix(d[i], s[i]);

        if (first) {
            result = cur;
            first = false;
        } else {
            result = mergeMatrix(result, cur);
        }
    }

    return result;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> x;

    d.resize(n);
    s.resize(n);

    for (int i = 0; i < n; i++)
        cin >> d[i];

    for (int i = 0; i < n; i++)
        cin >> s[i];

    int blocks = (n + B - 1) / B;

    SegTree st(blocks);

    /*
        Build one matrix for every block.
    */
    for (int b = 0; b < blocks; b++) {

        int L = b * B;
        int R = min(n, L + B);

        st.update(b, buildRange(L, R));
    }

    while (q--) {

        char type;
        cin >> type;

        if (type == '1') {

            int i, v;
            cin >> i >> v;

            --i;

            d[i] = v;

            int b = i / B;

            int L = b * B;
            int R = min(n, L + B);

            st.update(b, buildRange(L, R));
        }

        else if (type == '2') {

            int i, v;
            cin >> i >> v;

            --i;

            s[i] = v;

            int b = i / B;

            int L = b * B;
            int R = min(n, L + B);

            st.update(b, buildRange(L, R));
        }

        else {

            int l, r;
            cin >> l >> r;

            --l;

            /*
                We need the matrix for [l, r).

                Start with the first platform.
            */
            Matrix result =
                makeMatrix(d[l], s[l]);

            ++l;

            /*
                Process the left partial block.
            */
            while (l < r && l % B != 0) {

                result =
                    mergeMatrix(
                        result,
                        makeMatrix(d[l], s[l])
                    );

                ++l;
            }

            /*
                Process all complete blocks.
            */
            int blockL = l / B;
            int blockR = r / B;

            if (blockL < blockR) {

                Matrix middle =
                    st.query(blockL, blockR);

                result =
                    mergeMatrix(result, middle);

                l = blockR * B;
            }

            /*
                Process the right partial block.
            */
            while (l < r) {

                result =
                    mergeMatrix(
                        result,
                        makeMatrix(d[l], s[l])
                    );

                ++l;
            }

            /*
                Starting from the first cell means state 0.
                Finishing at the last cell also corresponds
                to state 0.
            */
            cout << result.a[0][0] << '\n';
        }
    }

    return 0;
}
