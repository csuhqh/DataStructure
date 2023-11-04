/**
 * 对二叉排序树进行查找
 * 
 * 对排序二叉树中序遍历是递增序列。
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct BTNode{
    int key;
    BTNode* lchild;
    BTNode* rchild;
}BTNode;

void buildBTree(BTNode*& root, int key){
    if(root == nullptr){
        root = new BTNode();
        root->key = key;
        root->lchild = nullptr;
        root->rchild = nullptr;
    }else{
        if(key > root->key){
            buildBTree(root->rchild, key);
        }else{
            buildBTree(root->lchild, key);
        }
    }
    
};

void inOrder(BTNode* root){
    if(root){
        inOrder(root->lchild);
        cout << root->key << " ";
        inOrder(root->rchild);
        
    }

};

class Solution{
    public:
    BTNode* bstSearch(BTNode* bt, int key){
        if(!bt) return nullptr;
        if(bt->key == key) return bt;
        if(bt->key > key) return bstSearch(bt->lchild, key);  //这里的return不能丢
        if(bt->key < key) return bstSearch(bt->rchild, key);
    }
};

int main(){
    Solution solu;
    BTNode* root = nullptr;
    vector<int> nums = {5, 4, 8, 3, 7, 6, 9, 10};
    
    for(int num: nums){
        buildBTree(root, num);
    }
    inOrder(root);
    cout << endl;
    cout << solu.bstSearch(root, 9)->key << endl;
    return 0;
}

