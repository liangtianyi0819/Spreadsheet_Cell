# Spreadsheet-Cell

Templates and abstract classes and inheritance, oh my!

For this project, you will use C++ template classes with inheritance.

You may work individually or with a partner of your choosing.

## Setup
Use this Guided Project template to create a new repository (see [GitHub-with-CLion](https://github.com/uvmcs120s2021/GitHub-with-CLion) repo for directions).
**Your repository must be named with the convention: Spreadsheet-Cell-netid**, where netid is your UVM NetID username.
* If you are collaborating, the format is Spreadsheet-Cell-netid1-netid2. Have one partner create the repository and give the other partner access on GitHub: on the repository page, go to the Settings tab, choose Manage Access, and add the person with their GitHub username.

Remember to commit and push frequently.

## Starter Code

You are given `SpreadsheetCell`, an abstract template base class that holds an optional template-type field and a number of characters (for formatted printing). Look over this class in `SpreadsheetCell.h`.
* Note that the declarations and definitions are both in the header file. This is because it is much more difficult to separate the code for a template class, so the convention is to use only a header file for template classes.

You are also given an `IntCell` class that inherits from `SpreadsheetCell<int>`. Look over the header and .cpp files for `IntCell` to see the class's functionality.  

## Part I: Inheritance

Write two more subclasses of `SpreadsheetCell`, each in their own header and .cpp files:
* `DoubleCell` inherits from `SpreadsheetCell<double>` and has similar functionality to IntCell. It should overload the / operator as well as the others included in `IntCell`.
    * Note that you also should implement the / operator in the `IntCell` class, which returns an optional `DoubleCell`.
    * Note that doubles should print right-aligned to two decimal places (hint: use `fixed` and `setprecision`).
* `StringCell` inherits from `SpreadsheetCell<string>`. It should overload the +, +=, * with unsigned int (think Python), *=, and the comparison (bool) operators.
    * Note that strings should print left-aligned and should be restricted to fit inside the `numChars` width.

Test your classes in `main.cpp` by creating a testing function for each, like the one provided for `IntCell`.

## Part II: Point to Child Objects

* Declare multiple 2-D vectors of unique pointers, one for each subclass. Push back `make_unique` pointers to the vectors. Make sure you have multiple rows and columns, as this will highlight the formatted printing!

## Part III: Polymorphism

* Declare a template function that takes a two-dimensional vector of Parent unique pointers by reference.
* Implement the function by calling the print method on the objects passed in. Print an endline after each vector/row.
* Call the function in main multiple times, passing it each vector declared in Part II.
* Observe in awe as the polymorphism allows the different types of cells to print in their custom format!

## Grading

This project is due on Gradescope by 11:59pm ET on Friday, March 19th.
* If you are collaborating, both partners have to submit on Gradescope.

### Grading Rubric
- [ ] (12 pts) Part I.
- [ ] (3 pts) Part II.
- [ ] (5 pts) Part III.
