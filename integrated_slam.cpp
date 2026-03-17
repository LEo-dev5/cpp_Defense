#include <iostream>
#include <vector>
#include <Eigen/Dense>

int main() {
    // 1. 초기 환경 설정
    Eigen::Vector2d drone_pos(0.0, 0.0);       // 현재 추정 위치
    Eigen::Matrix2d P = Eigen::Matrix2d::Identity() * 0.1; // 초기 불확실성
    Eigen::Matrix2d Q = Eigen::Matrix2d::Identity() * 0.2; // 이동 노이즈
    Eigen::Matrix2d R = Eigen::Matrix2d::Identity() * 0.1; // 센서 노이즈
    
    // 가상의 랜드마크 (동굴 벽의 특징점들)
    std::vector<Eigen::Vector2d> landmarks = { {5.0, 5.0}, {10.0, 2.0}, {15.0, 8.0} };

    for (int step = 1; step <= 3; ++step) {
        std::cout << "\n==== 작전 Step " << step << " ====" << std::endl;

        // [STEP 1: 예측] 5m씩 전진한다고 가정
        drone_pos.x() += 5.0; 
        P = P + Q; // 이동하며 불안함 증가
        std::cout << "이동 후 추정 위치: (" << drone_pos.x() << ", " << drone_pos.y() << ")" << std::endl;

        // [STEP 2: 관측 및 미친 데이터 필터링]
        std::vector<Eigen::Vector2d> valid_measurements;
        for (const auto& lm : landmarks) {
            // 실제로는 센서가 측정하겠지만, 여기서는 '측정값 = 랜드마크 - 현재위치 + 약간의오차'라고 가정
            Eigen::Vector2d noise(0.05, -0.05); 
            Eigen::Vector2d obs = lm - drone_pos + noise; 
            
            // 거리 기반 필터링 (현재 위치 근처의 점들만 신뢰)
            double dist = (lm - drone_pos).norm();
            if (dist < 15.0) { // 15m 이내의 점만 사용
                valid_measurements.push_back(lm - obs); // 역산한 내 위치 저장
            }
        }

        // [STEP 3: 보정] 살아남은 데이터로 평균을 내고 칼만 업데이트
        if (!valid_measurements.empty()) {
            Eigen::Vector2d mean_pos(0, 0);
            for (const auto& v : valid_measurements) mean_pos += v;
            mean_pos /= valid_measurements.size();

            // 칼만 필터 보정 공식
            Eigen::Matrix2d K = P * (P + R).inverse();
            drone_pos = drone_pos + K * (mean_pos - drone_pos); // 위치 보정
            P = (Eigen::Matrix2d::Identity() - K) * P;          // 공분산 수축

            std::cout << "보정 후 확정 위치: (" << drone_pos.x() << ", " << drone_pos.y() << ")" << std::endl;
            std::cout << "현재 불안 지수(P.norm): " << P.norm() << std::endl;
        }
    }
    return 0;
}