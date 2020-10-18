//˼·��
// ������������������������(leftSon && rightSon) ||((x==p || x== q) && (leftSon || rightSon))
// ��: 1.���������������ֱ���� p��q;
//     2.��ǰ���xΪp��q,ͬʱ�ýڵ����������������Ϊq��p
//  ������������ֻҪ������һ�����ɵõ������������
//
// ��1���ݹ顣 ʱ�临�Ӷȣ�O(n)
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