//
// Created by SaiKM on 10/1/2023.
//

#ifndef LAB4_FOOD_H
#define LAB4_FOOD_H

class Food {

private:
    std::string name; // Stores the name of the food item
    int inventoryStartCount; // Stores the starting amount of inventory
    int inventoryEndCount; // Stores the ending amount of inventory
    int *salesPerDay; // Points to a dynamically allocated array with [numberOfDaysFoodIsSold] elements
    int numberOfDaysFoodIsSold = 7; // Stores the number of days that a sale is recorded(7 is given)

    void makeArray();

    void calcEnd();

    double calcAvg();

public:
    Food();

    Food(int);

    Food(std::string, int, int);

    void setName(std::string passedName);

    void setStart(int);

    void setEnd(int);

    void setSales(int, int);

    std::string getName() const;

    int getStart() const;

    int getEnd() const;

    void showSales();

    void display();

    ~Food();

};


#endif //LAB4_FOOD_H
