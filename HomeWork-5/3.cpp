//if(str[len] == ' ')不可以写为if(str[len--] == ' ')其每进行一次判断均会自动减一使得结果出错
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
