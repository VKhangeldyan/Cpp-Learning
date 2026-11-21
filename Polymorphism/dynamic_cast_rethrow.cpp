#include <iostream>
#include <stdexcept>

class Animal {
    public:
       virtual ~Animal() {}
};

class Dog : public Animal {
    public:
        void bark() const {
        std::cout << "Woof" << std::endl;
        }
};

class Cat : public Animal {
    
};

void requireDog(Animal& animal) {
    Dog* dogPtr = dynamic_cast<Dog*>(&animal);

    if(dogPtr != nullptr) {
        dogPtr->bark();
    } else {
        throw std::invalid_argument("Excepted a Dog");
    }
}

void processAnimal(Animal& animal) {
    try {
        requireDog(animal);
    } catch(const std::exception& e) {
        std::cout << "Process: " << e.what() << std::endl;
        throw;
    }
}

int main() {

    Dog dog;
    Cat cat;

    try {
        processAnimal(dog);
    } catch(const std::invalid_argument& e) {
        std::cout << "Main: " << e.what() << std::endl;
    }
    std::cout << "Continue" << std::endl;

    try {
        processAnimal(cat);
    } catch(const std::invalid_argument& e) {
        std::cout << "Main: " << e.what() << std::endl;
    }
    std::cout << "Continue" << std::endl;

    return 0;
}