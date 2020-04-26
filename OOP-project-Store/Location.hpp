using std::cout;
using std::cin;
using std::endl;
using std::ostream;
class Location
{
	int section;
	int	shelf;
	int number;
public:
	Location();
	Location(int section, int shelf, int number);

	void print()const;
	friend ostream& operator<<(ostream& os, const Location& location);
};

Location::Location()
{
	this->section = 0;
	this->shelf = 0;
	this->number = 0;
}

Location::Location(int section, int shelf, int number)
{
	this->section = section;
	this->shelf = shelf;
	this->number = number;
}

ostream& operator<<(ostream& os, const Location& location)
{
	return os << location.section << " " << location.shelf << " " << location.number;
}
