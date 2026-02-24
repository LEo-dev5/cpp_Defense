#include <iostream>
#include <string>


int main() {
    int equipmentID = 707;

    double altitude = 0.0; // Placeholder for altitude value, you can replace it with actual data

    std::string status = "Target Acquired";

    std::cout << "=== Defense System Status ---" << std::endl;
    std::cout << "ID:" << equipmentID << std::endl;
    std::cin >> altitude;
    std::cout << "Altitude:" << altitude << " m" << std::endl;
    std::cout << "Status:" << status << std::endl;

    return 0;
}