#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
enum Month
{
	January = 1, February, March, April, May, June, July,
	August, September, October, November, December
};
class Date
{
	Month month;
	unsigned year;
	unsigned day;
public:
	Date();
	Date(Month month, unsigned day, unsigned year);
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

	friend ostream& operator << (ostream& os, const Date& date);
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

bool isValidDate(unsigned int day, unsigned int month, unsigned int year)
{
	if (year > 1990 && year < 2120 && month>0 && month <= 12 && day >= 1 && day <= 31)
	{
		if ((month >= 1 && month <= 7 && month % 2 == 1) || (month >= 8 && month <= 12 && month % 2 == 0))
			return (day >= 1 && day <= 31);
		else if (month >= 1 && month <= 7 && month % 2 == 0 || month >= 8 && month <= 12 && month % 2 == 1)
			return (isLeap(year) && month == 2 && day >= 1 && day <= 29) || (!isLeap(year) && month == 2 && day >= 1 && day <= 28) || (month != 2 && day >= 1 && day <= 30);
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

Date::Date(Month month, unsigned day, unsigned year)
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
		if (this->month >= 1 && this->month <= 7 && this->month % 2 == 1 || this->month >= 8 && this->month <= 12 && this->month % 2 == 0)
			result += 31;
		else if (this->month >= 1 && this->month <= 7 && this->month % 2 == 0 || this->month >= 8 && this->month <= 12 && this->month % 2 == 1)
		{
			if (month == 2 && isLeapYear())
				result += 29;
			else if (!(month == 2 && isLeapYear()))
				result += 28;
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
	return os << date.day <<" "<< date.month <<" "<< date.year;
}
