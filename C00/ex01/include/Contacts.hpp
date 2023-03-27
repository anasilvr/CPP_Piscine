#ifndef CONTACTS_H
# define CONTACTS_H

# include <string>

class Contacts {

	public:
	Contacts(void);
	~Contacts(void);

	//Getters
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhonenumber(void) const;
	std::string getDarkerstSecret(void) const;
	//Setters
	void setFirstName(std::string name);
	void setLastName(std::string name);
	void setNickname(std::string name);
	void setPhonenumber(std::string number);
	void setDarkestSecret(std::string secret);

	private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestSecret;
};

#endif // CONTACTS_H