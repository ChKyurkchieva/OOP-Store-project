#include"Product.hpp"
const int MAX_SIZE_IN_STORE = 10000;

class Store
{
	Product* store;
	static bool location[MAX_SIZE_IN_STORE];//the location of the products in the store wiil be saved in this array
	//the location will be saved by the index of the array;
	unsigned size;
	unsigned capacity;
	//unsigned lengthLocation;//the the current size of the array

	void copyFrom(const Store& other);
	void clean();
	void resize(unsigned newCapacity);
public:
	Store(unsigned size);
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	void print()const;
	void printInFile(ofstream& stream);
	void add(const Product& newProduct);
	void remove(const Product& productToRemove);
	void cleanFromStore(const Date& expiryDate);
};

void Store::copyFrom(const Store& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->store = new (nothrow) Product[this->capacity];
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
	this->store = new (nothrow) Product[size];
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
	Product* newStore = new (nothrow) Product[capacity];
	for (unsigned i = 0; i < size; i++)
	{
		newStore[i] = this->store[i];
	}
	delete[]store;
	store = newStore;
}

void Store::print()const 
{
	for (unsigned i = 0; i < this->size; i++)
	{
		this->store[i].print();
		cout << endl;
	}
}

void Store::printInFile(ofstream& stream)
{
	for (unsigned i = 0; i < this->size; i++)
	{
		this->store[i].printInFile(stream);
		stream << endl;
	}
}

void Store::add(const Product& newProduct)
{
	bool isSame = 0;
	for (unsigned i = 0; i < this->size; i++) //check if the product is already in the store and if the expiry date is same
	{
		if ((this->store[i] == newProduct) && (this->store[i].getExpiryDate() == newProduct.getExpiryDate()))
		{
			isSame = 1;
			unsigned newAmount = this->store[i].getAmount() + newProduct.getAmount();
			this->store[i].setAmount(newAmount);
			cout << "You have successfully increased the amount of the product!" << endl;
		}
	}
	if (!isSame)
	{
		if (this->size >= this->capacity)
		{
			resize(capacity * 2);
		}
		this->store[size] = newProduct;
		size++;
		cout << "You have successfully added a new product!";
	}
}

void Store::remove(const Product& productToRemove)
{
	bool isAlreadyRemoved = 0;
	unsigned indexToRemove = 0;
	for (unsigned i = 0; i < this->size; i++)//find the product and if the amount is bigger, less it
	{
		if (this->store[i] == productToRemove)
		{
			if (this->store[i].getAmount() > productToRemove.getAmount())
			{
				unsigned newAmount = this->store[i].getAmount() - productToRemove.getAmount();
				this->store[i].setAmount(newAmount);
				isAlreadyRemoved = 1;
				cout << "Successfully reduce the amount of product!" << endl;
			}
			indexToRemove = i;
		}
	}
	if (!isAlreadyRemoved)//otherwise, remove the product
	{
		for (unsigned i = indexToRemove; i < this->size - 1; i++)
		{
			this->store[i] = store[i + 1];
		}
		size--;
		cout << "Successfully removed the product!" << endl;
	}
}

void Store::cleanFromStore(const Date& expiryDate)
{
	for (unsigned i = 0; i < this->size; i++)
	{
		if (!(this->store[i].getExpiryDate().isLater(expiryDate)))
		{
			this->store[i].print();
			this->remove(this->store[i]);
		}
	}
}

