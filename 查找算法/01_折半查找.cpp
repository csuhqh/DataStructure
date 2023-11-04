#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int halfSearch(vector<int> &nums, int target){
        int low = 0, high = nums.size() - 1; //注意size()的大小 - 1，数组越界【size当作最大下标】
        int middle = -1;
        while(low <= high){
            middle = (low + high) / 2;
            if(nums[middle] < target){
                low = middle + 1;
            }else if(nums[middle] > target){
                high = middle - 1;
            }else{
                return middle;
            }
        };
        return -1;
    };
};

int main(){
    Solution solu;
    vector<int> nums = {-1, 3, 5, 6, 4};
    int target = 4;
    int res = solu.halfSearch(nums, target);
    cout << res << endl;
    return 0;
}