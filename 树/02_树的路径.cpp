#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {int val;struct TreeNode *left;struct TreeNode *right;TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
} TreeNode;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回节点权值1个数比0的个数多一的路径数
     * @param root TreeNode类 权值为0和1的二叉树根节点
     * @return int整型
     */
    int result = 0;
    vector<int> path;
    int pathNumber(TreeNode* root) {
        // write code here
        backTracking(root, 0, 0);
        // dfs(root);
        return result;


    }
    void dfs(TreeNode* root){
      if(root == nullptr) return;
      path.push_back(root->val);
      if(root->left == nullptr && root->right == nullptr){
        cout << "print path:";
        for(int i = 0; i < path.size(); ++i){
            cout << path[i] << " ";
        }
        cout << endl;
      }
      dfs(root->left);
      dfs(root->right);
      path.pop_back();
    }
    void backTracking(TreeNode* root, int zero, int one){
      if(root == nullptr) return; //空节点直接返回
      //对该节点处理
      if(root->val == 0) zero++;
      else one++;
      
      path.push_back(root->val); //节点进入
      cout << "push: " << root->val << endl;
      if(root->left == nullptr && root->right == nullptr){ //叶子节点
        cout << "print path:";
        for(int i = 0; i < path.size(); ++i){
            cout << path[i] << " ";
        }
        cout << endl;
        // cout << "val:" <<  ":" << zero << " " << one << endl;
        if(zero + 1 == one) result++;
        // return;
        
      }
      backTracking(root->left, zero, one); //遍历左子树
      backTracking(root->right, zero, one); //遍历右子树
      cout << "back: " << path.back() << endl;
      path.pop_back();
       
    }

};


//构建二叉树
TreeNode* buildTreeByList(std::vector<int> listtree, int start){
    if(listtree[start] == '#' or start > listtree.size() - 1) return nullptr;
    TreeNode *root = new TreeNode(listtree[start]);
    root->left = buildTreeByList(listtree, start * 2 + 1);  //都更新下
    root->right = buildTreeByList(listtree, start * 2 + 2);
    return root;
};

void printTree(TreeNode* tree){
    if(!tree) return;
    printf("Node: %d\n", tree->val);
    printTree(tree->left);
    printTree(tree->right);
}

int main(){
    // 
    vector<int> nums = {1,0,1,'#',1,0,0};
    TreeNode* root = nullptr;
    root = buildTreeByList(nums, 0);
    printTree(root);
    Solution solu;
    int res = solu.pathNumber(root);
    cout << res << endl;

}