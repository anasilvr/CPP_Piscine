#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

#define DEBUG_MSG "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n"

#define INFO_MSG "I cannot believe adding extra bacon costs more money.\n\
You didn't put enough bacon in my burger!\n\
If you did, I wouldn't be asking for more!\n"

#define WARN_MSG "I think I deserve to have some extra bacon for free.\n\
I've been coming for years whereas you started working here since last month.\n"

#define ERROR_MSG  "This is unacceptable ! I want to speak to the manager now.\n"

class Harl {
	public:
		Harl( void );
		~Harl( void );
	
		void complain( std::string id );
		
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};

typedef  void (Harl::*funcPtr[4])(void);

#endif /* HARL_HPP */