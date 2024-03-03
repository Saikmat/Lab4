/*
 * Name: Sai Matukumalli
 * Class: CMSY-171
 * Program name: Lab 4
 * Program Description: This program tracks the name, inventory, and number of sales per day of a given Food item.
 */
#include <iostream>
#include <string>
#include <iomanip>
#include "Food.h"


using namespace std;

const int DEFAULT_START_VALUE = 24;
const int DEFAULT_NUM_OF_DAYS = 7;
const std::string DEFAULT_NAME = "None";

/*
 * No Parameter constructor, sets all values to defaults
 */
Food::Food() { // NOLINT(*-pro-type-member-init) // Functions handle value setting so disregard Clang tidy
    setName(DEFAULT_NAME);
    setStart(DEFAULT_START_VALUE);
    numberOfDaysFoodIsSold = DEFAULT_NUM_OF_DAYS;
    makeArray();
}

/*
 * Constructor that takes the number of days of sales that are made
 * name and starting inventory is set to default
 * int numberOfSales - Takes the number of days during which there are sales
 */
Food::Food(int numberOfSales) { // NOLINT(*-pro-type-member-init)
    // Functions handle value setting so disregard Clang tidy
    setName(DEFAULT_NAME);
    setStart(DEFAULT_START_VALUE);
    this->numberOfDaysFoodIsSold = numberOfSales;
    makeArray();
}

/*
 * Constructor with all parameters
 * string requestedName - name of the item
 * int start - number of items in the initial inventory
 * int numberOfSales - the number of days that the product is sold
 */
Food::Food(string requestedName, int start, int numberOfSales) { // NOLINT(*-pro-type-member-init)
    // Functions handle value setting so disregard Clang tidy
    setName(requestedName);
    setStart(start);
    numberOfDaysFoodIsSold = numberOfSales;
    makeArray();
}

/*
 * Makes a dynamically generated Array of size [numberOfDaysFoodIsSold] and sets all values to 0
 */
void Food::makeArray() {
    salesPerDay = new int[numberOfDaysFoodIsSold];
    for (int i = 0; i < numberOfDaysFoodIsSold; ++i) {
        salesPerDay[i] = 0;
    }
}

/*
 * Calculates the ending inventory based on the provided sales
 */
void Food::calcEnd() {
    int runningEnd = inventoryStartCount;
    for (int i = 0; i < numberOfDaysFoodIsSold; ++i) {
        runningEnd -= salesPerDay[i];
    }
    setEnd(runningEnd);
}

/*
 * Calculates the average number of sales per day
 */
double Food::calcAvg() {
    if (numberOfDaysFoodIsSold == 0) { // Prevent div by 0 error
        return 0; // Allow implicit typecast
    }
    int count = 0;
    for (int i = 0; i < numberOfDaysFoodIsSold; ++i) {
        count += salesPerDay[i];
    }
    return count / (double) numberOfDaysFoodIsSold;
}

/*
 * Sets the name of the item
 * string passedName - sets this.name to the value entered
 */
void Food::setName(string passedName) {
    this->name = passedName;
}

/*
 * Gets the name of the item
 */
string Food::getName() const {
    return this->name;
}

/*
 * Sets the starting inventory if it is within range [24,99]
 * int startValue - value for starting inventory
 */
void Food::setStart(int startValue) {
    if (startValue >= 24 && startValue <= 99) {
        this->inventoryStartCount = startValue;
    } else {
        cerr << "Out of Range Value entered, cannot set inventory value for: " << getName() << endl;
    }
}

/*
 * Gets the starting inventory
 */
int Food::getStart() const {
    return this->inventoryStartCount;
}

/*
 * Sets the value of the ending inventory, as long as it is greater than or equal to 0
 * int endValue - value for the ending inventory
 */
void Food::setEnd(int endValue) {
    if (endValue >= 0) {
        inventoryEndCount = endValue;
    } else {
        cerr << "Negative Value Entered, cannot set inventory value for: " << getName() << endl;
    }
}

/*
 * Returns the final value of inventory
 */
int Food::getEnd() const {
    return this->inventoryEndCount;
}

/*
 * Sets the value of sales at each index of the salesPerDay array
 * int index - the day to select
 * int saleValue - the number of items sold on that day
 */
void Food::setSales(int index, int saleValue) {
    if (index > numberOfDaysFoodIsSold || index < 0) {
        cerr << "Out of Range Index entered, cannot set sale value" << endl;
        return;
    }
    if (saleValue < 1 || saleValue > 99) {
        cerr << "Out of Range Sale Value entered, cannot set sale value" << endl;
        return;
    }
    salesPerDay[index] = saleValue;
}

/*
 * Displays the values of the salesPerDay array
 */
void Food::showSales() {
    for (int i = 0; i < numberOfDaysFoodIsSold; ++i) {
        cout << "Sales on Day " << i + 1 << ": " << salesPerDay[i] << " for item " << getName() << endl;
    }
}

/*
 * Displays all available information about the object when called
 * Items shown are: Name, starting inventory, sales per day, final inventory amount, and the average sold each day
 */
void Food::display() {
    calcEnd();
    cout << "Food Name: " << getName() << endl;
    cout << "Starting inventory: " << getStart() << endl;
    showSales();
    calcEnd();
    cout << "Final inventory amount: " << Food::getEnd() << endl;
    cout << fixed << setprecision(1);
    cout << "The average sold each day is: " << calcAvg() << endl << endl;
}

/*
 * Destroys the int pointer once the obejct falls out of scope
 */
Food::~Food() {
    delete[] salesPerDay;
}
