#include <iostream>
#include <Eigen/Dense>

int main() {
    // 1. 지도에 등록된 랜드마크(빨간 점)의 절대 위치
    Eigen::Vector2d landmark_pos(5.0, 5.0); 

    // 2. 드론의 센서가 측정한 '나와 점 사이의 거리'(상대 좌표)
    // 센서는 "내 기준으로 점이 (2.1, 4.9)에 있어"라고 말합니다.
    Eigen::Vector2d relative_obs(2.1, 4.9);

    // 3. 역산: 내 위치 = 랜드마크 위치 - 상대 측정값
    // 오타 수정: relavie_obs -> relative_obs
    Eigen::Vector2d estimated_drone_pos = landmark_pos - relative_obs;

    std::cout << "--- 랜드마크 기반 위치 추정 ---" << std::endl;
    std::cout << "고정된 점의 위치: (" << landmark_pos.x() << ", " << landmark_pos.y() << ")" << std::endl;
    std::cout << "센서 측정값(상대): (" << relative_obs.x() << ", " << relative_obs.y() << ")" << std::endl;
    std::cout << ">>> 계산된 드론의 현재 위치: (" << estimated_drone_pos.x() << ", " << estimated_drone_pos.y() << ")" << std::endl;

    return 0;
}