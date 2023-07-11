#include "../include/iter.hpp"
// class Awesome {
// 	public:
// 		Awesome(void) : _n(42) { return; }
// 		int get(void) const { return this->_n; }

// 	private:
// 		int _n;
// };

// std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
// {
// 	o << rhs.get();
// 	return o;
// }

int main()
{
    // Awesome tab[5];
	int arr[5] = {1, 2, 3, 4, 5};
	std::string phrase[5] = {"hi", "this", "is", "a", "test"};
	float coucou[10] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	// std::cout << "Starting iter with int class Awesome being sent to print function:" << std::endl;
    // iter(tab, 5, print);

	std::cout << "\nStarting iter with int array being sent to print function:" << std::endl;
	iter(arr, 5, print);
	
	std::cout << "\nStarting iter with string array being sent to print function:" << std::endl;
	iter(phrase, 5, print);

	std::cout << "\nStarting iter with float array being sent to print function:" << std::endl;
	iter(coucou, 10, print);


    return 0;
}