#include <bits/stdc++.h>
using namespace std;

//nums的left-middle时有序的，middle到right是有序的。
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
    
void mergeSort(std::vector<int>& nums, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high); //对两个有序数组进行排序
    }
}

int main(){
    vector<int> nums= {10, 7, 8, 9, 1, 5};
    mergeSort(nums, 0, 5);
    
    cout << "Sorted array: ";
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
  return 0;
}