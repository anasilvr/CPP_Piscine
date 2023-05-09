#include "../include/YellowPages.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook(void) : _index(0) { return; }

Phonebook::~Phonebook(void) {
	std::cout << "\e[3m* THUD *\e[0m" << std::endl;
	return;
}

/*• ADD : enregistrer un nouveau contact
◦ Si l’utilisateur entre cette commande, le programme lui demande de remplir
une par une les informations du nouveau contact. Une fois tous les champs
complétés, le nouveau contact est ajouté au répertoire.
◦ Un contact possède les champs suivants : first name (prénom), last name
(nom de famille), nickname (surnom), phone number (numéro de téléphone),
et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne
peuvent être vides.*/


void	Phonebook::addContact(void)
{
	this->_index %= 8;
	std::cout << "\n\e[1m[ Adding new contact ]\e[0m" << std::endl;
	setContact();
	this->_index++;
	std::cout << "\e[1m[ Contact added to your phonebook ]\e[0m\n" << std::endl;

}

/*• SEARCH : affiche le contact demandé
◦ Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
first name, last name et nickname.
◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
un point (’.’).
◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher.
Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
Sinon, affichez les informations du contact, une par ligne.*/

void	Phonebook::searchContact(void) const
{
	int	input = 0;
	std::string nb;

	std::cout << "\nHere's your contact list.\nType a valid contact index to see more, or -1 to return to the main menu." << std::endl;
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1) << "|";
			this->displaySearch(this->_contact[i].getFirstName());
			this->displaySearch(this->_contact[i].getLastName());
			this->displaySearch(this->_contact[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	while (input != -1)
	{
		std::cout << "Index: ";
		std::cin >> nb;
		if (std::cin.eof())
			break ;
		try {
			input = stoi(nb);
		}
		catch (...)
		{
			std::cout << "Index should be a number." << std::endl;
		}
		if (input > 0 && input <= 8 && input <= this->getIndex())
		{
			std::cout << "\t\nFound it! Here's your contact information:\n" << std::endl;
			this->printContact(this->_contact[input - 1]);
			break ;
		}
		if (input != -1)
			std::cout << "Try again or type -1 to return to the main menu.\n" << std::endl;
	}
	std::cout << "\t\nReturning to the the main menu.\n" << std::endl;
}

int	Phonebook::getIndex(void) const
{
	return (this->_index);
}

void Phonebook::displaySearch(std::string data) const
{
	if (data.length() > 10)
		std::cout << data.substr(0, 9).append(".") << "|";
	else
		std::cout << std::setw(10) << data << "|";
}

void Phonebook::printContact(Contacts _contact) const
{
	std::cout << "\e[1m\tFirst Name:\e[0m " << _contact.getFirstName() << std::endl;
	std::cout << "\e[1m\tLast Name:\e[0m " << _contact.getLastName() << std::endl;
	std::cout << "\e[1m\tNickname:\e[0m " << _contact.getNickname() << std::endl;
	std::cout << "\e[1m\tPhone Number:\e[0m " << _contact.getPhonenumber() << std::endl;
	std::cout << "\e[1m\tDarkset Secret:\e[0m " << _contact.getDarkerstSecret() << std::endl;
	return ;
}

void	Phonebook::setContact(void)
{
	std::string input;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	while (input.empty())
	{
		std::cout << "\e[1m\tFirst Name:\e[0m "<< std::flush;
		std::getline(std::cin, input, '\n');
		this->_contact[this->_index].setFirstName(input);
	} input.clear();
	while (input.empty())
	{
		std::cout << "\e[1m\tLast name:\e[0m "<< std::flush;
		std::getline(std::cin, input, '\n');
		this->_contact[this->_index].setLastName(input);
	} input.clear();
	while (input.empty())
	{
		std::cout << "\e[1m\tNick name:\e[0m "<< std::flush;; 
		std::getline(std::cin, input, '\n');
		this->_contact[this->_index].setNickname(input);
	} input.clear();
	while (input.empty())
	{
		std::cout << "\e[1m\tPhone Number:\e[0m "<< std::flush;; 
		std::getline(std::cin, input, '\n');
		this->_contact[this->_index].setPhonenumber(input);
	} input.clear();
	while (input.empty())
	{
		std::cout << "\e[1m\tDarkest Secret:\e[0m "<< std::flush;; 
		std::getline(std::cin, input, '\n');
		this->_contact[this->_index].setDarkestSecret(input);
	} input.clear();
}