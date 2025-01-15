#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>
#include <sstream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1. Maximum Depth of Binary Tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 2. Check Symmetric Tree
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

// 3. In-order Traversal
void inorderRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderRecursive(root->left, result);
    result.push_back(root->val);
    inorderRecursive(root->right, result);
}

vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    inorderRecursive(root, result);
    return result;
}

vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current || !stk.empty()) {
        while (current) {
            stk.push(current);
            current = current->left;
        }
        current = stk.top(); stk.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}

// 4. Find Minimum Value in Binary Tree
int findMin(TreeNode* root) {
    if (!root) return INT_MAX;
    return min(root->val, min(findMin(root->left), findMin(root->right)));
}

// 5. Check Identical Trees
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->val == root2->val) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
}

// 6. Lowest Common Ancestor
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);
    return left && right ? root : left ? left : right;
}

// 7. Level-Order Traversal
vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front(); q.pop();
            level.push_back(current->val);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        result.push_back(level);
    }
    return result;
}

// 8. Diameter of Binary Tree
int findDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;
    int leftHeight = findDiameter(root->left, diameter);
    int rightHeight = findDiameter(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}

int getDiameter(TreeNode* root) {
    int diameter = 0;
    findDiameter(root, diameter);
    return diameter;
}

// 9. Serialize and Deserialize Binary Tree
string serialize(TreeNode* root) {
    if (!root) return "# ";
    return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
}

TreeNode* deserializeHelper(istringstream& ss) {
    string val;
    ss >> val;
    if (val == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(ss);
    node->right = deserializeHelper(ss);
    return node;
}

TreeNode* deserialize(string data) {
    istringstream ss(data);
    return deserializeHelper(ss);
}

// 10. Construct Binary Tree from Preorder and Inorder Traversal
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderIndexMap, int& preorderIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;

    int rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = inorderIndexMap[rootVal];
    root->left = buildTreeHelper(preorder, inorder, inorderIndexMap, preorderIndex, inStart, inIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, inorderIndexMap, preorderIndex, inIndex + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderIndexMap[inorder[i]] = i;
    }
    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorder, inorderIndexMap, preorderIndex, 0, inorder.size() - 1);
}
