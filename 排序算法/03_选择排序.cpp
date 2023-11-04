#include <iostream>
#include <vector>

class Solution{
    public:
    void selectSort(std::vector<int>& nums){
        //每次选择乱序序列中最小的一个与乱序队列的首个元素交换
        int minValIndex = -1;
        int temp = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            minValIndex = i + 1;
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[j] < nums[minValIndex]){
                    minValIndex = j;
                }
            }
            temp = nums[minValIndex];
            nums[minValIndex] = nums[i];
            nums[i] = temp;
        }
    }



    void heapSort(std::vector<int>& nums){
        //建立初始大顶堆(如果下标从0开始，第一个有孩子的节点为n/2 -1)
        for(int i = nums.size() / 2 - 1; i >= 0; --i){ //遍历每一个右孩子的节点
            sift(nums, i, nums.size() - 1); //对以该节点为根的树进行调整
        }
        
        //堆排序
        for(int i = nums.size() - 1; i >= 0; --i){
            std::swap(nums[0], nums[i]);
            sift(nums, 0, i-1); //在减少了一个关键字的无序序列中进行调整（每次-1说明一个以及排好了，把最大的放到末尾）
        }
    }
    void sift(std::vector<int>& nums, int low, int hight){
        int i = low, j = i * 2 + 1; //j 为 节点i 的左孩子
        int temp = nums[low]; //保存节点的值
        while(j <= hight){ 
            if(j + 1 < hight && nums[j] < nums[j + 1]) ++j; //j + 1 < hight确保右孩子存在。++j使得j指向右孩子
            if(temp < nums[j]){  //根与较大的孩子比较
                nums[i] = nums[j];
                i = j; //向下
                j = i * 2 + 1;
            }else{
                break;  //调整结束
            }
        }
        nums[i] = temp;
    }
};

int main(){
    Solution solu;
    std::vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    std::cout << "起始序列: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    nums = {49, 38, 65, 97, 76, 13, 27, 49};
    solu.selectSort(nums);
    std::cout << "简单选择排序: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    nums = {49, 38, 65, 97, 76, 13, 27, 49};
    solu.heapSort(nums);
    std::cout << "堆排序: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}