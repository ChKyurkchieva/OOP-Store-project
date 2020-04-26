#include"Product.hpp"
class Store
{
	Product* store;
	unsigned size;
	unsigned capacity;
	void copyFrom(const Store& other);
	void clean();
	void resize(unsigned newCapacity);
public:
	Store(unsigned size);
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();
	void print();
	bool add(const Product& newProduct);
	bool remove(const Product& productToRemove);
	void log(const Date& dateFrom, const Date& dateTo);
	void cleanFromStore();
};

void Store::copyFrom(const Store& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->store = new Product[this->capacity];
	for (unsigned i = 0; i < size; i++)
	{
		this->store[i] = other.store[i];
	}
}

void Store::clean()
{
	delete[] store;
	store = nullptr;
}

Store::Store(unsigned size)
{
	this->size = 0;
	this->capacity = size;
	this->store = new Product[size];
}

Store::Store(const Store& other)
{
	if (this != &other)
	{
		this->copyFrom(other);
	}
}

Store& Store::operator=(const Store& other)
{
	if (this != &other)
	{
		clean();
		copyFrom(other);
	}
	return *this;
}

Store::~Store()
{
	this->clean();
}

void Store::resize(unsigned newCapacity)
{
	if (newCapacity < this->capacity)
	{
		return;
	}
	this->capacity = newCapacity;
	Product* newStore = new Product[capacity];
	for (unsigned i = 0; i < size; i++)
	{
		newStore[i] = this->store[i];
	}
	delete[]store;
	store = newStore;
}

void Store::print()
{

}
/*bool Store::add(const Product& newProduct)
{
	if (this->size >= this->capacity)
	{
		resize(capacity * 2);
	}

}*/
//bool Store::remove(const Product& productToRemove);
//void Store::log(const Date& dateFrom, const Date& dateTo);
//void Store::cleanFromStore();