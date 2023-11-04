#include <bits/stdc++.h>
using namespace std;

/**
 * 堆排序：
 * 
*/
template<typename T>
class Heap{
    private:
        vector<T> nums;
        void heapfyUp(){ //调整内部节点，以维持堆特性。  父 >= 孩子
            int index = nums.size() - 1;
            while(index > 0){
                int parent = (index - 1) / 2;  //在完全二叉树中，parent = (chileIndex - 1) / 2
                if(nums[index] <= nums[parent]) break;
                swap(nums[index], nums[parent]);  //维持 父 > 子
                index = parent;
            }
        }

        void heapfyDown(){
            int current = 0;
            int l = 0, r = 0;
            while(true){
                l = current * 2 + 1; //左孩子
                r = current * 2 + 2; //右孩子
                int bigger = -1;
                if(l < nums.size() && r < nums.size()) bigger = nums[l] > nums[r] ? l : r;
                else if(l < nums.size() && r >= nums.size()) bigger = nums[l];
                else if(l >= nums.size() && r < nums.size()) bigger = nums[r];
                else break;
                if(nums[current] >= nums[bigger]) break;
                swap(nums[current], nums[bigger]);
                current = bigger;
            }
        }

    public:
        void insert(T value){
            nums.push_back(value);
            heapfyUp();
        }
        void remove(){
            if(nums.size() == 0){
                printf("Heap is empty");
                return;
            }
            nums[0] = nums.back(); //删除堆顶
            nums.pop_back(); // 删除队尾元素
            heapfyDown();
        }
        void sort(){
            while(!nums.empty()){
                cout << nums[0] << " ";
                remove();
            }
        }


};



int main(){
    Heap<int> heap;
    heap.insert(3);
    heap.insert(12);
    heap.insert(-1);
    heap.insert(164);
    heap.insert(-86);
    heap.sort();

    return 0;
}