/*
	从右侧观察二叉树，将观察的的节点按从上到下的顺序输出，即从上到下输出二叉树每一层最右边节点
	层序遍历过程中每一次层的最右边一定是最后访问到，将层数绑定到节点，
	每弹出一个元素，更新该元素对应层的最右边节点数组view，遍历过程中会自动更新记录最右边节点
*/

#include <stdio.h>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> view;
    	std::queue<std::pair<TreeNode *, int> > Q;
    	if (root){
	    	Q.push(std::make_pair(root, 0));
	    }
    	while(!Q.empty()){
	    	TreeNode *node = Q.front().first;
	    	int depth = Q.front().second;
	    	Q.pop();
	    	if (view.size() == depth){//注意这里的处理方式，直接声明的vector只有有了确定的值之后才能通过view[]更新
	    		view.push_back(node->val);
	    	}
	    	else{
	    		view[depth] = node->val;
	    	}
	    	if (node->left){
	    		Q.push(std::make_pair(node->left, depth + 1));
	    	}
	    	if (node->right){
	    		Q.push(std::make_pair(node->right, depth + 1));
	    	}
	    }
    	return view;
    }
};

int main(){
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	Solution solve;
	std::vector<int> result = solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]\n", result[i]);	
	}
	return 0;
}
