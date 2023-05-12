#include "../include/Brain.hpp"

// Default constructor
Brain::Brain() {
    cout << "\t[Default]\tBrain created.\n";
}

// Copy constructor
Brain::Brain(const Brain &other) {
    *this = other;
    cout << "\t[Copy]\tBrain created.\n";
    return;
}

// Copy assignment overload
Brain &Brain::operator=(const Brain &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) this->_ideas[i] = rhs._ideas[i];
    }
    return *this;
}

// Default destructor
Brain::~Brain() {
    cout << "\tBrain destroyed.\n";
}