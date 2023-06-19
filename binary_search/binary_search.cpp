#include <iostream>
#include <vector>

bool binary_search(std::vector<int> myVector, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = (right + left) / 2;

        if (myVector[middle] == target) {
            return true;
        } else if (myVector[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return false;
}
