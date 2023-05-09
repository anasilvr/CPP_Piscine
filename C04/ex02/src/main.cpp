#include <iostream>
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

#define REDHB "\e[0;101m"

int main ()
{
	//AAnimal *animal = new AAnimal() // WON'T COMPILE
    AAnimal *animal = new Cat(); // COMPILES
    animal->makeSound();
    return 0;
}