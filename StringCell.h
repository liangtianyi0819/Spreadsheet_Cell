#ifndef SPREADSHEETCELL_STRINGCELL_H
#define SPREADSHEETCELL_STRINGCELL_H

#include "SpreadsheetCell.h"
#include <string>
#include <iostream>

class StringCell : public SpreadsheetCell<std::string> {
public:
    /* Constructors */
    StringCell();
    explicit StringCell(std::string value);

    /* Override pure virtual method from parent */
    void printCell(std::ostream& outs) const override;

    /* Overloaded operators */
    friend StringCell operator + (const StringCell &lhs, const StringCell &rhs);
    StringCell& operator += (const StringCell &rhs);
    friend StringCell operator * (const StringCell &lhs, const unsigned int &rhs);
    StringCell& operator *= (const unsigned int &rhs);
    friend bool operator == (const StringCell &lhs, const StringCell &rhs);
    friend bool operator != (const StringCell &lhs, const StringCell &rhs);
    friend bool operator < (const StringCell &lhs, const StringCell &rhs);
    friend bool operator <= (const StringCell &lhs, const StringCell &rhs);
    friend bool operator > (const StringCell &lhs, const StringCell &rhs);
    friend bool operator >= (const StringCell &lhs, const StringCell &rhs);
};


#endif //SPREADSHEETCELL_STRINGCELL_H
