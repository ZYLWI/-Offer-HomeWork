# Chapter 2. Generic Algorithm<br>
## Small Section 2.3.2 string:<br>
>为了节省内存，C/C++把常量字符串放到单独的一个内存区域。当几个指针赋值给相同的常量字符串时，他们实际上会指向相同的内存地址。但是用常量内存初始化数组却有所不同。
```C++
  int _tmain(int argc, _TCHAR* argv[]){
    char str1[] = "hello world";
    char str2[] = "hello world";
    
    char* str3 = "hello world";
    char* str4 = "hello world";
    
    if(str1 == str2){
      printf("str1 and str2 are the same.\n");
    }else{
      printf("str1 and str2 are the not same.\n");
    }
    if(str3 = str4){
      printf("str3 and str4 are the same.\n");
    }else{
      printf("str3 and str4 are the not same.\n");
    }
  }
```
>1. str1和str2是两个字符串数组，我们会为它们分配两个长度为12字节的空间，并把"hello world"的内容分别赋值到数组中。这是两个初始地址不同的数组，因此str1的值不相同，所以输出的第一行是"str1 and str2 are not sname"<br>
>2. str3和str4是两个指针，我们无须为它们分配内存以存储字符串的内容，而只需要把它们指向"hello world"在内存中的地址就可以了。由于"hello world"是常量字符，它在内存中只有一个拷贝，因此str3和str4指向的是同一个地址。所以比较str3和str4的值得到的结果是相同的，输出第二行是"str3 and str4 are same"。<br>
### Interview question 5: repalcement string
>题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如，输入"We are happy",则输出"We%20are%20happy"<br>
**允许开辟新的空间**<br>
解析1：首先开辟一个空间大小相同的字符串进行拷贝赋值，然后从前向后遍历字符串，每次遇到空格赋值为*%20*,向后赋值即可，时间复杂度O(n)，空间复杂度为O(n)。<br>
[Interview question Answer 1](https://github.com/ZYLWI/-Offer-HomeWork/blob/master/HomeWork-5/1.cpp)<br>
**不允许开辟新的空间**<br>
解析2：从前向后遍历字符串，每遇到空格需要扩充加载2个存储空间，并且由后向前依次拷贝，在空格后位置添加%20，时间复杂度O(n^2)。<br>
[Interview question Answer 2](https://github.com/ZYLWI/JIANZHIOFFER-Pratice/blob/master/HomeWork-5/2.cpp)<br>
