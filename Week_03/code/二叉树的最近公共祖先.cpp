//思路：
// 最近公共祖先所满足的条件：(leftSon && rightSon) ||((x==p || x== q) && (leftSon || rightSon))
// 即: 1.左子树和右子树分别包含 p和q;
//     2.当前结点x为p或q,同时该节点的左子树或右子树为q或p
//  以上两个条件只要满足其一，即可得到最近公共祖先
//
// 法1：递归。 时间复杂度：O(n)
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left && right) return root;
		return left ? left : right;
	}
};


class Solution {
public:
	TreeNode* ans;
	bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return false;
		bool leftson = dfs(root->left, p, q);
		bool rightson = dfs(root->right, p, q);
		if ((leftson && rightson) || ((root->val == p->val || root->val == q->val) && (leftson || rightson))) {
			ans = root;
		}
		return leftson || rightson || (root->val == p->val || root->val == q->val);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		dfs(root, p, q);
		return ans;
	}
};