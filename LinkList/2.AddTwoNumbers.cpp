#include <iostream>
using namespace std;

    //int data1[] = {9,9,9,9,9,9,9};
    //int data1[] = {0};
    //int data1[] = {2, 3, 4}

    // int data2[] = {5, 6, 4};
    //int data2[] = {9,9,9,9};
    //int data2[] = {0};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode Nd;
typedef ListNode* Link;
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode *initListNode(int data[], int sz);
void showListNode(ListNode *head, string tags);


int main() {

    int data1[] = {9,9,9,9,9,9,9}, data2[] = {9,9,9,9};
    int sz = sizeof(data1) / sizeof(int);
    ListNode *l1 = initListNode(data1, sz);
    sz = sizeof(data2) / sizeof(int);
    ListNode *l2 = initListNode(data2, sz);
    showListNode(l1, "L1");
    showListNode(l2, "L2");
    Link res = addTwoNumbers(l1, l2);

    showListNode(res, "L3");
    return 0;
}

Link initListNode(int data[], int sz) {
    Link head = nullptr;
    Link p = nullptr;
    for(int i = 0 ; i < sz ; ++i) {
        if (head == nullptr) {
            head = new ListNode(data[i]);
            p = head;
        }  
        else {
            p->next = new ListNode(data[i]);
            p = p->next;
        }
    }
    return head;
}

void showListNode(Link head, string tags) {
    Link p = head;
    cout << tags << ": ";
    while(p != nullptr) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode    Nd;
typedef Nd*        Link;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    Link p1 = l1, p2 = l2, l3 = nullptr, p3 = l3;

    while(p1 != nullptr && p2 != nullptr) {
        int sum = p1->val + p2->val;
        Link newNode = new Nd(sum);
        if (l3 == nullptr) {
            l3 = newNode;
            p3 = l3;
        } else {
            p3->next = newNode;
            p3 = p3->next;
        }

        p1 = p1->next; p2 = p2->next;
    }

    // join Residue of l1
    while(p1 != nullptr) {
        int data = p1->val;
        Link newNode = new Nd(data);
        if (l3 == nullptr) {
            l3 = newNode;
            p3 = l3;
        } else {
            p3->next = newNode;
            p3 = p3->next;
        }
        p1 = p1->next;
    }
    
    // join Residue of l2
    while(p2 != nullptr) {
        int data = p2->val;
        Link newNode = new Nd(data);
        if (l3 == nullptr) {
            l3 = newNode;
            p3 = l3;
        } else {
            p3->next = newNode;
            p3 = p3->next;
        }    
        p2 = p2->next;
    }
    // carry
    p3 = l3;
    while(p3 != nullptr) {

        if (p3->val >= 10) {
            p3->val %= 10;
            
            if (p3->next == nullptr) {
                Link newNode = new Nd(1);
                p3->next = newNode;
            } else {
                p3->next->val += 1;
            }
        }
        p3 = p3->next;
    }

    Link res = l3;

    return res;
}