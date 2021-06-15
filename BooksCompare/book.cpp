#include "book.h"
#include <sstream>
#include <iomanip>

namespace hw {

	book::book(string title, string author, uint year, double price) :
		cTitle(title), cAuthor(author), cYear(year), cPrice(price) {}

	book& book::operator=(const book& other) {
		if (&other != this)
			Copy(other);
		return *this;
	}

	book& book::operator=(book&& other) noexcept{
		if (&other != this)
			Copy(other);
		return *this;
	}

	void book::Copy(const book& other) {
		cTitle=other.cTitle;
		cAuthor=other.cAuthor;
		cYear=other.cYear;
		cPrice=other.cPrice;
	}

	string& book::Title() { return cTitle; }
	string& book::Author() { return cAuthor; }
	uint& book::Year() { return cYear; }
	double& book::Price() { return cPrice; }

	book::operator string() const {
		ostringstream price;
		price << fixed << setprecision(2) << cPrice;
		return "Book{title='" + cTitle + "', author='" + cAuthor + "', year=" + to_string(cYear) + ", price=" + price.str() + '}';
	}

	int ByPrice::operator()(const book& first, const book& second) const {
		return CompareBooksByPrice(first, second);
	}

	int ByAuthor::operator()(const book& first, const book& second) const {
		return CompareBooksByAuthorAndTitleAndYear(first, second);
	}

	ostream& operator<<(ostream& out, const book& it) {
		out << (string)it;
		return out;
	}

	bool operator ==(const book& first, const book& second) {
		return first.cAuthor == second.cAuthor &&
			first.cPrice == second.cPrice &&
			first.cTitle == second.cTitle &&
			first.cYear == second.cYear;
	}

	bool operator < (const book& first, const book& second) {
		return first.cAuthor < second.cAuthor ||
			(first.cAuthor == second.cAuthor&&(first.cTitle < second.cTitle||
			(first.cTitle == second.cTitle&& (first.cYear < second.cYear||
			(first.cYear == second.cYear&&first.cPrice<second.cPrice)))));
	}

	int CompareBooksByPrice(const book& first, const book& second) {
		return first.cPrice<second.cPrice ? -1 : first.cPrice>second.cPrice ? 1 : 0;
	}

	int CompareBooksByAuthorAndTitleAndYear(const book& first, const book& second) {
		return first.cAuthor<second.cAuthor ? -1 : first.cAuthor>second.cAuthor ? 1 :
			first.cTitle<second.cTitle ? -1 : first.cTitle>second.cTitle ? 1 :
			first.cYear<second.cYear ? -1 : first.cYear>second.cYear ? 1 : 0;
	}
}