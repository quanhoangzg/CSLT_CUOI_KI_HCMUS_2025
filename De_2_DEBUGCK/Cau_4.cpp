#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* partitionList(Node* head, int x) {
    // Tạo 2 node giả (dummy) để làm đầu cho 2 danh sách
    Node* lessDummy = new Node();    
    Node* greaterDummy = new Node(); 
    
    // Con trỏ để chạy và nối đuôi cho 2 danh sách này
    Node* lessTail = lessDummy;      
    Node* greaterTail = greaterDummy;
    
    // Duyệt danh sách gốc
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data < x) {
            // Nếu nhỏ hơn x, nối vào danh sách bé
            lessTail->next = curr;
            lessTail = lessTail->next;
        } else {
            // Nếu lớn hơn hoặc bằng x, nối vào danh sách lớn
            greaterTail->next = curr;
            greaterTail = greaterTail->next;
        }
        curr = curr->next;
    }
    
    // Cắt đuôi danh sách lớn để tránh vòng lặp 
    greaterTail->next = NULL;
    
    // Nối danh sách bé vào danh sách lớn
    // lessDummy->next là phần tử đầu tiên của danh sách bé
    // greaterDummy->next là phần tử đầu tiên của danh sách lớn
    lessTail->next = greaterDummy->next;
    
    // 5. Cập nhật head mới và xóa dummy
    head = lessDummy->next;
    
    delete lessDummy;
    delete greaterDummy;
    
    return head;
}