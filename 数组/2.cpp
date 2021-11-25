/*
给你一个数组nums和一个值val，你需要原地移除所有数值等于val的元素，
并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用O(1)额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。
例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，
也会被视作正确答案。

输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3]
解释：函数应该返回新的长度5, 并且nums中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
*/
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val){
    int slow = 0;
    for(int fast = 0; fast < nums.size(); fast++){
        if(nums[fast] != val){
            nums[slow] = nums[fast];
            slow++;
        }
    }
    for(int i = 0; i < slow; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return slow;
}

int main(){
    vector<int> num = {0,1,2,2,3,0,4,2};
    cout << removeElement(num, 2) << endl;
}