#include <iostream>

int* copyArray(const int* source, int size) {
    if(source == nullptr || size <= 0) {
        return nullptr;
    }
    int* newArr = new int[size];

    for(int i = 0; i < size; i++) {
        newArr[i] = source[i];
    }
    return newArr;
}

int main() {

    int original[] = {10, 20, 30};
    int* copied = copyArray(original, 3);

    if(copied == nullptr) {
        std::cout << "Nothing to copy\n";
        return 0;
    }

    copied[0] = 100;

    for(int i = 0; i < 3; i++) {
       std::cout << original[i] << " ";
    }
    std::cout << '\n';

    for(int i = 0; i < 3; i++) {
        std::cout << copied[i] << " ";
    }
    std::cout << std::endl;

    delete[] copied;
    copied = nullptr;

    return 0;
}