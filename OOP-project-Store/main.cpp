#include"Store.hpp"
int main()
{
	Date date(March, 20, 2000);
	Date newDate(January, 10, 2000);
	date = newDate;
	Date p = date;
	//cout<<date.isLater(newDate);
	//date.addDays(53);
	p.print();
	bool measure = 0;
	unsigned amount = 10;
	Location location(12, 24, 46);
	Product product("Milk","MilkTrade","To be located properly!",date,newDate,measure,amount,location);

	char c;
	cin >> c;
	return 0;
}