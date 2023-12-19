#include "date.h"

int main() {
    Date date1(10, 5, 2023);
    Date date2(15, 5, 2023);

    std::cout << "Date 1: " << date1 << std::endl;
    std::cout << "Date 2: " << date2 << std::endl;

    int daysDiff = date2 - date1;
    std::cout << "Difference in days: " << daysDiff << std::endl;

    Date newDate = date1 + 7;
    std::cout << "New date after adding 7 days: " << newDate << std::endl;

    return 0;
}
