#include <iostream>
#include <Eigen/Dense>
#include <vector>

int main() {
    // 1. 지도상의 랜드마크들 (점 A, 점 B)
    Eigen::Vector2d landmarkA(5.0, 5.0);
    Eigen::Vector2d landmarkB(1.0, -1.0);

    // 2. 드론 센서의 측정값 (상대 좌표)
    Eigen::Vector2d obsA(2.1, 4.9);   // 점 A를 봤을 때
    Eigen::Vector2d obsB(-1.9, -1.1); // 점 B를 봤을 때

    // 3. 각각의 점으로 계산한 내 위치
    Eigen::Vector2d posA = landmarkA - obsA; // (2.9, 0.1)
    Eigen::Vector2d posB = landmarkB - obsB; // (2.9, 0.1)

    // 4. 평균 내기 (가장 원시적이지만 강력한 보정)
    Eigen::Vector2d final_pos = (posA + posB) / 2.0;

    std::cout << "--- 멀티 랜드마크 보정 작전 ---" << std::endl;
    std::cout << "점 A 기준 위치: (" << posA.x() << ", " << posA.y() << ")" << std::endl;
    std::cout << "점 B 기준 위치: (" << posB.x() << ", " << posB.y() << ")" << std::endl;
    std::cout << ">>> 최종 융합 위치: (" << final_pos.x() << ", " << final_pos.y() << ")" << std::endl;

    return 0;
}