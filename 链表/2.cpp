/*
707设计链表
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
*/
//这破题绝对不刷第二次
#include <iostream>
using namespace std;
class MyLinkedList{
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    LinkedNode* dummyHead;
    int size;
    MyLinkedList(){
        dummyHead = new LinkedNode(0);
        size = 0;
    }
    int get(int index){
        if(index > size - 1 || index < 0){
            return -1;
        }
        LinkedNode* cur = dummyHead->next;
        while (index)
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
        
    }
    void addAtHead(int val){
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }
    void addAtTail(int val){
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }
    void addAtIndex(int index, int val){
        if(index > size){
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyHead;
        while(index) {
            cur = cur->next;
            index--;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    void deleteAtIndex(int index){
        if(index >= size || index < 0){
            return;
        }
        LinkedNode* cur = dummyHead;
        while(index){
            cur = cur->next;
            index--;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }
    void print(){
        LinkedNode* cur = dummyHead->next;
        while (cur->next != nullptr)
        {
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << cur->val << endl;
    }
};
int main(){
    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList.print();
    linkedList.get(1);            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    linkedList.print();
    linkedList.get(1);            //返回3

}