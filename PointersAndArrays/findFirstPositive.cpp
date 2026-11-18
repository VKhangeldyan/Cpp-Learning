#include <iostream>

bool findFirstPositive(int* arr, int size, int*& result) {
     if(arr == nullptr || size <= 0) {
          result = nullptr;
          return false;
     }

     for(int i = 0; i < size; ++i) {
        if(arr[i] > 0) {
            result = &arr[i];
            return true;
        }
     }
     result = nullptr;
     return false;
}

int main() {

   int nums[] = {-4, 0, 7, 12};
   int* found = nullptr;

   if (findFirstPositive(nums, 4, found)) {
       *found = 100;
    } else {
        std::cout << "Something is false" << std::endl;
    }

    for(int i = 0; i < 4; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}