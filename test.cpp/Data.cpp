#include "Data.h"
#include <iostream>
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}
void Date::display() { 
    std::cout << year << "-" << month << "-" << day << std::endl; 
}
int main() {
    Date d(2023, 10, 1);
    d.display();
    return 0;
}