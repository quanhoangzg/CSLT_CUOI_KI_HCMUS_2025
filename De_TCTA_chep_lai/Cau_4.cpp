#include <bits/stdc++.h>
using namespace std;

// Bài về linked list
struct Node
{
    int data;
    Node *pNext;
};

struct List {
    Node *pHead;
};

// Câu a)
// Giả dụ là khi đó giá trị xuất hiện lớn nhất không độc nhất thì return 0
// VD: 1 1 1 2 2 3 3 4 4 4 5 thì return 0 do 1 xuất hiện 3 lần và 4 xuất hiện 3 lần
int countUniqueCode(List mylist) {
    Node *currCheck = mylist.pHead;
    int countMax = 0;
    int maxFreValue;
    bool isEqual = false;
    while (currCheck != nullptr) {
        Node *currTraverse = currCheck->pNext;
        int count = 1;
        while (currTraverse != nullptr) {
            if (currCheck->data == currTraverse->data) {
                count++;
            }
            currTraverse = currTraverse->pNext;
        }
        if (count > countMax) {
            maxFreValue = currCheck->data;
            countMax = count;
            isEqual = false;
        } else if (count == countMax && currCheck->data != maxFreValue) {
            isEqual = true;
        }
        currCheck = currCheck->pNext;
    }

    if (isEqual) {
        return 0;
    } else {
        return maxFreValue;
    }
}

// Câu b)
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void removePrimeNumber(List &mylist) {
    Node *dummy = new Node();
    dummy->pNext = mylist.pHead;
    Node *curr = dummy;
    Node *next = dummy->pNext;
    while (next != nullptr) {
        if (isPrime(next->data)) {
            curr->pNext = next->pNext;
            delete next;
            next = curr->pNext;
        } else {
            curr = curr->pNext;
            next = next->pNext;
        }
    }
    mylist.pHead = dummy->pNext;
    delete dummy;
}


