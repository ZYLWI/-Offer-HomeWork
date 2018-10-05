/*
	解题思路：
		1.最初使用暴力的方法，每一行迭代寻找，并且记录上一行的终止位置。整个查找范围是左上三角形。
		但是按照这种方法，最坏情况下，若查找数字大于矩阵中所有数字，那么需要遍历整个矩阵。时间复杂度O(n^2)
		2.进一步推想（其实看到了其他的解题方案），二分查找方法，按照1中方法记录上一行的终止位置。
		时间复杂度降低为O(nlogn)
		
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Find(int target, vector<vector<int>> array){
	for(int i = 0; i < array.size(); i++)
		if(binary_search(array[i].begin(), array[i].end(), target))	return true;
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
