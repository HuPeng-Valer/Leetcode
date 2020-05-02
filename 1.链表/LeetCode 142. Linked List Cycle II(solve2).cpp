/*
	求环起始节点，快慢指针思想
	快指针每次遍历走两步，慢指针每次遍历走一步，有环必定会有meet节点
	再从head和meet出发，两指针速度一样，相遇的节点即为环起始节点
*/
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	ListNode *fast = head;
    	ListNode *slow = head;
    	ListNode *meet = NULL;
    	while(fast){
    		slow = slow->next;
    		fast = fast->next;
    		if (!fast){
		    	return NULL;
		    }
		    fast = fast->next;
		    if (fast == slow){
    			meet = fast;
    			break;
    		}
	    }
	    if (meet == NULL){
    		return NULL;
    	}
    	while(head && meet){
	    	if (head == meet){
	    		return head;
	    	}
	    	head = head->next;
	    	meet = meet->next;
	    }
        return NULL;
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;
	Solution solve;
	ListNode *node = solve.detectCycle(&a);
	if (node){
		printf("%d\n", node->val);
	}
	else{
		printf("NULL\n");
	}
	return 0;
}
