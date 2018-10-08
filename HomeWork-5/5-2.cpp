/*
	面试题:替换空格
	题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如，输入"We are happy",则输出"We%20are%20happy"。
	解题思路：从前向后遍历字符串，每遇到空格需要扩充加载2个存储空间，并且由后向前依次拷贝，在空格后位置添加%20，时间复杂度O(n^2)。
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int j = 0, count = 0;
        while(str[j++] != '\0')  count++;
        int len = count, i = 0;
        while(str[i] != '\0'){
            if(str[i] == ' '){
                len += 2;
                for(int j = len; j > i + 2; j--)    str[j] = str[j - 2];
                str[i] = '%', str[i + 1] = '2', str[i + 2] = '0';
            }
            else{
                i++;
            }
        }
	}
};
