#include <iostream>
#include <vector>
# define MAXSIZE 5
//二叉树的节点
typedef struct BTNode{
    char data;
    BTNode *lchild;
    BTNode *rchlld;
}BTNode;
//构建二叉树
BTNode* buildTreeByList(std::vector<char> listtree, int start){
    if(listtree[start] == '#' or start > listtree.size() - 1) return nullptr;
    BTNode *root = new BTNode();
    root->data = listtree[start];
    root->lchild = buildTreeByList(listtree, start * 2 + 1);  //都更新下
    root->rchlld = buildTreeByList(listtree, start * 2 + 2);  //右子树
    return root;
};
//
class Solution{
    public:
    //基本的三种遍历。
    void inorder(BTNode* root){
        if (root == nullptr) return;
        inorder(root->lchild);
        std::cout << root->data << " ";
        inorder(root->rchlld);
    }
    //层次遍历
    void levelOrder(BTNode* root){
        if(!root) return;
        int front = 0, rear = 0; //循环队列的头的尾巴
        BTNode* p;
        BTNode* que[MAXSIZE];
        rear = (rear + 1) % MAXSIZE;
        que[rear] = root;
        while(front != rear){ //队列不为空
            front = (front + 1) % MAXSIZE;
            p = que[front];
            std::cout << p->data << " ";
            if(p->lchild){
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->lchild;
            }
            if(p->rchlld){
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->rchlld;
            }

        }




    }

};

int main(){
    Solution solu;

    std::vector<char> listtree = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '#', '#', '#', '#', 'H', 'I'};
    BTNode* root = buildTreeByList(listtree, 0);

    std::cout << "中序遍历: " << std::endl;
    solu.inorder(root);
    std::cout << std::endl;

    std::cout << "层次遍历: " << std::endl;
    solu.levelOrder(root);
    std::cout << std::endl;
    
    return 0;
}