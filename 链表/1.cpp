/*
203. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，
请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}  // 节点的构造函数
};

ListNode* removeElement(ListNode* head, int val){
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while(cur->next != nullptr){
        if(cur->next->val == val){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }else{
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
}

void show(ListNode* head){
	while (head->next != nullptr)
	{
		cout << head->val << ' ';
		head = head->next;
	}
	cout<< head->val;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* a = new ListNode(2);head->next = a;
    ListNode* b = new ListNode(6);a->next = b;
    ListNode* c = new ListNode(3);b->next = c;
    ListNode* d = new ListNode(4);c->next = d;
    ListNode* e = new ListNode(5);d->next = e;
    ListNode* f = new ListNode(6);e->next = f;
    show(removeElement(head, 6));
}