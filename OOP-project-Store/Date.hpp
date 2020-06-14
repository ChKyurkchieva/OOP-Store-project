#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::nothrow;
using std::ios;

enum Month
{
	January = 1, February, March, April, May, June, July,
	August, September, October, November, December
};

istream& operator >>(istream& is, const Month& month)
{
	is >>(char*) month;
	return is;
}

class Date
{
	Month month;
	unsigned year;
	unsigned day;
public:
	Date();
	Date(unsigned day, Month month, unsigned year);

	Month getMonth()const;
	unsigned getYear()const;
	unsigned getDay()const;

	void setMonth(Month newMonth);
	void setYear(unsigned newYear);
	void setDay(unsigned newDay);

	bool isLeapYear()const;
	unsigned convertToDays()const;
	bool isLater(const Date& other)const;
	void print()const;
	void printInFile(ofstream& stream)const;
	
	friend ostream& operator << (ostream& os, const Date& date);
	friend bool operator==(const Date& lhs, const Date& rhs);
	friend istream& operator>>(istream& is, Date& date);
};

bool isLeap(unsigned year)
{
	if (year % 4==0)
	{
		if (year % 100 == 0)
		{
			return (year % 400 == 0);
		}
		return false;
	}
	return false;
}

bool isValidDate(unsigned int day, Month month, unsigned int year)
{
	if (year > 1990 && year < 2120 && month>=January && month <= December && day >= 1 && day <= 31)
	{
		if ((month >= January && month <= July && month % 2 == 1) || (month >= August && month <= December && month % 2 == 0))
			return (day >= 1 && day <= 31);
		else if (month >= January && month <= July && month % 2 == 0 || month >= August && month <= December && month % 2 == 1)
			return (isLeap(year) && month == February && day >= 1 && day <= 29) || (!isLeap(year) && month == February && day >= 1 && day <= 28) || (month != February && day >= 1 && day <= 30);
		else return false;
	}
	else return false;
}

Date::Date()
{
	this->day = 1;
	this->month = January;
	this->year = 1990;
}

Date::Date(unsigned day, Month month, unsigned year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Month Date::getMonth()const
{
	return this->month;
}

unsigned Date::getYear()const
{
	return this->year;
}

unsigned Date::getDay()const
{
	return this->day;
}

void Date::setMonth(Month month)
{
	this->month = month;
}

void Date::setYear(unsigned year)
{
	this->year = year;
}

void Date::setDay(unsigned day)
{
	this->day = day;
}

bool Date::isLeapYear()const
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			return (year % 400 == 0);
		}
		return false;
	}
	return false;
}

unsigned int Date::convertToDays()const
{
	unsigned int result = 0;
	result = this->day;
	for (unsigned i = 1; i < (unsigned)month; i++)
	{
		if (this->month >= January && this->month <= July && this->month % 2 == 1 || this->month >= August && this->month <= December && this->month % 2 == 0)
			result += 31;
		else if (this->month >= January && this->month <= July && this->month % 2 == 0 || this->month >= August && this->month <= December && this->month % 2 == 1)
		{
			if (month == February && isLeapYear())
			{
				result += 29;
			}
			else if (!(month == February && isLeapYear()))
			{
				result += 28;
			}
			else result += 30;
		}
	}
	return result;
}

bool Date::isLater(const Date& other)const
{
	unsigned convertedThis = this->convertToDays();
	unsigned convertedOther = other.convertToDays();
	if (this->getYear()==other.getYear())
	{
		return(convertedThis > convertedOther);
	}
	else if(this->getYear() > other.getYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Date::print()const
{
	cout << this->getDay() << '/' << this->getMonth() << '/' << this->getYear() << endl;
}

ostream& operator << (ostream& os, const Date& date)
{
	return os << date.day <<"/"<< date.month <<"/"<< date.year;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return ((lhs.year == rhs.year) && (lhs.month == rhs.month) && (lhs.day == rhs.day));
}

void Date::printInFile(ofstream& stream)const
{
	stream << this->day << "/"<< this->month << "/" << this->year;
}

istream& operator>>(istream& is, Date& date)
{
	is >> date.day;
	is >> (char*)date.month;
	is >> date.year; 

	return is;
}