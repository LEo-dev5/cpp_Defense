#include <iostream>
#include <vector>
#include <cmath>
#include <Eigen/Dense>

int main() {
    // 1. 로봇 상태 (5m 이동, 30도 회전)
    double theta = 30.0 * M_PI / 180.0;
    Eigen::Vector2d robot_pos(5.0, 0.0);

    // 2. 회전 행렬 설정
    Eigen::Matrix2d rotation;
    rotation << std::cos(theta), -std::sin(theta),
                std::sin(theta),  std::cos(theta);

    // 3. 센서 데이터 (3개의 점)
    std::vector<Eigen::Vector2d> sensor_points;
    sensor_points.push_back(Eigen::Vector2d(10.0, 0.0));  // 정면 10m
    sensor_points.push_back(Eigen::Vector2d(3.5, 3.5));   // 대각선
    sensor_points.push_back(Eigen::Vector2d(3.5, -3.5));

    std::cout << "--- Eigen 기반 대량 좌표 변환 결과 ---" << std::endl;

    for (const auto& p_sensor : sensor_points) {
        // 좌표 변환 공식: (회전 * 센서좌표) + 로봇위치
        Eigen::Vector2d p_world = (rotation * p_sensor) + robot_pos;

        std::cout << "센서 기준: (" << p_sensor.x() << ", " << p_sensor.y() 
                  << ") -> 지도 기준: (" << p_world.x() << ", " << p_world.y() << ")" << std::endl;
    }

    return 0;
}