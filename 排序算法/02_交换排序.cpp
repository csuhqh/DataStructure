#include <iostream>
#include <vector>

class Solution{
    public:
        void bubbleSort(std::vector<int>& nums){
            //每次都是从第一个元素开始，知道没有一轮中产生交换
            bool isSwap = true;
            int temp;
            while(isSwap){//迭代，知道某一轮没有交换
                isSwap = false;
                //一轮冒泡
                for(int i = 0; i + 1 < nums.size(); ++i){
                    if(nums[i] > nums[i + 1]){
                        temp = nums[i + 1];
                        nums[i + 1] = nums[i];
                        nums[i] = temp;
                        isSwap = true;
                    }
                }
            }
        }

        void quickSort(std::vector<int>& nums){
            imp(nums, 0, nums.size() - 1);
        }
        void imp(std::vector<int>& nums, int low, int hight){
            if(low >= hight) return;
            //对nums的low~hight进行排序
            int temp = nums[low];
            int i = low, j = hight;
            while(i < j){
                while(j > i && nums[j] >= temp) --j; //从右往左找小于枢纽的值。
                if(j > i){ //找到后
                    nums[i] = nums[j];
                    ++i; 
                }
                while(j > i && nums[i] < temp) ++i;  //从左往右找大于枢纽的值
                if(j > i){
                    nums[j] = nums[i];
                    --j;
                }
            }
            nums[i] = temp;
            imp(nums, low, i - 1);
            imp(nums, i + 1, hight);

        }
};


int main(){
    std::vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    std::cout << "起始序列: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    Solution solu;
    

    nums = {49, 38, 65, 97, 76, 13, 27, 49};
    solu.bubbleSort(nums);
    std::cout << "冒泡排序: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    nums = {49, 38, 65, 97, 76, 13, 27, 49};
    solu.quickSort(nums);
    std::cout << "快速排序: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;



    return 0;
}