class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0, len = 0, j = 0;
        while(str[j] != '\0'){
            if(str[j] == ' ')    count += 3;
            else    count++;
            len++;    j++;
        }
        while(len > -1){
            if(str[len] == ' ')    {len--; str[count--] = '0'; str[count--] = '2'; str[count--] = '%';}
            else     {str[count--] = str[len--];}
           
        }
	}
};
