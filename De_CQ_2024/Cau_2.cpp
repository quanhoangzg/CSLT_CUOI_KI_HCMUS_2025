#include <iostream>
using namespace std;

int findPartitionIndex(int* nums, int size) {
    int prefix[size];
    prefix[0] = nums[0];
    for (int i = 1; i < size; i++) {
        prefix[i] = prefix[i-1] + nums[i];
    }

    int suffix[size];
    suffix[size-1] = nums[size-1];
    for (int i = size - 2; i >= 0; i--) {
        suffix[i] = suffix[i+1] + nums[i];
    }

    for (int i = 0; i < size-1; i++) {
        if (prefix[i] == suffix[i+1]) {
            return i;
        }
    }
    return -1;
}


int main() {
    int nums[] = {10,10};
    int size = 2;
    cout << findPartitionIndex(nums, size) << endl;
}