#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H

#if __cplusplus < 201700
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;

#else
#include <optional>
using std::optional;
using std::nullopt;
using std::make_optional;
#endif

#include <iostream>

template<typename T>
class SpreadsheetCell {
protected:
    optional<T> value;
    unsigned int numChars;
public:
    SpreadsheetCell() {
        value = nullopt;
        numChars = 10;
    }

    explicit SpreadsheetCell(T value) {
        setValue(value);
        numChars = 10;
    }

    SpreadsheetCell(T value, unsigned int numChars) {
        setValue(value);
        setNumChars(numChars);
    }

    virtual ~SpreadsheetCell() = default;

    optional<T> getValue() const {
        return value;
    }

    void setValue(T value) {
        this->value = make_optional(value);
    }

    void setToNull() {
        value = nullopt;
    }

    int getNumChars() const {
        return numChars;
    }

    void setNumChars(unsigned int numChars) {
        if (numChars == 0) {
            this->numChars = 10;
        } else {
            this->numChars = numChars;
        }
    }

    virtual void printCell(std::ostream& outs) const = 0;
};

#endif
