/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// �ص㣺���ǰ���������������Ķ���
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int preorderLength = preorder.size();
		int inorderLength = inorder.size();
		if (preorderLength != inorderLength) return NULL;
		unordered_map<int, int> inorderMap;
		// ������ϣ���������������
		for (int i = 0; i < inorderLength; i++) {
			inorderMap[inorder[i]] = i;
		}
		//
		return buildTree(preorder, 0, preorderLength - 1, inorderMap, 0, inorderLength - 1);
	}
private:
	TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, unordered_map<int, int>& inordermap, int inLeft, int inRight) {
		if (preLeft > preRight || inLeft > inRight) return NULL;
		//��ȡ���ڵ��ֵ
		int rootValue = preorder[preLeft];
		//�������ڵ�
		TreeNode* root = new TreeNode(rootValue);
		//������������ҳ����ڵ���±�
		int pIndex = inordermap[rootValue];
		//������
		root->left = buildTree(preorder, preLeft + 1, pIndex - inLeft + preLeft, inordermap, inLeft, pIndex - 1);
		// ������
		root->right = buildTree(preorder, pIndex - inLeft + preLeft + 1, preRight, inordermap, pIndex + 1, inRight);
		return root;
	}
};