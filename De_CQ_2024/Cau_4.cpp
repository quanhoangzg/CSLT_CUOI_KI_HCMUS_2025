#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

struct List{
    Node* pHead;
};

// Câu a)
void moveOdd2LeftEven2Right(List &l) {
    // Ý tưởng, giữ pointer head, nếu cái nào lẻ thì đưa nó lên đầu là được sẽ
    // thành thuật toán add head cho pointer.
    if (l.pHead == NULL || l.pHead->pNext == NULL) {
        return;
    }
    Node* prev = l.pHead;
    Node* curr = l.pHead->pNext;
    while (curr != NULL) {
        if (curr->data % 2 != 0) {
            prev->pNext = curr->pNext;
            curr->pNext = l.pHead;
            l.pHead = curr;
            curr = prev->pNext;
        } else {
            prev = curr;
            curr = curr->pNext;
        }
    }
}

// Câu b)
// Not Good
void reduceList(List &l, int K) {
    Node *curr = l.pHead;
    while (curr != NULL) {
        if (l.pHead->pNext == NULL) return;
        int minus = curr->data;
        Node *temp = curr;
        curr = curr->pNext;
        delete temp;
        int count = 1;
        while (count < K && curr != NULL) {
            minus = minus - curr->data;
            temp = curr;
            curr = curr->pNext;
            count++;
            delete temp;
        }
        l.pHead = new Node();
        l.pHead->data = abs(minus);
        l.pHead->pNext = curr;
        if (curr != NULL) {
            curr = l.pHead;
        }
    }
}

// Cách 2: Good
void reduceList(List &l, int K) {
    // Kiểm tra danh sách rỗng hoặc chỉ có 1 phần tử
    if (l.pHead == NULL || l.pHead->pNext == NULL) return;

    // Lặp cho đến khi danh sách chỉ còn đúng 1 node (node->next là NULL)
    while (l.pHead->pNext != NULL) {
        
        // 1. Lấy giá trị node đầu tiên
        Node *curr = l.pHead;
        int result = curr->data;
        
        // Dời Head sang node kế để chuẩn bị xóa node đầu
        l.pHead = curr->pNext; 
        delete curr;

        // 2. Trừ tiếp cho K-1 node tiếp theo
        int count = 1;
        // Bắt đầu duyệt từ l.pHead hiện tại (là node thứ 2 cũ)
        curr = l.pHead; 
        
        while (count < K && curr != NULL) {
            result = result - curr->data;
            
            // Xóa node vừa xử lý
            Node *temp = curr;
            curr = curr->pNext; // Dời curr sang node kế
            
            // Cập nhật l.pHead theo curr để danh sách luôn liền mạch
            l.pHead = curr; 
            
            delete temp;
            count++;
        }

        // 3. Tạo node gộp mới và đưa lên đầu danh sách
        Node *newNode = new Node();
        newNode->data = abs(result);
        
        // Nối node mới vào phần còn lại của danh sách (chính là l.pHead hiện tại)
        newNode->pNext = l.pHead; 
        
        // Cập nhật Head chính thức là node mới
        l.pHead = newNode;        
    }
}


// helper for test
void printList(List &l) {
    Node *curr = l.pHead;
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->pNext;
    }
    cout << "NULL" << endl;
}

int main() {
    List l = List();
    Node *node1 = new Node();
    node1->data = 1;
    l.pHead = node1;
    Node *node2 = new Node();
    node2->data = 2;
    node1->pNext = node2;

    Node *node3 = new Node();
    node3->data = 3;
    node2->pNext = node3;

    Node *node4 = new Node();
    node4->data = 4;
    node3->pNext = node4;

    Node *node5 = new Node();
    node5->data = 5;
    node4->pNext = node5;
    node5->pNext = NULL;
    cout << "Before: ";
    printList(l);
    moveOdd2LeftEven2Right(l);
    cout << "After move oddd to left and even to right:";
    printList(l);


    List l2 = List();
    Node *nodex1 = new Node();
    nodex1->data = 1;
    l2.pHead = nodex1;
    Node *nodex2 = new Node();
    nodex2->data = 2;
    nodex1->pNext = nodex2;

    Node *nodex3 = new Node();
    nodex3->data = 3;
    nodex2->pNext = nodex3;

    Node *nodex4 = new Node();
    nodex4->data = 6;
    nodex3->pNext = nodex4;

    Node *nodex5 = new Node();
    nodex5->data = 5;
    nodex4->pNext = nodex5;

    Node *nodex6 = new Node();
    nodex6->data = 8;
    nodex5->pNext = nodex6;
    nodex6->pNext = NULL;
    cout << "Before reduce: ";
    printList(l2);
    reduceList(l2, 3);
    cout << "After reduce: ";
    printList(l2);
}