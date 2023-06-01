#include "../include/Array.hpp"

#define W  "\e[0;107m"
#define NC "\e[0m"

int main()
{
    std::cout << W "\ntest1: default constructor" NC << std::endl;
    try {
        Array<int> test1;
        std::cout << "test1 size: " << test1.size() << std::endl;
        std::cout << "test1 content: " << std::endl;
        for (unsigned int i = 0; i < test1.size(); i++)
            std::cout << "\t[" << i << "] " << test1[i] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << W "\ntest2: parametric constructor (n = -1)" NC << std::endl;
    try {
        Array<int> test2(-1);
        std::cout << "test2 size: " << test2.size() << std::endl;
        std::cout << "test2 content: " << std::endl;
        std::cout << "\t[" << 0 << "] " << test2[0] << std::endl;
        std::cout << "\t["
                  << "4294967295"
                  << "] " << test2[-2] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << W "\ntest3: parametric constructor (n = 10)" NC << std::endl;
    try {
        Array<int> test3(10);
        for (unsigned int i = 0; i < 5; i++)
            test3[i] = i;
        std::cout << "test3 size: " << test3.size() << std::endl;
        std::cout << "test3 content: " << std::endl;
        for (unsigned int i = 0; i < test3.size(); i++)
            std::cout << "\t[" << i << "] " << test3[i] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << W "\ntest4: copy constructor" NC << std::endl;
    try {
        Array<int> test4(10);
        for (unsigned int i = 0; i < 10; i++)
            test4[i] = i;
        Array<int> test4copy = test4;
        Array<int> anothercopy(test4copy);
        Array<int> lastcopy;
        lastcopy = anothercopy;
        std::cout << "test4 size: " << test4.size() << std::endl;
        std::cout << "test4copy size: " << test4copy.size() << std::endl;
        std::cout << "anothercopy size: " << anothercopy.size() << std::endl;
        std::cout << "lastcopy size: " << lastcopy.size() << std::endl;

        std::cout
            << "test4 content and addresses:\t\ttest4copy content and "
               "addresses\t\tanothercopy\t\t\t\tlastcopy content and addresses"
            << std::endl;
        for (unsigned int i = 0; i < test4.size(); i++) {
            std::cout << "[" << i << "] " << test4[i] << &test4[i];
            std::cout << "\t\t\t[" << i << "] " << test4copy[i]
                      << &test4copy[i];
            std::cout << "\t\t\t[" << i << "] " << anothercopy[i]
                      << &anothercopy[i];
            std::cout << "\t\t\t[" << i << "] " << lastcopy[i] << &lastcopy[i]
                      << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << W "\ntest5: Out of bounds exception" NC << std::endl;
    try {
        Array<int> test5(3);
        for (unsigned int i = 0; i < 3; i++)
            test5[i] = i;
        std::cout << "test5 size: " << test5.size() << std::endl;

        std::cout << test5[4];
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << W "\ntest6: ?!" NC << std::endl;
    try {
        int *a = new int();
        std::cout << *a << std::endl;
        delete a;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}