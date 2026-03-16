#include <iostream>
#include <vector>
#include <Eigen/Dense>

int main() {
    std::vector<Eigen::Vector2d> calculated_positions;

    calculated_positions.push_back(Eigen::Vector2d(2.9, 0.1));
    calculated_positions.push_back(Eigen::Vector2d(3.1, -0.1));
    calculated_positions.push_back(Eigen::Vector2d(3.0, 0.0));
    // 테스트용 미친 데이터 추가!
    calculated_positions.push_back(Eigen::Vector2d(100.0, 100.0)); 

    Eigen::Vector2d sum_pos(0, 0);      // 초기화 필수
    int valid_count = 0;               // 유효 데이터 카운터
    Eigen::Vector2d threshosld(3.0, 0.0);
    double max_distance = 5.0;

    for (const auto& pos : calculated_positions) {
        // 거리 계산: 현재 점(pos)과 기준점(threshosld)의 차이의 길이(.norm())
        double distance = (pos - threshosld).norm();

        if (distance < max_distance) {
            sum_pos += pos;
            valid_count++;
        } else {
            std::cout << "⚠️ 경고: 미친 데이터 발견 및 제외! 거리: " << distance << "m" << std::endl;
        }
    }

    // 0으로 나누는 오류 방지 (유효 데이터가 하나도 없을 경우 대비)
    if (valid_count > 0) {
        Eigen::Vector2d final_pos = sum_pos / valid_count;

        std::cout << "\n--- 데이터 융합 결과 ---" << std::endl;
        std::cout << "총 데이터: " << calculated_positions.size() << "개" << std::endl;
        std::cout << "유효 데이터: " << valid_count << "개" << std::endl;
        std::cout << "최종 융합 위치: (" << final_pos.x() << ", " << final_pos.y() << ")" << std::endl;
    } else {
        std::cout << "❌ 신뢰할 수 있는 데이터가 없습니다!" << std::endl;
    }

    return 0;
}