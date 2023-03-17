#ifndef YELLOWPAGES_H
# define YELLOWPAGES_H

# include "Contacts.hpp"

class Phonebook {

	public:

	Phonebook(void);
	~Phonebook(void);

	// Getters and setters
	void		getContact(void) const;
	void		setContact(void);
	
	void		addContact(void);
	void		searchContact(void) const;
	void		getIndex(void) const;

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

• ADD : enregistrer un nouveau contact
◦ Si l’utilisateur entre cette commande, le programme lui demande de remplir
une par une les informations du nouveau contact. Une fois tous les champs
complétés, le nouveau contact est ajouté au répertoire.
◦ Un contact possède les champs suivants : first name (prénom), last name
(nom de famille), nickname (surnom), phone number (numéro de téléphone),
et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne
peuvent être vides.

• SEARCH : affiche le contact demandé
◦ Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
first name, last name et nickname.
◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
un point (’.’).
◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
Sinon, affichez les informations du contact, une par ligne.
• EXIT
◦ Le programme quitte et les contacts sont perdus à jamais !

*/