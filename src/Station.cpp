//*******************************************
// OOP345 Assignment 4
// File: Station.cpp
// Name: Khanh Vy Tran
// Seneca Email: kvtran2@myseneca.ca
// Student ID: 120175245
// Date: 8/2/2026
// Version: 1.0
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to
// complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//*******************************************
#include "Station.h"
#include "Utilities.h"
#include <iomanip>
#include <utility>

namespace seneca {
	size_t Station::m_widthField{};
	size_t Station::id_generator{};

	Station::Station(const std::string& record){
		Utilities util;

		size_t nextPosition = 0;
		bool more = true;

		m_id = ++id_generator;

		m_itemName = util.extractToken(record, nextPosition, more);
		m_serialNumber = std::stoul(util.extractToken(record, nextPosition, more));
		m_quantity = std::stoul(util.extractToken(record, nextPosition, more));

		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}

		m_description = util.extractToken(record, nextPosition, more);
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;	
	}

	size_t Station::getQuantity() const {
		return m_quantity;
	}

	void Station::updateQuantity() {
		if (m_quantity > 0) {
			--m_quantity;
		}
	}

	void Station::display(std::ostream& os, bool full) const{
		os << std::right
			<< std::setfill('0')
			<< std::setw(3)
			<< m_id
			<< " | ";

		os << std::left
			<< std::setfill(' ')
			<< std::setw(m_widthField)
			<< m_itemName
			<< " | ";

		os << std::right
			<< std::setfill('0')
			<< std::setw(6)
			<< m_serialNumber
			<< " | ";

		if (full) {
			os << std::setfill(' ')
				<< std::setw(4)
				<< m_quantity
				<< " | "
				<< m_description;
		}
		os << '\n';
	}
}