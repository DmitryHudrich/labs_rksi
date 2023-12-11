#include <iostream>
#include <string>

#include "program.h"

int main() {
    X x(10, 20);

    Y y(20, 10, 2);
    auto result = y.Run();
    std::cout << result << std::endl;
}