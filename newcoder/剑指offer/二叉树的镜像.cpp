/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (NULL == pRoot){ return; }

        queue<TreeNode *> q;
        q.push(pRoot);
        TreeNode *tmp;
        
        while (!q.empty()){
            pRoot = q.front();
            q.pop();
            
            tmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
            
            if (pRoot->left){ q.push(pRoot->left); }
            if (pRoot->right){ q.push(pRoot->right); }
        }
    }
};
