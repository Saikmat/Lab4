#include <iostream>
#include "Food.h"

using namespace std;

int main() {
    Food *food1 = new Food();
    Food *food2 = new Food(7);
    Food *food3 = new Food("Tossed Salad", 75, 7);
    food1->display();
    food2->display();
    food3->display();

    // Sandwiches
    food1->setName("Sandwiches");
    food1->setStart(90);
    food1->setSales(0, 7);
    food1->setStart(200); // Error 1
    food1->setSales(1, 8);
    food1->setSales(2, 9);
    food1->setSales(3, 10);
    food1->setSales(4, 10);
    food1->setSales(5, 5);
    food1->setSales(6, 12);
    food1->display();

    // Beverages
    food2->setName("Beverages");
    food2->setStart(80);
    food2->setSales(0, 10);
    food2->setSales(1, 10);
    food2->setSales(2, 12);
    food2->setSales(3, 10);
    food2->setSales(4, 12);
    food2->setSales(5, 11);
    food2->setSales(6, 12);
    food2->display();

    // Tossed Salad
    food3->setSales(0, 4);
    food3->setSales(1, 6);
    food3->setSales(2, 2);
    food3->setSales(3, 3);
    food3->setSales(4, 4);
    food2->setSales(5, 105); //Error 2
    food2->setSales(-4, -105); // Error 3
    food3->setSales(5, 7);
    food3->setSales(6, 3);
    food3->display();

    return 0;
}