#ifndef INTCELL_H
#define INTCELL_H

#include "DoubleCell.h"
#include "SpreadsheetCell.h"

class IntCell : public SpreadsheetCell<int> {
public:
    /* Constructors */
    IntCell();
    explicit IntCell(int value);

    /* Override pure virtual method from parent */
    void printCell(std::ostream& outs) const override;

    /* Overloaded operators */
    friend IntCell operator + (const IntCell &lhs, const IntCell &rhs);
    IntCell& operator += (const IntCell &rhs);
    friend IntCell operator - (const IntCell &lhs, const IntCell &rhs);
    IntCell& operator -= (const IntCell &rhs);
    friend IntCell operator * (const IntCell &lhs, const IntCell &rhs);
    IntCell& operator *= (const IntCell &rhs);
    // TODO: After implementing DoubleCell, uncomment and implement the following function
    friend optional<DoubleCell> operator / (const IntCell &lhs, const IntCell &rhs);
    IntCell& operator /= (const IntCell &rhs);
    friend bool operator == (const IntCell &lhs, const IntCell &rhs);
    friend bool operator != (const IntCell &lhs, const IntCell &rhs);
    friend bool operator < (const IntCell &lhs, const IntCell &rhs);
    friend bool operator <= (const IntCell &lhs, const IntCell &rhs);
    friend bool operator > (const IntCell &lhs, const IntCell &rhs);
    friend bool operator >= (const IntCell &lhs, const IntCell &rhs);
};

#endif
