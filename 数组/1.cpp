/*
二分查找
给定一个n个元素有序的（升序）整型数组nums和一个目标值target，
写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回-1。

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
*/
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(void){
    vector<int> num = {-1,0,3,5,9,12};
    cout << search(num, 9) << endl;
}