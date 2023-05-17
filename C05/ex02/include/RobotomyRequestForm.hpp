#pragma once

#include "../include/AForm.hpp"

// Class declaration
class RobotomyRequestForm : public AForm {
 public:
 RobotomyRequestForm(string target);
  ~RobotomyRequestForm();

 void execute(Bureaucrat const& executor) const;

 private:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};
