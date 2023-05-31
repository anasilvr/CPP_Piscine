#include "../include/iter.hpp"

// int main (void) {
// 	int arr[5] = {1, 2, 3, 4, 5};
// 	std::string phrase[5] = {"hi", "this", "is", "a", "test"};
// 	float glub[10] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

// 	std::cout << "Starting iter with int array being sent to print function:" << std::endl;
// 	iter(arr, 5, print);
// 	std::cout << "\nStarting iter with string array being sent to print function:" << std::endl;
// 	iter(phrase, 5, print);
// 	std::cout << "\nStarting iter with float array being sent to print function:" << std::endl;
// 	iter(glub, 10, print);
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}