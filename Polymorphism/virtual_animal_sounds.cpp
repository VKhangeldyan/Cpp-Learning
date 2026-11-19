#include <iostream>

class Animal {
   public:
       virtual void speak() const {
          std::cout << "Animal sound" <<std::endl;
       }

       virtual ~Animal() {
         std::cout << "Animal destructor" <<std::endl;
       }

};

class Dog : public Animal {
   public:
      void speak() const override {
         std::cout << "Woof" << std::endl;
      }

      ~Dog() override {
        std::cout << "Dog destructor" <<std::endl;
      }
};

class Cat : public Animal {
   public:
      void speak() const override {
         std::cout << "Meow" <<std::endl;
      }

      ~Cat() override {
         std::cout << "Cat destructor" <<std::endl;
      }
};

void makeSound(const Animal& animal) {
    animal.speak();
}

int main() {

    Dog dog;
    Cat cat;

    makeSound(dog);
    makeSound(cat);

    return 0;
} 