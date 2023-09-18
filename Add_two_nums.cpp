#include <iostream>

using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        sum+=curr1->val;
        curr1=curr1->next;
        sum+=curr2->val;
        curr2=curr2->next;
        carry=sum/10;
        ListNode* result = new ListNode(sum%10);
        ListNode* head = result;
        while(curr1!=nullptr || curr2!=nullptr){
            sum=0;
            if(curr1==nullptr && curr2!=nullptr){
                sum+=curr2->val;
                curr2=curr2->next;
            }
            else if (curr2==nullptr && curr1!=nullptr){
                sum+=curr1->val;
                curr1=curr1->next;
            }
            else {
                sum+=curr1->val;
                curr1=curr1->next;
                sum+=curr2->val;
                curr2=curr2->next;
            }
            sum+=carry;
            carry=sum/10;
            result->next=new ListNode(sum%10);
            result=result->next;
        }
        if(carry!=0){
            result->next=new ListNode(carry);
        }
        return head;
    }
};