#include <bits/stdc++.h>
using namespace std;

void quickSort(std::vector<int>& nums, int low, int hight){
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
    quickSort(nums, low, i - 1);
    quickSort(nums, i + 1, hight);

}

int main() {
    vector<int> nums= {10, 7, 8, 9, 1, 5};
    quickSort(nums, 0, 5);
    
    cout << "Sorted array: ";
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
