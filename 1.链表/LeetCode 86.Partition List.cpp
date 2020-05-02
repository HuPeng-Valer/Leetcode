/*
	已知链表头指针head与数值x，将所有小于x的节点放在大于等于x的节点前
	且保持这些节点的原来的相对位置
	思路，利用临时头节点，创建less_head和more_head节点，
	遍历原链表将节点放在对应less_head或more_head后面
*/
#include <stdio.h>
	
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode less_head(0);
    	ListNode more_head(0);
    	ListNode *less_ptr = &less_head;
    	ListNode *more_ptr = &more_head;
        while(head){
        	if (head->val < x){
        		less_ptr->next = head;
        		less_ptr = head;
			}
			else {
				more_ptr->next = head;
				more_ptr = head;
			}
        	head = head->next;
        }
        less_ptr->next = more_head.next;
        more_ptr->next = NULL;
        return less_head.next;
    }
};

int main(){
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;	
	Solution solve;
	ListNode *head = solve.partition(&a, 3);	
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}
