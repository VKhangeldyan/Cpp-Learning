#include <iostream>

int countPositive(const int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return 0;
    }

    const int* end = arr + size;
    int count = 0;

    while (arr != end) {
        if (*arr > 0) {
            ++count;
        }
        ++arr;
    }

    return count;
}

int main() {

    int nums[] = {-4, 0, 7, 12, -1, 3};
    std::cout << countPositive(nums, 6) << std::endl;

    return 0;
}