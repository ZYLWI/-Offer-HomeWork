/*
	面试题:替换空格
	题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如，输入"We are happy",则输出"We%20are%20happy"。
	解题思路：从前向后遍历字符串，每遇到空格需要扩充三倍大小，那么首先开辟一个三倍空间大小的字符串，每次遇到空格向后赋值即可，时间复杂度O(n^2)。
*/

#include<iostream>

using namespace std;

void replaceSpace(char* str, int length){
	int count = 0;
	char str_1[length];
	for(int i = 0, j = 0; i < length; i++){
		if(str_1[i] == ' ') { count += 3; str[j++] = '%'; str[j++] = '2'; str[j++] = '0';}
		else str[j++] = str_1[i];
	}
	for(int i = 0; i < length + count; i++){
		cout << str[i];
	}
}

int main(){
	int N = 11;
//	cin >> N;
	char str[N * 3 + 1] = "hello world";
//	for(int i = 0; i < N; i++){
//		cin >> str[i];
//	}	
	replaceSpace(str, N);
	return 0;
}
