#include <iostream>
#include <random>
#include <Eigen/Dense>

int main() {
    Eigen::Vector2d true_wall(10.0, 0.0);
    // 0.2에서 1.0으로 바꿨을 때 결과가 변하는지 확인하기 위한 부분
    double sigma = 0.2; 

    // 시드(Seed)를 주어 매번 다른 랜덤값이 나오게 합니다.
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::normal_distribution<double> dist(0.0, sigma);

    Eigen::Vector2d sum_points(0, 0);
    std::cout << "--- [NEW] Noisy Sensor (Sigma: " << sigma << ") ---" << std::endl;

    for (int i = 0; i < 10; ++i) {
        Eigen::Vector2d measurement(true_wall.x() + dist(generator), true_wall.y() + dist(generator));
        sum_points += measurement;
        std::cout << i + 1 << "차 측정: (" << measurement.x() << ", " << measurement.y() << ")" << std::endl;
    }

    std::cout << "\n평균 위치: (" << (sum_points/10.0).x() << ", " << (sum_points/10.0).y() << ")" << std::endl;
    return 0;
}