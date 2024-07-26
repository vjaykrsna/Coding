class ListNode {
    public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode* l3 = nullptr;
        if (l1->val < l2->val){
            l3 = l1;
            l1 = l1->next;
        }
        ListNode* temp = l3;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr){
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
                continue;
            }
            else if (l2 == nullptr){
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
                continue;
            }
            else{
                if (l1->val < l2->val){
                    l3 = l1;
                    l1 = l1->next;
                    l3 = l3->next;
                }
                else{
                    l3 = l2;
                    l2 = l2->next;
                    l3 = l3->next;
                }
            }
        }
        return temp;
    }
};

int main(){
    ListNode* l1;
    ListNode* l2;
    Solution s;
    s.mergeTwoLists(l1,l2);
}