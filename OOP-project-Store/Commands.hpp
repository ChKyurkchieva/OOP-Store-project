#include"Store.hpp"

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

bool open(fstream& command)
{
	command.open("storeTextDocument.txt", ios::app);
	if (!command.is_open()) {

		std::cout << "Can not open the file!"<<endl;
		return false;
	}
	cout << "The file was succesfully opened!" << endl;
	return true;
}

bool close(fstream& stream)
{
	if (stream.is_open())
	{
		stream.close();
		cout << "Succesfully closed this file!" << endl;
		return true;
	}
	cout << "This command was unsuccesfull!" << endl;
	return false;
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
