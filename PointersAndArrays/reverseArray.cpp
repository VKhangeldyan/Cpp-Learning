#include <iostream>

void reverseArray(int* arr, int size) {
     if(arr == nullptr || size <= 1) {
        return;
     }

     int* start = arr;
     int* end = arr + size - 1;
     while(start < end) {
        int t = *start;
        *start = *end;
        *end = t;

        start++;
        end--;
     }
}

int main() {

    int arr[] = {10, 20, 30, 40, 50, 60};
    reverseArray(arr, 6);
    for(int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}