/*
	解题思路：对于我暂称小白来说，看题目会想到特别多的解决方案，但是可行可实现的最后就是暴力。水滴石穿慢慢进步。
		  脱离常规思路，不拿(0, 0)为顶点，反之在左下角(同理右上方)求解，会发现现在棋盘行走思路有两种，要么，
		  向上走，要么向下走，最后抵达边界点停止。此时，我的时间复杂度是O(n)，最坏情况O(2n)。

	调试注意：while循环中应当将判断条件放置在前面,否则会出现数组首先越界，报段错误。
*/

#include<iostream>
#include<vector>

using namespace std;

bool Find(int target, vector<vector<int>> array){
	int cow = array.size(), low = array[0].size();
	int i = cow - 1, j = 0;
	while(i > -1 && j < low){
		if(target == array[i][j])	return true;
		while((i > -1 && j < low) && target < array[i][j])	i--;
		while((i > -1 && j < low) && target > array[i][j])	j++;
	}
	return false;
}

int main(){
        int N, M;
        cin >> N >> M;
        vector<vector<int>> array(N, vector<int>(M, 0));
        for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                        cin >> array[i][j];
                }
        }
        int target;
        cin >> target;
        cout << Find(target, array) << endl;
        return 0;
}
