#include <iostream>
#include <cmath>

int main(){
    // 1, 드롬의 레이더 데이터 : 정면 (x)으로 100m 거리 벙커가 있음
    double target_x = 100.0;
    double target_y = 0.0;

    // 2. 드론이 갑자기  왼쪽으로 30도 회전
    double degree = 30.0;
    double radian = degree * (M_PI / 180.0);

    // 3. 삼각 함수를 이용한 좌표 변환 
    // 새로운 x = 기존x * cos - 기존y * sin
    // 새로운 y = 기존x * sin + 기존y * cos
    double new_x = target_x * std::cos(radian) - target_y * std::sin(radian);
    double new_y = target_x * std::sin(radian) + target_y * std::cos(radian);


    std::cout << "--- 드론 탐지 보고서 ---" << std::endl;
    std::cout << "회전 전 벙커 위치: (" << target_x << ", " << target_y << ")" << std::endl;
    std::cout << degree << "도 회전 후 벙커 위치: (" << new_x << ", " << new_y << ")" << std::endl;




    
    return 0;
}