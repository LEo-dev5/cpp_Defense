#include <iostream>
#include <vector>
#include <Eigen/Dense>

int main(){
    std::vector<Eigen::Vector2d> calculated_positions;

    calculated_positions.push_back(Eigen::Vector2d(2.9,0.1));
    calculated_positions.push_back(Eigen::Vector2d(3.1,-0.1));
    calculated_positions.push_back(Eigen::Vector2d(3.0,0.0));

    Eigen::Vector2d sum_pos(0,0);
    for (const auto& pos : calculated_positions) {
            sum_pos += pos;
        }

    // 3. 평균 내기
    Eigen::Vector2d final_pos = sum_pos / calculated_positions.size();

    std::cout << "--- 데이터 융합 결과 ---" << std::endl;
    std::cout << "참고한 점의 개수: " << calculated_positions.size() << "개" << std::endl;
    std::cout << "최종 융합 위치: (" << final_pos.x() << ", " << final_pos.y() << ")" << std::endl;

    return 0;
}