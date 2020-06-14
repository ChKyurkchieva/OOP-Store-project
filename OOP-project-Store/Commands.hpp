#include"Store.hpp"

const int MAX_SIZE = 20;

void help()
{
	cout << "If you want to open new text document, please press 1." << endl;
	cout << "If you want to open document with a specific name, please press 2." << endl;
	cout << "If you want to close the current file, please press 3." << endl;
	cout << "If you want to save the current information, please press 4." << endl;
	cout << "If you want to save the current information in a specific file," << endl;
	cout << "please press 5." << endl;
	cout << "If you want to 'shut down' this program, please press 6."<<endl;
	cout << "If you want to see this instructions again, please 7." << endl;
}

void open(ofstream& command)
{
	command.open("storeTextDocument.txt", ios::app);
	if (!command.is_open()) {

		std::cout << "Can not open the file!"<<endl;
	}
	cout << "The file was succesfully opened!" << endl;
}

void openFile(ofstream& command, const char* fileName)
{
	command.open(fileName, ios::app);
	if (!command.is_open()) {

		std::cout << "Can not open the file!" << endl;
	}
	cout << "The file was succesfully opened!" << endl;
}

void close(ofstream& stream)
{
	if (stream.is_open())
	{
		stream.close();
		cout << "Succesfully closed this file!" << endl;
	}
	cout << "This command was unsuccesfull!" << endl;
}

void save(const char* fileName, Store& myStore)
{
	ofstream out(fileName);
	out.exceptions(ifstream::failbit | ifstream::badbit | ifstream::eofbit);
	myStore.printInFile(out);
}

void saveAs(const char* fileName, Store& myStore)
{
	save(fileName, myStore);
}

void testDateandProduct()
{
	Date date(1, January, 2020);
	Date newDate(20, February, 2021);
	date = newDate;
	Date p = date;
	//cout << date.isLater(newDate);
	//p.print();
	bool measure = 0;
	unsigned amount = 10;
	Product product1("Milk", "MilkTrade", "To be located properly!", date, newDate, measure, amount);
	Product product2("Peper", "Me", "To de located properly!", date, newDate, measure, amount);
	//product1.print();
	cout << endl;
	//product2.print();
	cout << endl;
	//product1 = product2;
	//product1.print();
	Product product3 = product1;
	//product3.print();

	Store mystore(2);

	mystore.add(product1);
	mystore.add(product3);
	mystore.add(product2);
	mystore.print();
	cout << endl;
	mystore.remove(product3);
	mystore.print();
}

void testFiles()
{
	Date date(20, March, 2000);
	bool measure = 0;
	unsigned amount = 10;
	Product product1("Milk", "MilkTrade", "To be located properly!", date, date, measure, amount);
	ofstream myfile;
	myfile.open("example.txt");
	date.printInFile(myfile);
	myfile << endl;
	product1.printInFile(myfile);
	Product product2("Peper", "Me", "To de located properly!", date, date, measure, amount);
	//product1.print();
	myfile << endl;
	//product2.print();
	myfile << endl;
	//product1 = product2;
	//product1.print();
	Product product3 = product1;
	//product3.print();

	Store mystore(2);

	mystore.add(product1);
	mystore.add(product3);
	mystore.add(product2);

	save("test", mystore);

	myfile.close();
}

Store& store()
{
	Date date(1, January, 2020);
	Date newDate(20, February, 2021);
	Date newDate1(2, February, 2020);
	bool measure = 0;
	unsigned amount = 100;
	Product product1("Milk", "MilkTrade", "Use before the expiration date!", date, newDate, measure, amount);
	Product product2("Peper", "Bulgaria", "To de located properly!", date, newDate1, measure = 1, amount);
	Product product3("Tomato", "Bulgaria", "To de located properly!", date, newDate1, measure = 1, amount);
	Product product4("Apple", "Bulgaria", "To de located properly!", date, newDate1, measure = 1, amount);
	Product product5("Pear", "Bulgaria", "To de located properly!", date, newDate1, measure = 1, amount);
	Product product6("Grapes", "Bulgaria", "To de located properly!", date, newDate1, measure = 1, amount);
	Product product7("Beer", "Burgas", "Use before the expiration date!", date, newDate, measure, amount);
	Product product8("Whiskey", "Jack Daniels", "Use before the expiration date!", date, newDate, measure, amount);
	Product product9("Water", "Devin", "Use before the expiration date!", date, newDate, measure, amount);
	Store mystore(1);
	mystore.add(product1);
	mystore.add(product2);
	mystore.add(product3);
	mystore.add(product4);
	mystore.add(product5);
	mystore.add(product6);
	mystore.add(product7);
	mystore.add(product8);
	mystore.add(product9);
	mystore.print();
	return mystore;
}

void validateComand(char* command)
{
	bool isValidCommand = (strcmp(command, "open") == 0 || strcmp(command, "open/") == 0 ||
		strcmp(command, "save") == 0 || strcmp(command, "saveAs") == 0 ||
		strcmp(command, "close") == 0 || strcmp(command, "exit") == 0 ||
		strcmp(command, "help") == 0);
	cout << isValidCommand;
	while (!(isValidCommand))
	{
		if (!isValidCommand)
		{
			cout << "Please input a valid command, if you want to continued using the store properly!" << endl;
		}
		cin >> command;
	}
}

void firstCommandString(ofstream& fileStream, char* command)
{
	while (!(fileStream.is_open()))
	{
		cin >> command;
		if (strcmp(command, "open") == 0)
		{
			open(fileStream);
			break;
		}
		else if (strcmp(command, "open/") == 0)
		{
			char* fileName = new (nothrow)char[MAX_SIZE];
			cin >> fileName;
			openFile(fileStream, fileName);
			delete[]fileName;
			fileName = nullptr;
			break;
		}
		else if (strcmp(command, "help") == 0)
		{
			cout << endl;
			help();
			cout << endl;
		}
		else if (strcmp(command, "exit") == 0)
		{
			return;
		}
		else if (strcmp(command, "close") == 0 || strcmp(command, "save") == 0 ||
			strcmp(command, "saveAs") == 0)
		{
			cout << "Please, use a valid command! You don't have opened file!" << endl;
		}
	}
}

void firstCommand(ofstream& fileStream, int command)
{
	while (command < 1 || command>7)
	{
		cin >> command;
	}
	while (!fileStream.is_open())
	{
		switch (command)
		{
		case 1:
		{
			open(fileStream); break;
		}
		case 2:
		{
			char* fileName = new(nothrow) char[MAX_SIZE];
			cout << "Please, input filename." << endl;
			cin >> fileName;
			openFile(fileStream, fileName);
			delete[] fileName;
			break;
		}
		case 3:
		{
			cout << "Unvalid command! You didn't open a file!" << endl; break;
		}
		case 4:
		{
			cout << "Unvalid command! You didn't open a file!" << endl; break;
		}
		case 5:
		{
			cout << "Unvalid command! You didn't open a file!" << endl; break;
		}
		case 6:
		{
			cout << "Exiting the program!"; return;
		}
		case 7:
		{
			help(); break;
		}
		}
		if (command >= 3 && command <= 7 && command != 6)
		{
			if (command != 7)
			{
				cout << "Please input a valid command!" << endl;
			}
			else
			{
				cout << "Please input new command!" << endl;
			}
			cin >> command;
		}
	}
}

void command(ofstream& fileStream, const char* fileName, Store& myStore, int command)
{
	if (fileStream.is_open())
	{
		while (command < 1 || command > 7)
		{
			cin >> command;
		}
		switch (command)
		{
		case 1:
		{
			open(fileStream); break;
		}
		case 2:
		{
			char* fileName = new(nothrow) char[MAX_SIZE];
			cout << "Please, input filename." << endl;
			cin >> fileName;
			openFile(fileStream, fileName);
			delete[] fileName;
			break;
		}
		case 3:
		{
			close(fileStream); break;
		}
		case 4:
		{
			save(fileName, myStore); break;
		}
		case 5:
		{
			save(fileName, myStore); break;
		}
		case 6:
		{
			help(); break;
		}
		}
	}
	else
	{
		cout << "Please open a file!" << endl;
	}
}

void addNewProduct(Store& myStore)
{
	char* name = new(nothrow)char[MAX_SIZE];
	cout << "Please, input a name of the product!" << endl;
	cin >> name;
	cout << "Please, input a name of the producer!" << endl;
	char* producer = new(nothrow)char[MAX_SIZE];
	cin >> producer;
	cout << "Please, input a comment!" << endl;
	char* comment = new(nothrow)char[MAX_SIZE];
	cin >> comment;
	unsigned day=0;
	unsigned year=0;
	Month month;
	cout << "Please input a acceptance date!" << endl;
	cout << "Day: ";
	cin >> day;
	cout << endl;
	cout << " Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;
	Date acceptanceDate(day, month, year);
	cout << "Please input a expiry date!" << endl;
	cout << "Day: ";
	cin >> day;
	cout << endl;
	cout << " Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;
	Date expiryDate(day, month, year);
	if (expiryDate.isLater(acceptanceDate))
	{
		unsigned amount;
		do 
		{
			cout << "Please input the amount of the product!";
			cin >> amount; 
		} while (amount <= 0);
		bool measure;
		do
		{
			cout << "Please input the measure of the product! If it is a liquid, press 0. Otherwise, press 1. " << endl;
			cin >> measure;
		} while (measure != 1 || measure != 0);
		Product newProd(name, producer, comment, acceptanceDate, expiryDate, measure, amount);
		myStore.add(newProd);
	}
	else
	{
		cout << "The product can't be created due to unvalid input! " << endl;
	}
	delete[] name;
	delete[] producer;
	delete[] comment;
}

void run()
{
	cout << "           Welcome in our store!";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Let's take a look at the contents of the store first! " << endl;
	cout << endl;
	store();
	cout << endl;
	cout << "We are a Bulgarian company, but our owner is a foreigner, so we want everything to happen legally." << endl;
	cout << "Therefore, any change in the contents of the store must be kept somewhere." << endl;
	cout << endl;
	help();
	cout << endl;
	cout << "We suggest you using the open and open/file commands before starting work in the store." << endl;
	int command;
	cin >> command;//i have validation of the input, but it doesn't work; theoritically it have to, in practice it doesn't
	ofstream fileStream;
	firstCommand(fileStream, command);
	unsigned action;
	if (fileStream.is_open())
	{
		Store myStore=store();
		do
		{
			cout << "If you want to add new product, please press 1." << endl;
			cout << "If you want to make changes in the store, please press 2" << endl;
			cout << "If you want to exit the program, please press 3" << endl;
			cin >> action;
		} while (action < 1 || action>3);
		switch (action)
		{
			case 1:
			{
				addNewProduct(myStore); break;
				myStore.print();
				myStore.printInFile(fileStream);
			}
			case 2:
			{
				do
				{
					cout << "If you want to add a product, press 1." << endl;
					cout << "If you want to clean the store, press 2." << endl;
					cin >> action;
				} while (action < 1 || action>3);
				if (action == 1)
				{
					addNewProduct(myStore);
				}
				else
				{
					unsigned day = 0;
					unsigned year = 0;
					Month month;
					cout << "Please input a expiry date!" << endl;
					cout << "Day: ";
					cin >> day;
					cout << endl;
					cout << " Month: ";
					cin >> month;
					cout << "Year: ";
					cin >> year;
					Date expiryDate(day, month, year);
					myStore.cleanFromStore(expiryDate);
					myStore.print();
					myStore.printInFile(fileStream);
				}
			}
			case 3:
			{
				cout << "Exiting program!" << endl;
				return;
			}
		}
	}
	else
	{
		firstCommand(fileStream, command);
	}
}