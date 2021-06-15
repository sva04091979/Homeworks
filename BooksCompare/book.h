#pragma once
#include <string>
#include <ostream>

namespace hw {

	using namespace std;

	using uint = unsigned int;

	class book
	{
		string cTitle;
		string cAuthor;
		uint cYear;
		double cPrice;
		void Copy(const book&);
	public:
		book() = default;
		book(const book&) = default;
		book(book&&) = default;
		book(string title, string author, uint year, double price);
		book& operator=(const book&);
		book& operator=(book&&) noexcept;
		string& Title();
		string& Author();
		uint& Year();
		double& Price();
		operator string() const;
		friend bool operator <(const book&, const book&);
		friend bool operator ==(const book&, const book&);
		friend ostream& operator<<(ostream&, const book&);
		friend int CompareBooksByPrice(const book& first, const book& second);
		friend int CompareBooksByAuthorAndTitleAndYear(const book& first, const book& second);
	};

	struct ByPrice {
		int operator()(const book& first, const book& second) const;
	};

	struct ByAuthor {
		int operator()(const book& first, const book& second) const;
	};

	ostream& operator<<(ostream&, const book&);
	bool operator ==(const book&, const book&);
	bool operator <(const book&, const book&);
	int CompareBooksByPrice(const book& first, const book& second);
	int CompareBooksByAuthorAndTitleAndYear(const book& first, const book& second);

	template<typename Type>
	bool Less(const book& first, const book& second) { return Type()(first, second) < 0; }
}