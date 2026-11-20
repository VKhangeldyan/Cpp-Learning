#include <iostream>

struct Animal;

struct AnimalVTable {
    void (*speak)(const Animal* self);
    void (*describe)(const Animal* self);
};

struct Animal {
    const AnimalVTable* vptr;
    int age;
};

void dogSound(const Animal* self) {
     std::cout << "Woof, age: " << self->age << '\n';
}

void catSound(const Animal* self) {
    std::cout << "Meow, age: " << self->age << '\n';
}

void dogDescribe(const Animal* self) {
    std::cout << "Dog, age: " << self->age << '\n';
}

void catDescribe(const Animal* self) {
    std::cout << "Cat, age: " << self->age << '\n';
}

void makeSound(const Animal& animal) {
    animal.vptr->speak(&animal);
}

void describeAnimal(const Animal& animal) {
    animal.vptr->describe(&animal);
}

int main() {

   const AnimalVTable dogTable{&dogSound, &dogDescribe};
   const AnimalVTable catTable{&catSound, &catDescribe};

   Animal dog{&dogTable, 20};
   Animal cat{&catTable, 19};

   makeSound(cat);
   makeSound(dog);

   describeAnimal(dog);
   describeAnimal(cat);

   return 0;

}