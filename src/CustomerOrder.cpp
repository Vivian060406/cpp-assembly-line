//*******************************************
// OOP345 Assignment 4
// File: CustomerOrder.cpp
// Name: Khanh Vy Tran
// Seneca Email: kvtran2@myseneca.ca
// Student ID: 120175245
// Date: 8/2/2026
// Version: 1.0
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to
// complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//*******************************************
#include "CustomerOrder.h"
#include "Utilities.h"
#include <vector>
#include <iomanip>

namespace seneca {
    size_t CustomerOrder::m_widthField{};

    CustomerOrder::CustomerOrder(const std::string& record) {
        Utilities util;

        size_t nextPosition = 0;
        bool more = true;

        m_name = util.extractToken(record, nextPosition, more);

        m_product = util.extractToken(record, nextPosition, more);

        std::vector<std::string> itemNames;

        while (more) {
            itemNames.push_back(util.extractToken(record, nextPosition, more));
        }

        m_cntItem = itemNames.size();

        m_lstItem = new Item * [m_cntItem];

        for (size_t i = 0; i < m_cntItem; ++i) {
            m_lstItem[i] = new Item(itemNames[i]);
        }

        if (m_widthField < util.getFieldWidth()) {
            m_widthField = util.getFieldWidth();
        }
    }
     
    CustomerOrder::CustomerOrder(const CustomerOrder&) {
        throw "Cannot make copies.";
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
        *this = std::move(other);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < m_cntItem; ++i) {
                delete m_lstItem[i];
            }

            delete[] m_lstItem;

            m_name = std::move(other.m_name);
            m_product = std::move(other.m_product);
            m_cntItem = other.m_cntItem;
            m_lstItem = other.m_lstItem;

            other.m_cntItem = 0;
            other.m_lstItem = nullptr;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; ++i) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        for (size_t i = 0; i < m_cntItem; ++i) {
            if (!m_lstItem[i]->m_isFilled) {
                return false;
            }
        }
        return true;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        for (size_t i = 0; i < m_cntItem; ++i) {
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
                return false;
            }
        }
        return true;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        for (size_t i = 0; i < m_cntItem; ++i) {
            if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
                if (station.getQuantity() > 0) {
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;

                    station.updateQuantity();

                    os << "    Filled "
                        << m_name
                        << ", "
                        << m_product
                        << " ["
                        << m_lstItem[i]->m_itemName
                        << "]\n";
                    return;
                } else {
                    os << "    Unable to fill "
                        << m_name
                        << ", "
                        << m_product
                        << " ["
                        << m_lstItem[i]->m_itemName
                        << "]\n";
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name
            << " - "
            << m_product
            << '\n';

        for (size_t i = 0; i < m_cntItem; ++i) {
            os << '['
                << std::setfill('0')
                << std::setw(6)
                << m_lstItem[i]->m_serialNumber
                << "] ";

            os << std::left
                << std::setfill(' ')
                << std::setw(m_widthField)
                << m_lstItem[i]->m_itemName
                << " - ";

            os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << '\n';

            os << std::right;
        }
    }
}