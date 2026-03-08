#include <iostream>
#include <Eigen/Dense>

int main() {
    // 1. [이전 상황] 5단계 이동 후 커져버린 불안함 (P)
    Eigen::Matrix2d P;
    P << 0.7, 0.0,
         0.0, 0.7;
    
    std::cout << "보정 전 불안 지수: " << P.norm() << std::endl;

    // 2. [센서 등장] 센서의 정밀도 (R) 
    // 숫자가 작을수록 아주 정밀한 센서입니다.
    Eigen::Matrix2d R = Eigen::Matrix2d::Identity() * 0.05;

    // 3. [칼만 이득 계산] K = P / (P + R) 
    // 실제로는 역행렬을 곱하지만, 개념적으로는 "전체 오차 중 내 오차의 비중"입니다.
    Eigen::Matrix2d K = P * (P + R).inverse();

    // 4. [공분산 업데이트] P = (I - K) * P
    Eigen::Matrix2d I = Eigen::Matrix2d::Identity();
    P = (I - K) * P;

    std::cout << "--- 센서 보정 완료 ---" << std::endl;
    std::cout << "보정 후 P 행렬:\n" << P << std::endl;
    std::cout << "보정 후 불안 지수: " << P.norm() << std::endl;

    return 0;
}