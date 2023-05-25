#ifndef DATA_HPP
#define DATA_HPP

#pragma once

#include <iostream>
#include <string>

typedef struct {
    std::string obj;
} Data;

uintptr_t serialize(Data* ptr);        // converts Data *ptr to uintptr_t
Data*     deserialize(uintptr_t raw);  // converts uintptr_t raw to a Data*

#endif