// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/03
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;

const double INITIAL_PRICE = 0.0;
const bool INITIAL_TAXED = false;
const double TAX_RATE = 0.13;

namespace sdds {
	void Item::setName(const char* name) {
		strCpy(this->m_itemName, name);
	}

	void Item::setEmpty() {
		strCpy(this->m_itemName, "");
		this->m_price = INITIAL_PRICE;
		this->m_taxed = INITIAL_TAXED;
	}

	void Item::set(const char* name, double price, bool taxed) {
		strCpy(this->m_itemName, name == nullptr ? "" : name);
		this->m_price = price;
		this->m_taxed = taxed;
	}

	void Item::display() const {
		if (this->isValid()) {
			cout << "| ";
			cout << left << setw(20) << setfill('.') << this->m_itemName;
			cout << " | ";
			cout << right << setw(7) << fixed << setprecision(2) << this->m_price;
			cout << " | ";
			if (this->m_taxed) {
				cout << "Yes";
			}
			else {
				cout << "No ";
			}
			cout << " |" << endl;
		}
		else {
			cout << "| ";
			for (int i = 0; i < 20; i++) cout << "x";
			cout << " | ";
			for (int i = 0; i < 7; i++) cout << "x";
			cout << " | ";
			for (int i = 0; i < 3; i++) cout << "x";
			cout << " |" << endl;
		}
	}

	bool Item::isValid() const {
		if (this->m_itemName == nullptr) return false;
		if (strLen(this->m_itemName) == 0) return false;
		if (this->m_price <= 0.0) return false;
		return true;
	}

	double Item::price() const { return this->m_price; }
	double Item::tax() const { return this->m_taxed ? this->m_price * TAX_RATE : 0.0; }
}