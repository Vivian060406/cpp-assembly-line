//*******************************************
// OOP345 Assignment 4
// File: CustomerOrder.h
// Name: Khanh Vy Tran
// Seneca Email: kvtran2@myseneca.ca
// Student ID: 120175245
// Date: 8/2/2026
// Version: 1.0
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to
// complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//*******************************************
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <cstddef>
#include <iostream>
#include <string>
#include "Station.h"

namespace seneca {
	class CustomerOrder {
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};

		static size_t m_widthField;

	public:
        CustomerOrder() = default;

        CustomerOrder(const std::string& record);

        CustomerOrder(const CustomerOrder& other);

        CustomerOrder& operator=(const CustomerOrder& other) = delete;

        CustomerOrder(CustomerOrder&& other) noexcept;

        CustomerOrder& operator=(CustomerOrder&& other) noexcept;

        ~CustomerOrder();

        bool isOrderFilled() const;

        bool isItemFilled(const std::string& itemName) const;

        void fillItem(Station& station, std::ostream& os);

        void display(std::ostream& os) const;
    };
}

#endif