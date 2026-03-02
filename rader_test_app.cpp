#include <iostream>
#include <cmath>

int main(){
    // // 1, 드롬의 레이더 데이터 : 정면 (x)으로 100m 거리 벙커가 있음
    // double target_x = 100.0;
    // double target_y = 0.0;

    // // 2. 드론이 갑자기  왼쪽으로 30도 회전
    // double degree = 30.0;
    // double radian = degree * (M_PI / 180.0);

    // // 3. 삼각 함수를 이용한 좌표 변환 
    // // 새로운 x = 기존x * cos - 기존y * sin
    // // 새로운 y = 기존x * sin + 기존y * cos
    // double new_x = target_x * std::cos(radian) - target_y * std::sin(radian);
    // double new_y = target_x * std::sin(radian) + target_y * std::cos(radian);


    // std::cout << "--- 드론 탐지 보고서 ---" << std::endl;
    // std::cout << "회전 전 벙커 위치: (" << target_x << ", " << target_y << ")" << std::endl;
    // std::cout << degree << "도 회전 후 벙커 위치: (" << new_x << ", " << new_y << ")" << std::endl;
    double robot_x =5.0;
    double robot_y = 0.0;
    double robot_theta = 0.0;

    double sensor_x = 10.0;
    double sensor_y = 0.0;

    double radian = robot_theta * (3.14 / 180.0);
    double cos_val = std::cos(radian);
    double sin_val = std::sin(radian);

    double world_wall_x = (sensor_x * cos_val - sensor_y * sin_val) + robot_x;
    double world_wall_y = (sensor_x * sin_val + sensor_y * cos_val) + robot_y;
    
    std::cout << "--- 실전 좌표 변환 보고서 ---" << std::endl;
    std::cout << "로봇 위치: (" << robot_x << ", " << robot_y << ") 방향: " << robot_theta << "도" << std::endl;
    std::cout << "센서 감지 거리: " << sensor_x << "m" << std::endl;
    std::cout << ">>> 지도의 실제 벽 위치: (" << world_wall_x << ", " << world_wall_y << ")" << std::endl;

    return 0;
}