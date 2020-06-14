#include"Commands.hpp"
const int MAX_SIZE = 20;

void testDateandProduct()
{
	Date date(1,January,2020);
	Date newDate(20,February, 2021);
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
	Date date(20,March, 2000);
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

void store()
{
	Date date(1,January, 2020);
	Date newDate(20,February, 2021);
	Date newDate1(2,February, 2020);
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

int main()
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
	char* command = new(nothrow)char[MAX_SIZE];
	cin >> command;
	

	
	system("pause");
	return 0;
}