class Codec {
public:

    void serializeHelper(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "null,";
            return;
        }

        result += to_string(root->val) + ",";

        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string value;
        getline(ss, value, ',');

        if (value == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};
