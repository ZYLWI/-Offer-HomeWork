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
        std::stack<ListNode*> nodes;
        while(head){
            nodes.push(head);
            head = head -> next;
        }
        vector<int> ArrayList;
        while(!nodes.empty()){
            ArrayList.push_back(nodes.top()->val);
            nodes.pop();
        }
        return ArrayList;
    }
};
