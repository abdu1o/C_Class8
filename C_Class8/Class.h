#pragma once
class Date
{
private:
	int day, month, year;
	int value;

public:

	Date(int _day, int _month, int _year)
	{
		this->day = _day;
		this->month = _month;
		this->year = _year;
	}

	Date(int i) : value(i)
	{}

	const Date& operator++()
	{
		this->day++;

		if (day > 31)
		{
			month += day / 31;
			day /= 31;

			if (month > 12)
			{
				year += month / 12;
				month /= 12;
			}
		}
		return *this;
	}

	const Date& operator--()
	{
		this->day--;

		if (day < 1)
		{
			day = 31;
			month--;

			if (month < 1)
			{
				month = 12;
				year--;
			}
		}
		return *this;
	}

	const Date& operator+=(int value)
	{
		this->day += value;

		if (day > 31)
		{
			month += day / 31;
			day /= 31;

			if (month > 12)
			{
				year += month / 12;
				month /= 12;
			}
		}
		return *this;
	}

	const Date& operator-=(int value)
	{
		this->day -= value;

		if (day < 1)
		{
			day /= 31;
			month -= abs(day / 31);

			if (month < 1)
			{
				month = 12;
				year--;
			}
		}
		return *this;
	}

	const bool operator!=(Date& obj)
	{
		if (this->day != obj.day 
			&& this->month != obj.month 
			&& this->year != obj.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const bool operator==(Date& obj)
	{
		if (this->day == obj.day
			&& this->month == obj.month
			&& this->year == obj.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const Date& operator=(Date& obj)
	{
		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;

		return *this;
	}

	const bool operator>(Date& obj)
	{

		if (this->year > obj.year)
		{
			return true;
		}
		else if (this->year == obj.year)
		{
			if (this->month > obj.month)
			{
				return true;
			}
		}
		else if (this->year == obj.year && this->month == obj.month)
		{
			if (this->day > obj.day)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	const bool operator<(Date& obj)
	{

		if (this->year < obj.year)
		{
			return true;
		}
		else if (this->year == obj.year)
		{
			if (this->month <  obj.month)
			{
				return true;
			}
		}
		else if (this->year == obj.year && this->month == obj.month)
		{
			if (this->day < obj.day)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, Date& obj)
	{
		out << "Day: " << obj.day << std::endl;
		out << "Month: " << obj.month << std::endl;
		out << "Year: " << obj.year << std::endl;
		return out;
	}

	friend std::istream& operator>> (std::istream& in, Date& obj)
	{
		in >> obj.day;
		in >> obj.month;
		in >> obj.year;

		return in;
	}

	const Date& operator() (int _day, int _month, int _year)
	{
		this->day = _day;
		this->month = _month;
		this->year = _year;

		return *this;
	}
};