#pragma once

#include "../include/AForm.hpp"

// Class declaration
class PresidentialPardonForm : public AForm {
 public:
 PresidentialPardonForm(string target);
  ~PresidentialPardonForm();

 void execute(Bureaucrat const& executor) const;

 private:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
};
