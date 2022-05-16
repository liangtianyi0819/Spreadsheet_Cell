#include "DoubleCell.h"
#include "IntCell.h"
#include "StringCell.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
using namespace std;

void testIntCell();

void testDoubleCell();

void testStringCell();

template<typename T>
void printCells(vector<vector<unique_ptr<SpreadsheetCell<T>>>> &cells);

int main() {

    testIntCell();
    testDoubleCell();
    testStringCell();

    cout << "Polymorphism: "  << endl;
    vector<vector<unique_ptr<SpreadsheetCell<int>>>> cells;
    vector<unique_ptr<SpreadsheetCell<int>>> row;
    row.push_back(make_unique<IntCell>(500));
    row.push_back(make_unique<IntCell>());
    row.push_back(make_unique<IntCell>(300000));
    row.push_back(make_unique<IntCell>(20000));
    cells.push_back(move(row));
    row.clear();
    row.push_back(make_unique<IntCell>(-5));
    row.push_back(make_unique<IntCell>(90));
    row.push_back(make_unique<IntCell>());
    row.push_back(make_unique<IntCell>(100));
    cells.push_back(move(row));
    row.clear();
    printCells(cells);
    cells.clear();

    // TODO: Create a function to print the 2-D vector
    // It should work for all subclasses of SpreadsheetCell.

    vector<vector<unique_ptr<SpreadsheetCell<double>>>> doubleCells;
    vector<unique_ptr<SpreadsheetCell<double>>> doubleRow;
    doubleRow.push_back(make_unique<DoubleCell>(3.1415));
    doubleRow.push_back(make_unique<DoubleCell>(2.714));
    doubleRow.push_back(make_unique<DoubleCell>(0.001));
    doubleRow.push_back(make_unique<DoubleCell>());
    doubleCells.push_back(move(doubleRow));
    doubleRow.clear();
    doubleRow.push_back(make_unique<DoubleCell>());
    doubleRow.push_back(make_unique<DoubleCell>(2.7182));
    doubleRow.push_back(make_unique<DoubleCell>());
    doubleRow.push_back(make_unique<DoubleCell>(1.732));
    doubleCells.push_back(move(doubleRow));
    doubleRow.clear();
    printCells(doubleCells);
    doubleCells.clear();

    vector<vector<unique_ptr<SpreadsheetCell<string>>>> stringCell;
    vector<unique_ptr<SpreadsheetCell<string>>> stringRow;
    stringRow.push_back(make_unique<StringCell>());
    stringRow.push_back(make_unique<StringCell>("Custom"));
    stringRow.push_back(make_unique<StringCell>("Format"));
    stringRow.push_back(make_unique<StringCell>());
    stringCell.push_back(move(stringRow));
    stringRow.clear();
    stringRow.push_back(make_unique<StringCell>("Different"));
    stringRow.push_back(make_unique<StringCell>("Types"));
    stringRow.push_back(make_unique<StringCell>("of"));
    stringRow.push_back(make_unique<StringCell>("Cells!"));
    stringCell.push_back(move(stringRow));
    stringRow.clear();
    printCells(stringCell);
    stringCell.clear();



    return 0;
}

void testIntCell() {

    IntCell i1;
    IntCell i2(7.9);

    IntCell i3 = i1 + i2;
    if (i3.getValue()) {
        cout << "FAILED nullopt + test case" << endl;
    }
    i3 = i1 - i2;
    if (i3.getValue()) {
        cout << "FAILED nullopt - test case" << endl;
    }
    i3 = i2 * i1;
    if (i3.getValue()) {
        cout << "FAILED nullopt * test case" << endl;
    }
    optional<DoubleCell> d1;
    d1 = i2 / i1;
    if (i3.getValue()) {
        cout << "FAILED nullopt / test case" << endl;
    }
    i3.setValue(4);
    i3 += i2;
    if (i3.getValue() != 11) {
        cout << "FAILED += test case" << endl;
    }
    i3 -= i1;
    if (i3.getValue() != 11) {
        cout << "FAILED -= nullopt test case" << endl;
    }
    i3 *= i2;
    if (i3.getValue() != 77) {
        cout << "FAILED *= test case" << endl;
    }
    i3 /= IntCell(11);
    if (i3.getValue() != 7) {
        cout << "FAILED /= test case" << endl;
    }

    i1.setValue(4);
    cout << "* Testing IntCell print and setNumChars methods *" << endl;
    i1.printCell(cout);
    i2.printCell(cout);
    i1.printCell(cout);
    i2.printCell(cout);

    cout << endl;
    i1.setNumChars(5);
    i2.setNumChars(5);
    i1.printCell(cout);
    i2.printCell(cout);
    i1.printCell(cout);
    i2.printCell(cout);

    cout << endl << "* End testing IntCell print and setNumChars methods *" << endl;

    cout << endl << boolalpha;
    if (i1 == i2) {
        cout << "FAILED == test case" << endl;
    }
    if (!(i1 != i2)) {
        cout << "FAILED != test case" << endl;
    }
    if (!(i1 < i2)) {
        cout << "FAILED < test case" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case" << endl;
    }
    if (i1 > i2) {
        cout << "FAILED > test case" << endl;
    }
    if (i1 >= i2) {
        cout << "FAILED >= test case" << endl;
    }
    i1.setValue(7);
    if (!(i1 == i2)) {
        cout << "FAILED == test case 2" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case 2" << endl;
    }
    if (!(i1 >= i2)) {
        cout << "FAILED >= test case 2" << endl;
    }
}

void testDoubleCell() {

    DoubleCell d1;
    DoubleCell d2(3.14);

    DoubleCell d3 = d1 + d2;
    if (d3.getValue()) {
        cout << "FAILED nullopt + test case" << endl;
    }
    d3 = d1 - d2;
    if (d3.getValue()) {
        cout << "FAILED nullopt - test case" << endl;
    }
    d3 = d2 * d1;
    if (d3.getValue()) {
        cout << "FAILED nullopt * test case" << endl;
    }
    d3.setValue(4.1);
    d3 += d2;
    if (d3.getValue() != 7.24) {
        cout << "FAILED += test case" << endl;
    }
    d3 -= d1;
    if (d3.getValue() != 7.24) {
        cout << "FAILED -= nullopt test case" << endl;
    }
    d3.setValue(7.24);
    d2.setValue(2.555);
    d3 *= d2;
    if (d3.getValue() != 18.4982) {
        cout << "FAILED *= test case" << endl;
    }
    d3 /= DoubleCell(0.5);
    if (d3.getValue() != 36.9964) {
        cout << "FAILED /= test case" << endl;
    }
    d1.setValue(3.1415926);
    cout << "* Testing DoubleCell print and setNumChars methods *" << endl;
    d1.printCell(cout);
    d2.printCell(cout);
    d1.printCell(cout);
    d2.printCell(cout);

    cout << endl;
    d1.setNumChars(5);
    d2.setNumChars(5);
    d1.printCell(cout);
    d2.printCell(cout);
    d1.printCell(cout);
    d2.printCell(cout);
    cout << endl << "* End testing DoubleCell print and setNumChars methods *" << endl;

    cout << endl << boolalpha;

    // d1 = 3.1415926
    // d2 = 2.555
    if (d1 == d2) {
        cout << "FAILED == test case" << endl;
    }
    if (!(d1 != d2)) {
        cout << "FAILED != test case" << endl;
    }
    if (d1 < d2) {
        cout << "FAILED < test case" << endl;
    }
    if (d1 <= d2) {
        cout << "FAILED <= test case" << endl;
    }
    if (!(d1 > d2)) {
        cout << "FAILED > test case" << endl;
    }
    if (!(d1 >= d2)) {
        cout << "FAILED >= test case" << endl;
    }
    d2.setValue(3.1415926);
    if (!(d1 == d2)) {
        cout << "FAILED == test case 2" << endl;
    }
    if (!(d1 <= d2)) {
        cout << "FAILED <= test case 2" << endl;
    }
    if (!(d1 >= d2)) {
        cout << "FAILED >= test case 2" << endl;
    }
}

void testStringCell () {
    StringCell s1;
    StringCell s2("Spreadsheet");

    StringCell s3 = s1 + s2;
    if (s3.getValue()) {
        cout << "FAILED nullopt + test case" << endl;
    }

    s3 = s1 * 3;
    if (s3.getValue()) {
        cout << "FAILED nullopt * test case" << endl;
    }

    s3.setValue("String");
    s3 += s2;
    if (s3.getValue() != "StringSpreadsheet") {
        cout << "FAILED += test case" << endl;
    }
    s3.setValue("ab");
    s3 *= 3;

    if (s3.getValue().value() != ("ababab")) {
        cout << "FAILED *= test case" << endl;
    }

    s1.setValue("This ");
    s2.setValue("is ");
    s3.setValue("a ");
    StringCell s4;
    StringCell s5;
    StringCell s6;
    s4.setValue("String ");
    s5.setValue("Spread");
    s6.setValue("sheet");
    cout << "* Testing StringCell print and setNumChars methods *" << endl;
    s1.printCell(cout);
    s2.printCell(cout);
    s3.printCell(cout);
    StringCell("String").printCell(cout);
    StringCell("Spreadsheet").printCell(cout);

    cout << endl;
    s1.setNumChars(5);
    s2.setNumChars(5);
    s3.setNumChars(5);
    s4.setNumChars(5);
    s5.setNumChars(5);
    s6.setNumChars(5);
    s1.printCell(cout);
    s2.printCell(cout);
    s3.printCell(cout);
    s4.printCell(cout);
    s5.printCell(cout);
    s6.printCell(cout);

    cout << endl << "* End testing StringCell print and setNumChars methods *" << endl;
    s1.setValue("a");
    s2.setValue("ab");
    cout << endl << boolalpha;
    if (s1 == s2) {
        cout << "FAILED == test case" << endl;
    }
    if (!(s1 != s2)) {
        cout << "FAILED != test case" << endl;
    }
    if (!(s1 < s2)) {
        cout << "FAILED < test case" << endl;
    }
    if (!(s1 <= s2)) {
        cout << "FAILED <= test case" << endl;
    }
    if (s1 > s2) {
        cout << "FAILED > test case" << endl;
    }
    if (s1 >= s2) {
        cout << "FAILED >= test case" << endl;
    }
    s1.setValue("ab");
    if (!(s1 == s2)) {
        cout << "FAILED == test case 2" << endl;
    }
    if (!(s1 <= s2)) {
        cout << "FAILED <= test case 2" << endl;
    }
    if (!(s1 >= s2)) {
        cout << "FAILED >= test case 2" << endl;
    }
}

template<typename T>
void printCells(vector<vector<unique_ptr<SpreadsheetCell<T>>>> &cells) {
    int i = 0;
    for (; i < cells.size(); ++i) {
        for (const auto& j : cells[i]) {
            j->printCell(cout);
        }
        cout << endl;
    }
}