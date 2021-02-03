// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/03
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {
	void Bill::setEmpty() {
		strCpy(this->m_title, "");
		this->m_items = nullptr;
		this->m_noOfItems = 0;
		this->m_itemsAdded = 0;
	}

	bool Bill::isValid() const {
		// Check title and items pointer.
		if (strLen(this->m_title) == 0 || this->m_items == nullptr) return false;
		// Check each item.
		for (int i = 0; i < this->m_noOfItems; i++) {
			if (!this->m_items[i].isValid()) return false;
		}
		// All checks passed.
		return true;
	}

	double Bill::totalTax() const {
		if (!this->isValid()) return 0.0;
		double sum = 0.0;
		for (int i = 0; i < this->m_noOfItems; i++) sum += this->m_items[i].tax();
		return sum;
	}

	double Bill::totalPrice() const {
		if (!this->isValid()) return 0.0;
		double sum = 0.0;
		for (int i = 0; i < this->m_noOfItems; i++) sum += this->m_items[i].price();
		return sum;
	}

	void Bill::Title() const {
		cout << "+--------------------------------------+" << endl;

		if (this->isValid()) {
			cout << "| ";
			cout << left << setw(36) << this->m_title;
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer() const {
		cout << "+----------------------+---------+-----+" << endl;

		if (this->isValid()) {
			double totalTax = this->totalTax();
			double totalPrice = this->totalPrice();
			cout << "|                Total Tax: ";
			cout << right << setw(10) << setprecision(2) << fixed << totalTax;
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout << right << setw(10) << setprecision(2) << fixed << totalPrice;
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout << right << setw(10) << setprecision(2) << fixed << totalPrice + totalTax;
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		if (title == nullptr || noOfItems <= 0) {
			// Invalid args.
			this->setEmpty();
			return;
		}

		this->m_noOfItems = noOfItems;
		this->m_itemsAdded = 0;
		strnCpy(this->m_title, title, 36);
		this->m_items = new Item[noOfItems];
		for (int i = 0; i < noOfItems; i++) this->m_items[i].setEmpty();
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		if (this->m_itemsAdded >= this->m_noOfItems) return false;
		this->m_items[this->m_itemsAdded].set(item_name, price, taxed);
		this->m_itemsAdded++;
		return true;
	}

	void Bill::display() const {
		this->Title();
		for (int i = 0; i < this->m_noOfItems; i++) this->m_items[i].display();
		this->footer();
	}

	void Bill::deallocate() {
		delete[] this->m_items;
		this->m_items = nullptr;
	}
}