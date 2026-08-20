#include <iostream>
#include <optional>
#include <queue>
#include <vector>

// LeetCode 104. Maximum Depth of Binary Tree
//
// Given the root of a binary tree, return its maximum depth.
//
// A binary tree's maximum depth is the number of nodes along the longest path
// from the root node down to the farthest leaf node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Leetcode104 {
public:
    int maxDepth(TreeNode* root) {
        return nav(root);
    }

    int nav(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = root->left == nullptr ? 0 : this->nav(root->left);
        int right = root->right == nullptr ? 0 : this->nav(root->right);
        return std::max(left, right) + 1;
    }
};

// Builds a binary tree from a LeetCode-style level-order list, where
// std::nullopt marks a missing child.
static TreeNode* buildTree(const std::vector<std::optional<int>>& values) {
    if (values.empty() || !values[0].has_value()) return nullptr;

    TreeNode* root = new TreeNode(*values[0]);
    std::queue<TreeNode*> pending;
    pending.push(root);

    size_t i = 1;
    while (!pending.empty() && i < values.size()) {
        TreeNode* node = pending.front();
        pending.pop();

        if (i < values.size()) {
            if (values[i].has_value()) {
                node->left = new TreeNode(*values[i]);
                pending.push(node->left);
            }
            i++;
        }

        if (i < values.size()) {
            if (values[i].has_value()) {
                node->right = new TreeNode(*values[i]);
                pending.push(node->right);
            }
            i++;
        }
    }

    return root;
}

static void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Leetcode104 solution;

    std::vector<std::vector<std::optional<int>>> tests = {
        {3, 9, 20, std::nullopt, std::nullopt, 15, 7},  // 3
        {1, std::nullopt, 2},                           // 2
        {},                                             // 0
        {0},                                            // 1
        {1, 2, 3, 4, std::nullopt, std::nullopt, 5},    // 4
    };

    for (size_t i = 0; i < tests.size(); i++) {
        TreeNode* root = buildTree(tests[i]);
        std::cout << "Test Case " << (i + 1) << std::endl;
        std::cout << solution.maxDepth(root) << std::endl;
        deleteTree(root);
    }

    return 0;
}
