#include <iomanip>
#include "StringCell.h"
using namespace std;

StringCell::StringCell() : SpreadsheetCell() {
}

StringCell::StringCell(string value) : SpreadsheetCell(value) {
}

void StringCell::printCell(ostream &outs) const {
    if (value) {
        outs << "|" << left << setw(numChars) << *value ;
    } else {
        outs << "|" << left << setw(numChars) << "" ;
    }

}

StringCell operator+(const StringCell &lhs, const StringCell &rhs) {
    StringCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value + *rhs.value);
    } else {
        // One or both of the parameters are nullopt.
        returnVal.setToNull();
    }
    return returnVal;
}

StringCell &StringCell::operator+=(const StringCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value + *rhs.value);
    }
    return *this;
}

StringCell operator*(const StringCell &lhs, const unsigned int &rhs) {
    StringCell returnVal;
    returnVal.setValue("");
    if (lhs.value && rhs) {
        for (int i = 0; i < rhs; ++ i) {
            returnVal+=lhs;
        }
    } else if (!lhs.value) {
        returnVal.setToNull();
    }
    return returnVal;
}

StringCell &StringCell::operator*=(const unsigned int &rhs) {
    optional<string> thisVal = this->getValue();
    string returnStr;
    if (value && rhs) {
        for (int i = 0; i < rhs; ++i) {
            returnStr += thisVal.value();
        }
        this->setValue(returnStr);
    }
    return *this;
}

bool operator==(const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return lhs.value == rhs.value;
    } else if ((!lhs.value)&&(!rhs.value)) {
        return true;
    }
    return false;
}

bool operator!=(const StringCell &lhs, const StringCell &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return lhs.value->length() < rhs.value->length();
    } else if ((!lhs.value)&&(rhs.value)) {
        return true;
    }
    return false;
}

bool operator<=(const StringCell &lhs, const StringCell &rhs) {
    return (lhs < rhs) || (rhs == lhs);
}

bool operator>(const StringCell &lhs, const StringCell &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const StringCell &lhs, const StringCell &rhs) {
    return !(lhs < rhs);
}
