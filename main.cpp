#include <iostream>
#include <string>

int main() {
    int equipmentID = 707;

    double altitude = 0.0;

    std::string status;

    std::cout << "=== CMS (combat Management System) Initializing ===" << std::endl;
    std::cout << "Enter detected target altitude (m): ";

    std::cin >> altitude;

    if (altitude >= 50000.0){
        status = "Space Object Detected";
    }
    else if (altitude >= 30000.0){
        status = "High-Altitude Threat (ICBM suspected)";
    }
    else if(altitude >= 10000.0){
        status = "Standard-Altitude Threat (Fighter Jet)";
    }
    else if (altitude >0.0){
        status = "Low-Altitude Monitoring (UAV/Bird)";
    }


    std::cout << "\n--- Tactical Analysis Result ---" << std::endl;
    std::cout << "Target ID   : " << equipmentID << std::endl;
    std::cout << "Measured Alt : " << altitude << " m" << std::endl;
    std::cout << "System Status : " << status << std::endl;

    return 0;

}