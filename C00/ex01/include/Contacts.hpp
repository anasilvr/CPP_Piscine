#ifndef CONTACTS_H
# define CONTACTS_H

# include <string>

class Contacts {

	public:

	Contacts(void);
	~Contacts(void);

	std::string getFirstName(void) const;
	std::string getLasttName(void) const;
	std::string getNickname(void) const;
	std::string getPhonenumber(void) const;
	std::string getDarkerstSecret(void) const;
	
	void setFirstName(std::string fname);
	void setLastName(std::string lname);
	void setNickname(std::string nname);
	void setsetPhonenumber(std::string number);
	void setDarkestSecret(std::string secret);


	private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestSecret;
};

#endif

/*
• Contact
◦ Représente un contact dans le répertoire.
*/