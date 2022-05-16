#include "DoubleCell.h"
#include <iomanip>

using namespace std;

DoubleCell::DoubleCell() : SpreadsheetCell() {
}

DoubleCell::DoubleCell(double value) : SpreadsheetCell(value) {

}

void DoubleCell::printCell(std::ostream &outs) const {
    outs.precision(2);
    if (value) {
        outs << fixed;
        outs << "|" << right << setw(numChars) << *value;
    } else {
        outs << fixed;
        outs << "|" << right << setw(numChars) << "";
    }
}

DoubleCell operator + (const DoubleCell &lhs, const DoubleCell &rhs) {
    DoubleCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value + *rhs.value);
    } else {
        // One or both of the parameters are nullopt.
        returnVal.setToNull();
    }
    return returnVal;
}

DoubleCell &DoubleCell::operator+=(const DoubleCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value + *rhs.value);
    }
    return *this;
}

DoubleCell operator-(const DoubleCell &lhs, const DoubleCell &rhs) {
    DoubleCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value - *rhs.value);
    } else {
        // One or both of the parameters are nullopt.
        returnVal.setToNull();
    }
    return returnVal;
}

DoubleCell &DoubleCell::operator-=(const DoubleCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value - *rhs.value);
    }
    return *this;
}

DoubleCell operator*(const DoubleCell &lhs, const DoubleCell &rhs) {
    DoubleCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value * *rhs.value);
    } else {
        returnVal.setToNull();
    }
    return returnVal;
}

DoubleCell &DoubleCell::operator*=(const DoubleCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        this->setValue((*value * *rhs.value));
    }
    return *this;
}

optional<DoubleCell> operator/(const DoubleCell &lhs, const DoubleCell &rhs)  {
    DoubleCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value * *rhs.value);
    } else {
        returnVal.setToNull();
    }
    return returnVal;
}

DoubleCell &DoubleCell::operator/=(const DoubleCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value && *rhs.value != 0) {
        setValue(*value / *rhs.value);
    }
    return *this;
}

bool operator==(const DoubleCell &lhs, const DoubleCell &rhs) {
    if (lhs.value && rhs.value) {
        return (*lhs.value == *rhs.value);
    } else if (!lhs.value && !rhs.value) {
        // both are nullopt, so they are equal
        return true;
    }
    return false;
}

bool operator!=(const DoubleCell &lhs, const DoubleCell &rhs) {
    return !(lhs == rhs);
}

bool operator<(const DoubleCell &lhs, const DoubleCell &rhs) {
    if (lhs.value && rhs.value) {
        return (*lhs.value < *rhs.value);
    }
    return false;
}

bool operator<=(const DoubleCell &lhs, const DoubleCell &rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator>(const DoubleCell &lhs, const DoubleCell &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const DoubleCell &lhs, const DoubleCell &rhs) {
    return !(lhs < rhs);
}

