#include "../include/Contacts.hpp"
#include <iostream>
#include <iomanip>

Contacts::Contacts(void) { return; }
Contacts::~Contacts(void) { return; } 

// Getters
std::string Contacts::getFirstName() const { return (this->_firstName); }
std::string Contacts::getLastName() const { return (this->_lastName); }
std::string Contacts::getNickname() const { return (this->_nickname); }
std::string Contacts::getPhonenumber() const { return (this->_phonenumber); }
std::string Contacts::getDarkerstSecret() const { return (this->_darkestSecret); }

// Setters
void Contacts::setFirstName(std::string name) {
	this->_firstName = name;
	return;
}

void Contacts::setLastName(std::string name) {
	this->_lastName = name;
	return;
}

void Contacts::setNickname(std::string name) {
	this->_nickname = name;
	return;
}

void Contacts::setPhonenumber(std::string name) {
	this->_phonenumber = name;
	return;
}

void Contacts::setDarkestSecret(std::string name) {
	this->_darkestSecret = name;
	return;
}