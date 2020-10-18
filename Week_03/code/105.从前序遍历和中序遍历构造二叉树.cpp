/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// 重点：理解前序遍历和中序遍历的定义
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int preorderLength = preorder.size();
		int inorderLength = inorder.size();
		if (preorderLength != inorderLength) return NULL;
		unordered_map<int, int> inorderMap;
		// 构建哈希表存放中序遍历序列
		for (int i = 0; i < inorderLength; i++) {
			inorderMap[inorder[i]] = i;
		}
		//
		return buildTree(preorder, 0, preorderLength - 1, inorderMap, 0, inorderLength - 1);
	}
private:
	TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, unordered_map<int, int>& inordermap, int inLeft, int inRight) {
		if (preLeft > preRight || inLeft > inRight) return NULL;
		//获取根节点的值
		int rootValue = preorder[preLeft];
		//创建根节点
		TreeNode* root = new TreeNode(rootValue);
		//在中序遍历中找出根节点的下标
		int pIndex = inordermap[rootValue];
		//左子树
		root->left = buildTree(preorder, preLeft + 1, pIndex - inLeft + preLeft, inordermap, inLeft, pIndex - 1);
		// 右子树
		root->right = buildTree(preorder, pIndex - inLeft + preLeft + 1, preRight, inordermap, pIndex + 1, inRight);
		return root;
	}
};