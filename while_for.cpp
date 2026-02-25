#include <iostream>
#include <string>

int main() {
    double altitude = 0.0;
    bool isRunning = true; // 시스템 가동 상태 여부

    std::cout << "=== Air Defense Radar System Active ===" << std::endl;
    std::cout <<"(Enter -1 to shut down system)" << std::endl;

    while (isRunning){
        std::cout << "\nScanning for targets... Input Altitude (m): " ;
        std::cin >> altitude;

        if (altitude == -1){
            std::cout << "[SYSTEM] Shutting down CMS..." << std::endl;
            isRunning = false; // 시스템 종료
            continue;
        }

        std::string status;
        if(altitude >= 50000.0) status = "Space Object Detected";
        else if (altitude >=30000.0) status = "High-Altitude Threat";
        else if (altitude >=10000.0) status = "Standard Threat";
        else status = " Low-Altitude/Ground";
        
        std::cout << ">>> Analysis Result: " << status << std::endl;
    }

    return 0;
}