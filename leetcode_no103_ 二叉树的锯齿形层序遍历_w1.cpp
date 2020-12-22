/* ------------------------------------------------------------------|
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：11.7 MB, 在所有 C++ 提交中击败了9.45%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }
    vector<vector<int> > res;
    stack<TreeNode*> s;
    int floorcnt = 1;
    bool dir = 1;
    s.emplace(root);

    while (!s.empty()) {
        vector<int> tmp;
        stack<TreeNode*> tmpstack;
        while (floorcnt--) {
            TreeNode* curr = s.top();
            s.pop();
            tmp.emplace_back(curr->val);

            if (dir) {
                if (curr->left) {
                    tmpstack.emplace(curr->left);
                }
                if (curr->right) {
                    tmpstack.emplace(curr->right);
                }
            }
            else {
                if (curr->right) {
                    tmpstack.emplace(curr->right);
                }
                if (curr->left) {
                    tmpstack.emplace(curr->left);
                }
            }
        }
        s = tmpstack;
        dir = !dir;
        floorcnt = s.size();
        res.emplace_back(tmp);
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = zigzagLevelOrder(root);
}