#ifndef YELLOWPAGES_H
# define YELLOWPAGES_H

# include "Contacts.hpp"

class Phonebook {

	public:

	Phonebook(void);
	~Phonebook(void);

	// Getters and setters
	void setContact(void);

	void addContact(void);
	void searchContact(void) const;
	
	void displaySearch(std::string data) const;
	void printContact(Contacts _contact) const;

	int			getIndex(void) const;

	private:

	int			_index;
	Contacts	_contact[8];
};

#endif



/*
PhoneBook
◦ Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite.
*/