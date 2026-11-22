#include <iostream> 

void resizeArray(int*& arr, int oldSize, int newSize) {
    if(oldSize == newSize) {
        return;
    }
    if(newSize == 0) {
        delete[] arr;
        arr = nullptr;
        return;
    }
     
    int* newArr = new int[newSize]{};
    if(oldSize < newSize) {
        for(int i = 0; i < oldSize; i++) {
            newArr[i] = arr[i];
        }

    } else {
        for(int i = 0; i < newSize; i++) {
            newArr[i] = arr[i];
        }
    }
    delete[] arr;
    arr = newArr;
}

int main() {
    
    int* original = new int[3]{10, 20, 30};
    
    for(int i = 0; i < 3; i++) {
        std::cout << original[i] << ' ';
    }
    std::cout << '\n';

    resizeArray(original, 3, 5);
    for(int i = 0; i < 5; i++) {
        std::cout << original[i] << ' ';
    }
    std::cout << '\n';

    resizeArray(original, 5, 2);
    for(int i = 0; i < 2; i++) {
        std::cout << original[i] << ' ';
    }
    std::cout << '\n';

    resizeArray(original, 2, 0);
    if(original == nullptr) {
        std::cout << "Deleted array" << std::endl;
    }

    return 0;
}