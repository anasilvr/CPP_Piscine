#include "include/Data.hpp"

#define GRN "\e[0;32m"
#define NC "\e[0m"

uintptr_t serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}

int main(void) {
    uintptr_t a = 0;
    Data      b;

    std::cout << GRN "Printing initial data" NC << std::endl;
    std::cout << "uintptr_t a = " << a << std::endl;
    std::cout << "b.obj = " << b.obj << std::endl;

    std::cout << GRN
        "\nPrinting data once b.obj is set to \"Ana\" and a is the serialized "
        "version of Data*" NC
              << std::endl;
    b.obj = "Ana";

    a = serialize(&b);
    std::cout << "uintptr_t a = " << a << std::endl;
    std::cout << "b.obj = " << b.obj << std::endl;

    std::cout << GRN
        "\nCreating new Data* called test and setting it to the return of "
        "deserialization(uintptr_t a)" NC
              << std::endl;
    Data* test = deserialize(a);
    std::cout << "b address is: " << &b << std::endl;
    std::cout << "b.obj = " << b.obj << std::endl;
    std::cout << "test address is: " << test << std::endl;
    std::cout << "test->obj = " << test->obj << std::endl;
}