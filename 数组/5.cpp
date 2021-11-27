/*
59.螺旋矩阵二
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，
且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix

输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    int top = 0, botton = n - 1, left = 0, right = n - 1;
    int num = 1;
    vector<vector<int>> res(n, vector<int>(n, 0));
    while(num <= n * n){
        for(int i = left; i <= right; i++){
            res[top][i] = num;
            num++;
        }
        top++;
        for(int i = top; i <= botton; i++){
            res[i][right] = num;
            num++;
        }
        right--;
        for(int i = right; i >= left; i--){
            res[botton][i] = num;
            num++; 
        }
        botton--;
        for(int i = botton; i >= top; i--){
            res[i][left] = num;
            num++;   
        }
        left++;
    }
    return res;
}

int main(){
    vector<vector<int>> vs = generateMatrix(3);
    cout << "[";
    for(int i = 0; i < vs.size(); ++i) {
	    cout << "[";
    	    for(int j = 0; j < vs[i].size(); ++j)  {
		    cout << vs[i][j];
		    if (j != vs[i].size() - 1) cout << ",";
	    }
	    cout << "]";
	    if (i != vs.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}