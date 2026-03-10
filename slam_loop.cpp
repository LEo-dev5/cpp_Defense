#include <iostream>
#include <Eigen/Dense>
#include <vector>   

int main() {
    Eigen::Matrix2d P = Eigen::Matrix2d::Identity() * 0.1;
    Eigen::Matrix2d Q = Eigen::Matrix2d::Identity() * 0.3;
    Eigen::Matrix2d R = Eigen::Matrix2d::Identity() * 0.5;
    Eigen::Matrix2d I = Eigen::Matrix2d::Identity();

    std::cout << " --- 자율주행 작전 개시 --- " << std::endl;

    for (int step = 1; step <= 5; ++step) {
        std::cout << "\n[Step " << step << " ] " << std::endl;
        // 1. 이동 후 불안함 증가
        P = P + Q;
        std::cout << "이동 후 불안 지수: " << P.norm() << "(상승)" << std::endl;

        Eigen::Matrix2d L =P * (P+R).inverse();
        P = (I - L) * P;
        std::cout << "센서 보정 후 불안 지수: " << P.norm() << "(하락)" << std::endl;
    }
}