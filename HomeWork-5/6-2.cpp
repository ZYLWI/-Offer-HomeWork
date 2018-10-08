/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* phead = head;
        ListNode* ptail = head;
        vector<int> ArrayList;
        if(head == NULL)
            return ArrayList;
        while(head->next != NULL){
            ptail = head->next;
            head->next = ptail->next;
            ptail->next = phead;
            phead = ptail;
        }
        while(ptail != NULL){
            ArrayList.push_back(ptail->val);
            ptail = ptail->next;
        }
        return ArrayList;
    }
};
