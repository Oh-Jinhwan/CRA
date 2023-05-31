#include <vector>
#include <string>
#include <sstream>

// ctrl + alt + enter : reformat code (자동 들여쓰기)
// ctrl + alt + shift + up/down : 코드 이동시키기

class Movie {
public:
	static const int CHILDRENS = 2;
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;

public:
	Movie(std::string title, int priceCode)
		: _title(title), _priceCode(priceCode) {}

	std::string getTitle() const {
		return _title;
	}

	int getPriceCode() const {
		return _priceCode;
	}

	void setPriceCode(int priceCode) {
		_priceCode = priceCode;
	}

private:
	std::string _title;
	int _priceCode;
};

class Rental {
private:
	Movie _movie;

public:
	Rental(const Movie& movie, int daysRented)
		: _movie(movie), _daysRented(daysRented)
	{
		
	}

	int getDaysRented() const {
		return _daysRented;
	}

	const Movie& getMovie() const {
		return _movie;
	}

private:
	int _daysRented;
};

class Customer {
private:
	std::string _name;
	std::vector<Rental> _rentals;

public:
	Customer(std::string name)
		: _name(name)
	{
		
	}

	void addRental(const Rental& rental) {
		_rentals.push_back(rental);
	}

	std::string statement() const {
		double totalAmount = 0;
		int frequentRenterPoints = 0;
		std::string result = "Rental Record for " + getName() + "\n";

		for (auto it = _rentals.begin(); it != _rentals.end(); ++it) {
			double thisAmount = 0;
			const Rental& each = *it;
			// determines the amount for each line
			switch (each.getMovie().getPriceCode())
			{
			case Movie::REGULAR:
				thisAmount += 2;
				if (each.getDaysRented() > 2)
					thisAmount += (each.getDaysRented() - 2) * 1.5;
				break;

			case Movie::NEW_RELEASE:
				thisAmount += each.getDaysRented() * 3;
				break;

			case Movie::CHILDRENS:
				thisAmount += 1.5;
				if (each.getDaysRented() > 3)
					thisAmount += (each.getDaysRented() - 3) * 1.5;
				break;
			}
			// add frequent renter points
			frequentRenterPoints++;

			// add bonus for a two day new release rental
			if (each.getMovie().getPriceCode() == Movie::NEW_RELEASE && each.getDaysRented() > 1)
				frequentRenterPoints++;

			// show figures for this rental
			std::ostringstream stream;
			stream << "\t" << each.getMovie().getTitle() << "\t" << thisAmount << "\n";
			result += stream.str();
			totalAmount += thisAmount;
		}

		// add footer lines
		std::ostringstream stream;
		stream << "You owed " << totalAmount << "\n"
				<< "You earned " << frequentRenterPoints << " frequent renter points";
		result += stream.str();

		return result;
	}
	std::string getName() const {
		return _name;
	}
};