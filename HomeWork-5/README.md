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
解析2：从前向后遍历字符串，每遇到空格需要扩充加载2个存储空间，在空格后位置添加%20，时间复杂度O(n^2)。<br>
[Interview question Answer 2](https://github.com/ZYLWI/JIANZHIOFFER-Pratice/blob/master/HomeWork-5/2.cpp)<br>
解析3：从后向前遍历字符串，先遍历一次字符串找到空格对应个数，使用计数器追随扩充后对应的位置，由后向前依次拷贝，在空格处添加%20,时间复杂度O(n)<br>
[Interview question Answer 3](https://github.com/ZYLWI/JIANZHIOFFER-Pratice/blob/master/HomeWork-5/3.cpp)<br>
## Small Section 2.3.3 string:<br>
>链表是一种动态数据结构，是因为在创建链表时，无需知道链表的长度。当插入一个节点时，只需要为新节点分配内存，然后调整指针的指向来确保每个新节点被链接到链表当中。内存不是在创建链表时一次性完成的，而是每添加一个节点分配一次内存。由于没有闲置的内存，链表的空间效率比数组高。<br>

**单链表定义如下**
```C++
	struct ListNode{
		int	m_nValue;
		ListNode* m_pnext;
	}
```
**向链表的末尾添加一个节点**
```C++
	void AddToTail(ListNode** pHead, int value){
		ListNode* pNew = new ListNode();
		pNew->m_nValue = value;
		pNew->m_pNext = nullptr;
		
		if(*pHead == nullptr){
			*pHead = pNew;
		}
		else
		{
			ListNode* pNode = *pHead;
			while(pNode->m_pNext != nullptr)
				pNode = pNode->m_pNext;
			pNode->m_pNext = pNew;
		}
	}
```
> *函数的第一个参数pHead是一个指向指针的指针。当向一个空链表中插入一个节点时，新插入的节点就是链表的头指针。由于此时会改动头指针，因此必须把pHead参数设置为指向指针的指针，否则出了这个函数pHead仍然是一个空指针。*<br>
> 由于链表中的内存不是一次性分配的，因而无法保证链表的内存和数组一样连续。因此，如果想在链表中找到它的第i个节点，那么我们只能从头节点开始，沿着指向下一个节点的指针遍历链表，它的时间效率为O(n)。而在数组中，我们可以根据下标在O(1)时间内找到第i个元素。<br>

**在链表中找到第一个含有某值的节点并且删除该节点**
```C++
void RemoveNode(ListNode** pHead, int value){
	if(pHead == nullptr || *pHead == nullptr)
		return;
	ListNode* pToBeDeleted = nullptr;
	if((*pHead)->m_nvalue == value){
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}	
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		
		if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value){
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if(pToBeDeleted != nullptr){
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}
```
