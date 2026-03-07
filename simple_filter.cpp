#include <iostream>
#include <Eigen/Dense>

int main(){
    //현재 추측 위치
    Eigen::Vector2d predicted_pos(4.88, -0.33);

    //외부 센서 측정 위치(측정값)
    Eigen::Vector2d measured_pos(5.02, 0.05);
    
    double k_gain = 0.1;

    Eigen::Vector2d filtered_pos = predicted_pos +k_gain * (measured_pos - predicted_pos);
    
    std::cout << "--- 필터 작전 결과 보고서 ---" << std::endl;
    std::cout << "1. 오차가 쌓인 예측 위치: (" << predicted_pos.x() << ", " << predicted_pos.y() << ")" << std::endl;
    std::cout << "2. 센서가 측정한 위치: (" << measured_pos.x() << ", " << measured_pos.y() << ")" << std::endl;
    std::cout << ">>> 필터가 보정한 최종 위치: (" << filtered_pos.x() << ", " << filtered_pos.y() << ")" << std::endl;

    // 실제 목표였던 (5.0, 0.0)과 얼마나 가까워졌는지 확인
    Eigen::Vector2d goal(5.0, 0.0);
    std::cout << "\n보정 전 오차 거리: " << (goal - predicted_pos).norm() << "m" << std::endl;
    std::cout << "보정 후 오차 거리: " << (goal - filtered_pos).norm() << "m" << std::endl;

    return 0;
}