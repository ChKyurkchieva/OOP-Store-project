#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

#include"Date.hpp"
#include"Location.hpp"

class Product
{
private:
	char *name;// name of the product
	char *producedBy;//name of the producer
	char *comment;
	Date expiryDate;//expiry date of the product
	Date acceptanceDate;//date of entry into the storehouse
	bool measure;
	unsigned amount;//amount of the product in the storehouse
	Location productLocation;//location of the product in the storehouse

	void copyFrom(const Product& other);//function, which copy the information about a product to another product
	void free();// function, which free allocated memory
public:
	Product();//default constructor
	Product(const char *_name, const char *_producedBy, const char *_comment, Date& _expiryDate,
		Date& _acceptanceDate, bool _measure, unsigned _amount, Location& _productLocation);//constructor with parameters
	Product(const Product& other);//copy constructor
	Product& operator=(const Product& other);//operator =
	~Product();//destructor

	char* getName()const;
	char* getProducedBy()const;
	char* getComment()const;
	Date getExpiryDate()const;
	Date getAcceptanceDate()const;
	bool getMeasure()const;
	unsigned getAmount()const;
	Location getLocation()const;

	void setName(const char* newName);
	void setProducedBy(const char* newProducedBy);
	void setComment(const char* newComment);
	void setExpiryDate(const Date& newEDate);
	void setAcceptanceDate(const Date& newADate);
	void setMeasure(bool newMeasure);
	void setAmount(unsigned newAmount);
	void setLocation(const Location& newProductionLocation);

	void print()const;

};

void Product::copyFrom(const Product& other)
{
	unsigned nameLength = strlen(other.name);
	this->name = new char[nameLength + 1];
	strcpy(this->name, other.name);

	unsigned producedByLength = strlen(other.producedBy);
	this->producedBy = new char[producedByLength + 1];
	strcpy(this->producedBy, other.producedBy);

	unsigned commentLength = strlen(other.comment);
	this->comment = new char[commentLength + 1];
	strcpy(this->comment, other.comment);

	this->expiryDate = other.expiryDate;
	this->acceptanceDate = other.acceptanceDate;
	this->measure = other.measure;
	this->amount = other.amount;
	this->productLocation = other.productLocation;
}

void Product::free()
{
	delete[]name;
	delete[]producedBy;
	delete[]comment;
}

Product::Product()
{
	this->name = new char[1];
	this->name[0] = '\0';
	this->producedBy = new char[1];
	this->producedBy[0] = '\0';
	this->comment = new char[1];
	this->comment[0] = '\0';
	this->expiryDate = Date(January, 1, 2001);
	this->acceptanceDate = Date(January, 1, 2000);
	this->measure = 0;
	this->amount = 0;
	this->productLocation = Location(0, 0, 0);
}

Product::Product(const char *_name, const char *_producedBy, const char *_comment, Date& _expiryDate,
	Date& _acceptanceDate, bool _measure, unsigned _amount, Location& _productLocation)
{
	unsigned nameLength = strlen(_name);
	this->name = new char[nameLength + 1];
	strcpy(this->name, _name);

	unsigned producedByLength = strlen(_producedBy);
	this->producedBy = new char[producedByLength + 1];
	strcpy(this->name, _name);

	unsigned commentLength = strlen(comment);
	this->name = new char[commentLength + 1];
	strcpy(this->comment, _comment);

	this->expiryDate = _expiryDate;
	this->acceptanceDate = _acceptanceDate;
	this->measure = _measure;
	this->amount = _amount;
	this->productLocation = _productLocation;
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

char* Product::getName()const
{
	return this->name;
}

char* Product::getProducedBy()const
{
	return this->producedBy;
}

char* Product::getComment()const
{
	return this->comment;
}

Date Product::getExpiryDate()const
{
	return this->expiryDate;
}

Date Product::getAcceptanceDate()const
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

Location Product::getLocation()const
{
	return this->productLocation;
}

void Product::setName(const char* newName)
{
	unsigned newNameLength = strlen(newName);
	delete[]name;
	name = nullptr;
	this->name = new char[newNameLength + 1];
	strcpy(this->name, newName);
	this->name[newNameLength] = '\0';
}

void Product::setProducedBy(const char* newProducedBy)
{
	unsigned newProducedByLength = strlen(newProducedBy);
	delete[] producedBy;
	producedBy = nullptr;
	this->producedBy = new char[newProducedByLength + 1];
	strcpy(this->producedBy, newProducedBy);
	this->producedBy[newProducedByLength] = '\0';
}

void Product::setComment(const char* newComment)
{
	unsigned newCommentLength = strlen(newComment);
	delete[] comment;
	comment = nullptr;
	this->comment = new char[newCommentLength + 1];
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

void Product::setLocation(const Location& newProductionLocation)
{
	this->productLocation = newProductionLocation;
}

void Product::print()const
{
	cout << "Name of product: ";
	cout<< this->getName() << endl;
	cout << "The name of producer: ";
	cout << this->getProducedBy() << endl;
	cout << "The amount of the product: ";
	cout << this->getAmount() << endl;
	cout << "The location of the product: ";
	cout << this->getLocation() << endl;
	cout << "The acceptance date of the product: ";
	cout << this->getAcceptanceDate() << endl;
	cout << " The expiry date of the product: ";
	cout << this->getExpiryDate() << endl;
}