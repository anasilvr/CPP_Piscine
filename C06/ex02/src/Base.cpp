#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

// Default destructor
Base::~Base() { return; }

// randomly instanciates A, B or C and returns the instance as a Base pointer
Base	*generate(void) {
	srand((time(NULL)));
	int type = rand() % 3;
	std::cout << "Possible types:\n\t0 = A\n\t1 = B\n\t2 = C" << std::endl;
	std::cout << "Type generated: " << type << std::endl;
	
	Base *test;
	
	switch(type) {
		case 0:
			test = new A();
			break ;
		case 1:
			test = new B();
			break ;
		case 2:
			test = new C();
			break ;
	}
	return (test);
};

// prints the actual type of the object pointed to by p ("A", "B" or "C")
void	identify(Base* p) {
	std::cout << "Identifying *p:" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "ID failed." << std::endl;
}

void	identify(Base& p)  {
	std::cout << "Identifying &p:" << std::endl;
	try {
		if (dynamic_cast<A*>(&p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "C" << std::endl;
	}
	catch(const std::bad_cast& e){
		std::cerr << "e.what(): " << e.what() << std::endl;
	}
}