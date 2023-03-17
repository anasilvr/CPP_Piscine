#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample1 {
	public:

		const float	pi; // attribute
		int		sq;

		Sample1(const float nb); //constructor
		~Sample1(void); // destructor

		void print_att(void) const; // member function
};

#endif