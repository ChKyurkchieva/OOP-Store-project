#define _CRT_SECURE_NO_WARNINGS

#include<cstring>

#include"Date.hpp"

class Product
{
private:
	char *name;// name of the product
	char *producedBy;//name of the producer
	char *comment;
	
	Date expiryDate;//expiry date of the product
	Date acceptanceDate;//date of entry into the storehouse
	unsigned amount;//amount of the product in the storehouse
	bool measure;//if 1-kg, if is 0-ml

	void copyFrom(const Product& other);//function, which copy the information about a product to another product
	void free();// function, which free allocated memory
public:
	Product();//default constructor
	Product(const char *_name, const char *_producedBy, const char *_comment, const Date& _acceptanceDate, 
		const Date& _expiryDate, bool _measure, unsigned _amount);//constructor with parameters
	Product(const Product& other);//copy constructor
	Product& operator=(const Product& other);//operator =
	~Product();//destructor

	const char* getName()const;
	const char* getProducedBy()const;
	const char* getComment()const;
	const Date& getExpiryDate()const;
	const Date& getAcceptanceDate()const;
	bool getMeasure()const;
	unsigned getAmount()const;

	void setName(const char* newName);
	void setProducedBy(const char* newProducedBy);
	void setComment(const char* newComment);
	void setExpiryDate(const Date& newEDate);
	void setAcceptanceDate(const Date& newADate);
	void setMeasure(bool newMeasure);
	void setAmount(unsigned newAmount);

	void print()const;
	void printInFile(ofstream& stream)const;

	friend bool operator==(const Product& lhs, const Product& rhs);

	friend ofstream& operator<<(ofstream& out, const Product& product);
	friend istream& operator>>(istream& in, Product& product);

};

void Product::copyFrom(const Product& other)
{
	int nameLength = strlen(other.name);
	this->name = new (nothrow) char [nameLength + 1];
	strcpy(this->name, other.name);

	int producedByLength = strlen(other.producedBy);
	this->producedBy = new (nothrow) char[producedByLength + 1];
	strcpy(this->producedBy, other.producedBy);

	int commentLength = strlen(other.comment);
	this->comment = new (nothrow) char[commentLength + 1];
	strcpy(this->comment, other.comment);

	this->expiryDate = other.expiryDate;
	this->acceptanceDate = other.acceptanceDate;
	this->measure = other.measure;
	this->amount = other.amount;

}

void Product::free()
{
	delete[]name;
	delete[]producedBy;
	delete[]comment;
}

Product::Product()
{
	this->name = new (nothrow) char[1];
	this->name[0] = '\0';
	this->producedBy = new (nothrow) char[1];
	this->producedBy[0] = '\0';
	this->comment = new (nothrow) char[1];
	this->comment[0] = '\0';
	this->expiryDate = Date(1,January, 2001);
	this->acceptanceDate = Date(1, January, 2000);
	this->measure = 0;
	this->amount = 0;
	
}

Product::Product(const char *_name, const char *_producedBy, const char *_comment, const Date& _acceptanceDate, 
	const Date& _expiryDate, bool _measure, unsigned _amount)
{
	unsigned nameLength = strlen(_name);
	this->name = new (nothrow) char[nameLength + 1];
	strcpy(this->name, _name);

	unsigned producedByLength = strlen(_producedBy);
	this->producedBy = new (nothrow) char[producedByLength + 1];
	strcpy(this->producedBy, _producedBy);

	unsigned commentLength = strlen(_comment);
	this->comment = new (nothrow) char[commentLength + 1];
	strcpy(this->comment, _comment);

	this->expiryDate = _expiryDate;
	this->acceptanceDate = _acceptanceDate;
	this->measure = _measure;
	this->amount = _amount;

}

Product::Product(const Product& other)
{
	copyFrom(other);
}

Product& Product:: operator=(const Product& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Product::~Product()
{
	free();
}

const char* Product::getName()const
{
	return this->name;
}

const char* Product::getProducedBy()const
{
	return this->producedBy;
}

const char* Product::getComment()const
{
	return this->comment;
}

const Date& Product::getExpiryDate()const
{
	return this->expiryDate;
}

const Date& Product::getAcceptanceDate()const
{
	return this->acceptanceDate;
}

bool Product::getMeasure()const
{
	return this->measure;
}

unsigned Product::getAmount()const
{
	return this->amount;
}

void Product::setName(const char* newName)
{
	unsigned newNameLength = strlen(newName);
	delete[]name;
	name = nullptr;
	this->name = new (nothrow) char[newNameLength + 1];
	strcpy(this->name, newName);
	this->name[newNameLength] = '\0';
}

void Product::setProducedBy(const char* newProducedBy)
{
	unsigned newProducedByLength = strlen(newProducedBy);
	delete[] producedBy;
	producedBy = nullptr;
	this->producedBy = new (nothrow) char[newProducedByLength + 1];
	strcpy(this->producedBy, newProducedBy);
	this->producedBy[newProducedByLength] = '\0';
}

void Product::setComment(const char* newComment)
{
	unsigned newCommentLength = strlen(newComment);
	delete[] comment;
	comment = nullptr;
	this->comment = new (nothrow) char[newCommentLength + 1];
	strcpy(this->comment, newComment);
	this->comment[newCommentLength] = '\0';
}

void Product::setExpiryDate(const Date& newEDate)
{
	this->expiryDate = newEDate;
}

void Product::setAcceptanceDate(const Date& newADate)
{
	this->acceptanceDate = newADate;
}

void Product::setMeasure(bool newMeasure)
{
	this->measure = newMeasure;
}

void Product::setAmount(unsigned newAmount)
{
	this->amount = newAmount;
}

void Product::print()const
{
	cout << "Name of product: ";
	cout<< this->getName() << endl;
	cout << "The name of producer: ";
	cout << this->getProducedBy() << endl;
	cout << "The amount of the product: ";
	cout << this->getAmount() << endl;
	cout << "The acceptance date of the product: ";
	cout << this->getAcceptanceDate() << endl;
	cout << "The expiry date of the product: ";
	cout << this->getExpiryDate() << endl;
}

bool operator==(const Product& lhs, const Product& rhs)
{
	return (strcmp(lhs.name, rhs.name) == 0 && 
		strcmp(lhs.producedBy, rhs.producedBy) == 0 &&
		(lhs.measure==rhs.measure));
}

void Product::printInFile(ofstream& stream)const
{
	stream << "Name of product: ";
	stream << this->getName() << endl;
	stream<< "The name of producer: ";
	stream << this->getProducedBy() << endl;
	stream << "The amount of the product: ";
	stream << this->getAmount() << endl;
	stream << "The acceptance date of the product: ";
	stream << this->getAcceptanceDate() << endl;
	stream << " The expiry date of the product: ";
	stream << this->getExpiryDate() << endl;
}

ofstream& operator<<(ofstream& out, const Product& product)
{
	out << product.name << product.producedBy << product.comment << product.acceptanceDate;
	out << product.expiryDate << product.measure << product.amount;
	return out;
}

istream& operator>>(istream& in, Product& product)
{
	in >> product.name >> product.producedBy >> product.comment;
	in >> product.acceptanceDate;
	in >> product.expiryDate >> product.measure >> product.amount;
	return in;
}

