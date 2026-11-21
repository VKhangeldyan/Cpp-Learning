#include <iostream>
#include <stdexcept>

void ordinary() {
    std::cout << "Inside ordinary" << std::endl;

    throw std::runtime_error("Ordinary failed");
}

void handledInside() noexcept {
    try {
        throw std::runtime_error("Handled inside");
    } catch(const std::exception& e) {
        std::cout << "Inner caught: " << e.what() << std::endl;
    }

    std::cout << "handledInside finished" << std::endl;
}

void escapes() noexcept {
    std::cout << "Inside escapes" << std::endl;
    ordinary();
}

int main() {

   std::cout << "ordinary: " << noexcept(ordinary()) << std::endl;
   std::cout << "handledInside: " << noexcept(handledInside()) << std::endl;
   std::cout << "escapes: " << noexcept(escapes()) << std::endl;

   try {
    ordinary();
   } catch(const std::exception& e) {
    std::cout << "Main caught: " << e.what() << std::endl;
   }

   handledInside();

   std::cout << "Main continues" << std::endl;

   try {
    escapes();
   } catch(const std::exception& e) {
    std::cout << "Outer caught: " << e.what() << std::endl;
   }
   std::cout << "After escapes" << std::endl; 

   return 0;
}