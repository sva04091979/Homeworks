#include "pch.h"
#include <vector>
#include <algorithm>
#include <set>
#include "CppUnitTest.h"
#include "..\BooksCompare\book.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Comparator)
		{
			using namespace std;
			using namespace hw;
			static vector<book> algoBooks{
					book("������� ���������", "������ ��������", 2017, 500.0),
					book("����������� ��������. ������", "��� ���������", 2019, 1500.0),
					book("����������� ��������. �������� ��������� � ��������� ������", "��������� ���", 2019, 999.0),
					book("��������� ��� ����������", "������� �����", 2018, 499.0),
					book("������� ���������", "������ ��������", 2021, 700.0),
					book("�������� � ������ ����������", "����� ������", 2019, 500.0),
					book("���������: ���������� � ����������", "���� ���������", 2016, 100.0)
			};
			static set<book> _set(algoBooks.begin(), algoBooks.end());
			static auto check = algoBooks;
			sort(check.begin(), check.end(), [](auto l, auto r) {return l.Price() < r.Price(); });
			sort(algoBooks.begin(), algoBooks.end(), Less<ByPrice>);
			Assert::AreEqual(algoBooks==check,true);
			sort(check.begin(), check.end(), [](auto l, auto r) {
				return l.Author() < r.Author() ||
					(l.Author() == r.Author() && (l.Title() < r.Title() ||
						(l.Title() == r.Title() && l.Year() < r.Year())));
						});
			sort(algoBooks.begin(), algoBooks.end(), Less<ByAuthor>);
			Assert::AreEqual(algoBooks==check,true);
			Assert::AreEqual(equal(algoBooks.begin(),algoBooks.end(),_set.begin(),_set.end()), true);
		}
	};
}
