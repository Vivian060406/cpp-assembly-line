//*******************************************
// OOP345 Assignment 4
// File: LineManager.cpp
// Name: Khanh Vy Tran
// Seneca Email: kvtran2@myseneca.ca
// Student ID: 120175245
// Date: 8/2/2026
// Version: 1.0
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to
// complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//*******************************************
#include "LineManager.h"
#include "Utilities.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <utility>

namespace seneca {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        std::ifstream inputFile(file);
        if (!inputFile) {
            throw std::string("Unable to open file: " + file);
        }

        Utilities util;
        std::string record;

        while (std::getline(inputFile, record)){
            size_t nextPosition = 0;
            bool more = true;

            const std::string currentName = util.extractToken(record, nextPosition, more);

            auto currentStation = std::find_if(stations.begin(), stations.end(), [currentName](Workstation* station) {
                    return station->getItemName() == currentName;
                }
            );

            if (currentStation == stations.end()){
                throw std::string("Current station not found: " + currentName);
            }

            m_activeLine.push_back(*currentStation);

            if (more) {
                const std::string nextName = util.extractToken(record, nextPosition, more);

                auto nextStation = std::find_if(stations.begin(), stations.end(), [nextName](Workstation* station) {
                        return station->getItemName() == nextName;
                    }
                );

                if (nextStation == stations.end()) {
                    throw std::string("Next station not found: " + nextName);
                }

                (*currentStation)->setNextStation(*nextStation);
            }
        }

        m_cntCustomerOrder = g_pending.size();

        auto firstStation = std::find_if(m_activeLine.begin(), m_activeLine.end(), [this](Workstation* possibleFirst) {
                return std::none_of(m_activeLine.begin(), m_activeLine.end(), [possibleFirst](Workstation* station) {
                        return station->getNextStation() == possibleFirst;
                    }
                );
            }
        );

        if (firstStation == m_activeLine.end()){
            throw std::string("First station not found.");
        }
        m_firstStation = *firstStation;
    }

    void LineManager::reorderStations() {
        std::vector<Workstation*> orderedLine{};

        Workstation* currentStation = m_firstStation;

        while (currentStation != nullptr) {
            orderedLine.push_back(currentStation);
            currentStation = currentStation->getNextStation();
        }
        m_activeLine = std::move(orderedLine);
    }

    bool LineManager::run(std::ostream& os) {
        static size_t iterationCount = 0;

        os << "Line Manager Iteration: "
            << ++iterationCount
            << '\n';

        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* station) {
                station->fill(os);
            }
        );

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [](Workstation* station) {
                station->attemptToMoveOrder();
            }
        );
        return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
    }

    void LineManager::display(std::ostream& os) const {
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* station) {
                station->display(os);
            }
        );
    }
}