#include "../include/MutantStack.hpp"

void	message(std::string s) { std::cout << s << std::endl; }
void	print_stack(MutantStack<int> s, MutantStack<int>::iterator start, MutantStack<int>::iterator end) {
	std::cout << GRN "size: " << s.size() << " | content: ";
	while (start != end) {
        std::cout << *start << " ";
        ++start;
    }
	std::cout << NC << std::endl;
}

int main()
{
    MutantStack<int> mstack;
	message("Starting stack");
	print_stack(mstack, mstack.begin(), mstack.end());
    mstack.push(5);
    mstack.push(17);
	message("\nStack after push 5 and push 17");
	print_stack(mstack, mstack.begin(), mstack.end());
    mstack.pop();
	message("\nStack after one pop");
    print_stack(mstack, mstack.begin(), mstack.end());
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
	message("\nStack after more pushes (3 5 737 0)");
    print_stack(mstack, mstack.begin(), mstack.end());
	std::cout << "Testing iterators: " << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
	std::cout << "Stack content: " << std::endl;
    while (it != ite) { // same as calling print_stack
        std::cout << *it << std::endl;
        ++it;
    }
	message("Copying mstack to create newstack");
	MutantStack<int> newstack = mstack;
	std::cout << "mstack: ";
	print_stack(mstack, mstack.begin(), mstack.end());
	std::cout << "newtack: ";
	print_stack(newstack, newstack.begin(), newstack.end());
    return 0;
}
