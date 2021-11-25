/*
977. 有序数组的平方
给你一个按 非递减顺序 排序的整数数组 nums，
返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int> &nums){
    int size = nums.size();
    vector<int> vec(size, 0);
    int k = size - 1;
    for(int i = 0, j = size - 1; i <= j; ){
        if(nums[i] * nums[i] < nums[j] * nums[j]){
            vec[k] = nums[j] * nums[j];
            k--;
            j--;
        }else{
            vec[k] = nums[i] * nums[i];
            k--;
            i++;
        }
    }
    return vec;
}

int main(){
    vector<int> a = {-4,-1,0,3,10};
    vector<int> result = sortedSquares(a);
    vector<int>::iterator it;
    for(it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
}