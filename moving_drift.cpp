#include <iostream>
#include <random>
#include <Eigen/Dense>

int main() {
    // 1. 로봇의 시작 위치 (0, 0)
    Eigen::Vector2d current_pos(0.0, 0.0);
    
    // 2. 오차 주머니 (표준편차 0.1m)
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::normal_distribution<double> dist(0.0, 0.1);

    // 3. 이동 명령 (한 번에 1m씩 5번 가라!)
    Eigen::Vector2d move_step(1.0, 0.0);

    std::cout << "--- 로봇 이동 작전 개시 ---" << std::endl;
    std::cout << "출발점: (" << current_pos.x() << ", " << current_pos.y() << ")" << std::endl;

    for (int i = 1; i <= 5; ++i) {
        // [핵심] 실제 이동 = 명령(1m) + 랜덤 오차
        double noise_x = dist(gen);
        double noise_y = dist(gen);
        Eigen::Vector2d actual_move(move_step.x() + noise_x, move_step.y() + noise_y);

        // 로봇 위치 업데이트 (누적해서 더하기)
        current_pos += actual_move;

        std::cout << i << "단계 이동 후 위치: (" << current_pos.x() << ", " << current_pos.y() << ")" << std::endl;
    }

    std::cout << "\n최종 목적지 도달!" << std::endl;
    std::cout << "이론상 위치는 (5, 0)이어야 하지만, 실제로는 어떤가요?" << std::endl;

    return 0;
}