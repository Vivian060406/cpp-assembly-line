//*******************************************
// OOP345 Assignment 4
// File: Workstation.cpp
// Name: Khanh Vy Tran
// Seneca Email: kvtran2@myseneca.ca
// Student ID: 120175245
// Date: 8/2/2026
// Version: 1.0
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to
// complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//*******************************************
#include "Workstation.h"
#include <utility>

namespace seneca {
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string& record)
        : Station(record){}

    void Workstation::fill(std::ostream& os) {
        if (!m_orders.empty()) {
            m_orders.front().fillItem(*this, os);
        }
    }

    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const {
        os << getItemName() << " --> ";

        if (m_pNextStation != nullptr) {
            os << m_pNextStation->getItemName();
        } else {
            os << "End of Line";
        }
        os << '\n';
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }

    bool Workstation::attemptToMoveOrder() {
        if (m_orders.empty()) {
            return false;
        }

        CustomerOrder& order = m_orders.front();

        if (order.isItemFilled(getItemName()) || getQuantity() == 0) {
            if (m_pNextStation != nullptr) {
                *m_pNextStation += std::move(order);
            } else {
                if (order.isOrderFilled()) {
                    g_completed.push_back(std::move(order));
                } else {
                    g_incomplete.push_back(std::move(order));
                }
            }
            m_orders.pop_front();
            return true;
        }
        return false;
    }
}