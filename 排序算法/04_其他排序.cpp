#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

class Solution{
    public:
    //合并两个有序序列，只需要开辟一块等大空间与2个指针，时间复杂度为O(n)
    void merge(std::vector<int>& nums, int left, int middle, int right){
        std::vector<int> temp(nums);
        int i = left, j = middle + 1;
        while(i <= middle && j <= right){
            if(temp[i] > temp[j]){
                nums[left] = temp[j];
                ++j;
                
            }else{
                nums[left] = temp[i];
                ++i;
            }
            ++left;
        }
        while(i <= middle){
            nums[left] = temp[i];
            ++i;
            ++left;
        }
        while(j <= right){
            nums[left] = temp[j];
            ++j;
            ++left;
        }

    }
        
    void mergeSortImp(std::vector<int>& nums, int low, int high){
        if(low < high){
            int mid = (low + high) / 2;
            mergeSortImp(nums, low, mid);
            mergeSortImp(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }
    void mergeSort(std::vector<int>& nums){
        mergeSortImp(nums, 0, nums.size() - 1);
    }
    void bucketSort(std::vector<int>& nums){
        //关键词类型数量 = 3， 意味着需要3躺分配与回收，元素个数为n，每个类型有10种，需要10个桶。
        //时间：3(10)
        int d = 3, bucket_num = 10, n = nums.size();
        //10个桶子，对于每种关键字的组成关键字个数（0~9）
        std::queue<int> buckets[bucket_num];
        for(int count = 0; count < d; ++count){
            int key;
            //分配
            for(int i = 0; i < nums.size(); ++i){
                key = (nums[i] / int(pow(10, count))) % 10;
                buckets[key].push(nums[i]);
            }
            //收集
            int k = 0;
            for(int i = 0; i < bucket_num; ++i){
                while(!buckets[i].empty()){
                    nums[k] = buckets[i].front();
                    buckets[i].pop();
                    k++;
                }
            }
            std::cout<< "第" << count << "词" << "桶排序序列:";
            for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }



    }

};


int main(){
    Solution solu;
    std::vector<int> nums = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    std::cout << "起始序列: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    nums = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    solu.mergeSort(nums);
    std::cout << "二路归并排序: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //桶排序(多关键字)
    nums = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    solu.bucketSort(nums);
    std::cout << "桶排序序列: ";
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    return 0;
}