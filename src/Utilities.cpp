//*******************************************
// OOP345 Assignment 4
// File: Utilities.cpp
// Name: Khanh Vy Tran
// Seneca Email: kvtran2@myseneca.ca
// Student ID: 120175245
// Date: 8/2/2026
// Version: 1.0
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to
// complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//*******************************************
#include "Utilities.h"
namespace seneca {
	char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
	}

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        size_t delimiterPosition = str.find(m_delimiter, next_pos);
        if (delimiterPosition == next_pos) {
            more = false;
            throw std::string("Delimiter found at next_pos");
        }
        std::string token{};

        if (delimiterPosition == std::string::npos) {
            token = str.substr(next_pos);
            more = false;
        }
        else {
            token = str.substr(next_pos, delimiterPosition - next_pos);
            next_pos = delimiterPosition + 1;
            more = true;
        }

        size_t firstCharacter = token.find_first_not_of(' ');
        size_t lastCharacter = token.find_last_not_of(' ');

        if (firstCharacter == std::string::npos) {
            token.clear();
        }
        else {
            token = token.substr(firstCharacter, lastCharacter - firstCharacter + 1);
        }

        if (m_widthField < token.length()) {
            m_widthField = token.length();
        }
        return token;
    }

    void Utilities::setDelimiter(char newDelimiter){
		m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter(){
        return m_delimiter;
    }
}
