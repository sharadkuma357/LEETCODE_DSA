#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

struct CompareNode {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->data > b->data;
    }
};

void push(ListNode*& head, int data) {
    ListNode* newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void PrintList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergelist(vector<ListNode*>& list) {
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;
    
    for (auto li : list)
        if (li) minHeap.push(li);

    ListNode dummy(0), *tail = &dummy;
    
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        tail->next = node;
        tail = tail->next;

        if (node->next) minHeap.push(node->next);
    }

    return dummy.next;
}

ListNode*  externalSort(vector<ListNode*>& list) {
    ListNode* sortedList = mergelist(list);
     return sortedList;
}

int main() {
    int N = 3;
    vector<ListNode*> list(N, nullptr);

    push(list[0], 50);
    push(list[0], 40);
    push(list[0], 30);

    push(list[1], 45);
    push(list[1], 35);

    push(list[2], 100);
    push(list[2], 80);
    push(list[2], 70);
    push(list[2], 60);
    push(list[2], 10);

    ListNode* ans = externalSort(list);
    PrintList(ans);
    return 0;
}

// PUSH ALL ARRAY IN MINHEAP 
// CREATE A DUMMY NODE AND JOIN NEXT NODE TO IT FROM ARRAY