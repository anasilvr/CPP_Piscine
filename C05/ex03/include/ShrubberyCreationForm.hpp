#pragma once

#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>

// Class declaration
class ShrubberyCreationForm : public AForm {
 public:
 ShrubberyCreationForm(string target);
  ~ShrubberyCreationForm();

 void execute(Bureaucrat const& executor) const;

 private:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};
