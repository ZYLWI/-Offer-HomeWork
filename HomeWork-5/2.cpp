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
