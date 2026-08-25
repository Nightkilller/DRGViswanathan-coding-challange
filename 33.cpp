class Solution {
public:

    struct TrieNode {
        TrieNode* child[26];
        int wordIndex;

        TrieNode() {
            wordIndex = -1;

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string word, int index) {
        TrieNode* curr = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (curr->child[i] == nullptr) {
                curr->child[i] = new TrieNode();
            }

            curr = curr->child[i];
        }

        curr->wordIndex = index;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* node,
             vector<string>& words) {

        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size()) {
            return;
        }

        if (board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];
        int index = ch - 'a';

        if (node->child[index] == nullptr) {
            return;
        }

        TrieNode* next = node->child[index];

        if (next->wordIndex != -1) {
            ans.push_back(words[next->wordIndex]);
            next->wordIndex = -1;
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, next, words);
        dfs(board, r - 1, c, next, words);
        dfs(board, r, c + 1, next, words);
        dfs(board, r, c - 1, next, words);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, words);
            }
        }

        return ans;
    }
};
