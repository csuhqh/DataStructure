#include <iostream>
#include <vector>

class Solution{
    public:
    //直接插入排序
    void insertSort(std::vector<int>& nums){
        int n = nums.size();
        int temp = -1;
        int j = 0;
        for(int i = 1; i < n; ++i){
            j = i - 1;
            temp = nums[i];
            //寻找插入位置
            while(j >= 0 && temp < nums[j]){
                nums[j + 1] = nums[j];
                --j;
            }
            //插入
            nums[j + 1] = temp;
        }
    }
    //折半排序
    void binaryInsertionSort(std::vector<int>& nums){
        int key, left, right, mid;
        for(int i = 1; i < nums.size(); ++i){
            key = nums[i];
            left = 0, right = i - 1;
            //寻找插入位置
            while(left <= right){
                mid = (right + left) / 2;
                if(nums[mid] > key){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            // if(left == mid + 1) std::cout << left << " == " << mid + 1 << std::endl; ??? 为什么用mid + 1替换 left错误
            //移动
            for(int j = i - 1; j >= left; --j){
                nums[j + 1] = nums[j];
            }
            //插入元素
            nums[left] = key;
        }
    }
    //希尔排序
    void shellSort(std::vector<int>& nums){
        int temp, j;
        for(int gap = nums.size() / 2; gap > 0; gap /= 2){
            for(int i = gap; i < nums.size(); ++i){
                temp = nums[i];
                j = i - gap;
                while(j >= 0 && temp < nums[j]){
                    nums[j + gap] = nums[j];
                    j -= gap;
                }
                nums[j + gap] = temp;
            }
        }
    }
};

int main(){
    std::vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    std::cout << "排序前: ";
    for(auto i: nums){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    Solution solu;
    solu.insertSort(nums);
    std::cout << "直接插入排序: ";
    for(auto i: nums){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    nums = {49, 38, 65, 97, 76, 13, 27, 49};
    solu.binaryInsertionSort(nums);
    std::cout << "折半排序: ";
    for(auto i: nums){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    nums = {49, 38, 65, 97, 76, 13, 27, 49};
    solu.shellSort(nums);
    std::cout << "希尔排序: ";
    for(auto i: nums){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}