# CPP-Modules
These are 42's modules to learn C++ concepts

## C++ Module 00

This is an introductory module to get familiarized with the C++ language.

### ex00

Here we get introduced to objects, objects data fields, much like structs that can store variables, these are called attributes, also like structs, objects can have functions, these are called methods, different from structs, classes allow us to encapsulate behaviour and abstract complexity (more on that on the next modules).
In this exercise I used ```cout``` which is an object that describes the console output.

This is what the subject assigned to me:

Write a program that produces the this behaviour:
```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

This is quite simple, we just traverse the strings of passed by the command line arguments, check if there are lowercase characters, if so, turn them uppercase.

### ex01

In this exercise we learn more about classes, a class is sort of a blueprint or template, for an object.
A class definition is more or less like this:
```
class	myClass
{
	private:
		/*Private atributes or methods*/

	public:
		myClass();		//constructor
		~myClass();		//desctructor

		/*Public atributes or methods*/
}
```
Wether a method/attribute is private or public, it up to you, but, in standard, function members that are only accessed inside the class should be private, this allows encapsulation, and other members can be public.
Another concept that need to be talked about are constructors and destructors, basically a constructor is what the object should do when is ```instantiated```, you can leave as it is if you don't intend to do anything when is the object is instantiated, but the most common practice is atributes that you will need right after the instantiation.

For this exercise it was asked to implement a Phonebook.
This phonebook will have an array of contacts, A contact is also another class, we are allowed to implement this class as we want, but anything that will always be used inside a class is private, and that anything that can be
used outside a class is public.

The subject says a lot of stuff but in short, it asks for the Phonebook, it needs to do 3 things:
* Add a contact with its first name, last name, nickname, phone number and darkest secret.
* Search a contact, based on its index, it will display the contact inside a table with 4 columns: index, first name, last name and nickname, each column is 10 characters wide.
* Exit.

And finnaly, if the user adds a 9th contact, it should switch the oldest one with the one that is the current contact.

This is the class definition for Phonebook:
```
class PhoneBook
{
	private:
		int			index;
		int			is_full;
		Contact			contacts[8];
		void			getContactInfo(int index);

	public:
		PhoneBook();
		~PhoneBook();

		void			add(void);
		void			search(void);
		void			exiting(void);
};
```
`index` is to keep track of the current contact slot, `is_full` as the name says, is to check if the contact array is full, finally, the `getContactInfo(int index)` is a method is to print the contact info.

This is the class definition for `Contact`:
```
class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	phone_number;
		std::string	nickname;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();

		std::string	&getFirstName(void);
		std::string	&getLastName(void);
		std::string	&getPhoneNumber(void);
		std::string	&getNickname(void);
		std::string	&getDarkestSecret(void);

		void		setNickname(std::string str);
		void		setLastName(std::string str);
		void		setFirstName(std::string str);
		void		setPhoneNumber(std::string str);
		void		setDarkestSecret(std::string str);
};
```
And all these methods, are getters and setters, I think they are self explanatory, but basically are methods to access and change private attributes, it can seem redundant to create functions to access and modify a class variable, but this is the point of encapsulation, and if the getters and setters are well implemented, to ensure that variables are always accessed as intended and safely managed.

```
int	main(void)
{
	PhoneBook	phonebook;
	std::string		input;
	
	std::cout	
				<< "\033[33mWrite your command, [ADD, SEARCH, EXIT]\033[0m" << 
	std::endl; 
	while (1 && getline(std::cin, input))
	{
		if (strtrim(input) == "ADD")
			phonebook.add();
		else if (strtrim(input) == "SEARCH")
			phonebook.search();
		else if (strtrim(input) == "EXIT")
			phonebook.exiting();
		else if (std::cin.eof())
			phonebook.exiting();
		else
			std::cout << "Invalid command! Try again." << std::endl;
		std::cout
					<< "\033[33mWrite your command, [ADD, SEARCH, EXIT]\033[0m" <<
		std::endl; 
	}
	return (0);
}
```
This is my main, here I use `getline` to get the user's input directly from the command line.


