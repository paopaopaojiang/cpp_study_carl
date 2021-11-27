/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和≥target的长度最小的连续子数组[numsl, numsl+1, ..., numsr-1, numsr] 
并返回其长度。如果不存在符合条件的子数组，返回 0

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

输入：target = 4, nums = [1,4,4]
输出：1

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums){
    if(nums.size() == 0) return 0;
    int start = 0, end = 0, sum = 0, ans = INT_MAX;
    while(end < nums.size()){
        sum += nums[end];
        while(sum >= s){
            ans = min(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;
}

int main(){
    vector<int> a = {2,3,1,2,4,3};
    cout << minSubArrayLen(7, a) <<endl;
}