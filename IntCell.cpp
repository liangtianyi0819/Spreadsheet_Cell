#include "IntCell.h"
#include <iomanip>
using namespace std;

IntCell::IntCell() : SpreadsheetCell() {
}

IntCell::IntCell(int value) : SpreadsheetCell(value) {
}

void IntCell::printCell(std::ostream& outs) const {
    if (value) {
        outs << "|" << right << setw(numChars) << *value;
    } else {
        outs << "|" << right << setw(numChars) << "";
    }
}

IntCell operator + (const IntCell &lhs, const IntCell &rhs) {
    IntCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value + *rhs.value);
    } else {
        // One or both of the parameters are nullopt.
        returnVal.setToNull();
    }
    return returnVal;
}

IntCell& IntCell::operator += (const IntCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value + *rhs.value);
    }
    return *this;
}

IntCell operator - (const IntCell &lhs, const IntCell &rhs) {
    IntCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value - *rhs.value);
    } else {
        // One or both of the parameters are nullopt.
        returnVal.setToNull();
    }
    return returnVal;
}

IntCell& IntCell::operator -= (const IntCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value - *rhs.value);
    }
    return *this;
}

IntCell operator * (const IntCell &lhs, const IntCell &rhs) {
    IntCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value * *rhs.value);
    } else {
        returnVal.setToNull();
    }
    return returnVal;
}

IntCell& IntCell::operator *= (const IntCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value * *rhs.value);
    }
    return *this;
}

optional<DoubleCell> operator/(const IntCell &lhs, const IntCell &rhs) {
    DoubleCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value / *rhs.value);
    } else {
        returnVal.setToNull();
    }
    return returnVal;
}

IntCell& IntCell::operator /= (const IntCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value && *rhs.value != 0) {
        setValue(*value / *rhs.value);
    }
    return *this;
}


bool operator == (const IntCell &lhs, const IntCell &rhs) {
    if (lhs.value && rhs.value) {
        return (*lhs.value == *rhs.value);
    } else if (!lhs.value && !rhs.value) {
        // both are nullopt, so they are equal
        return true;
    }
    return false;
}

bool operator != (const IntCell &lhs, const IntCell &rhs) {
    return !(lhs == rhs);
}

bool operator < (const IntCell &lhs, const IntCell &rhs) {
    if (lhs.value && rhs.value) {
        return (*lhs.value < *rhs.value);
    } 
    return false;
}

bool operator <= (const IntCell &lhs, const IntCell &rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator > (const IntCell &lhs, const IntCell &rhs) {
    return !(lhs <= rhs);
}

bool operator >= (const IntCell &lhs, const IntCell &rhs) {
    return !(lhs < rhs);
}


