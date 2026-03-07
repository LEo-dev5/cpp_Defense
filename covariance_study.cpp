#include <iostream>
#include <Eigen/Dense>

int main(){

    Eigen::Matrix2d P = Eigen::Matrix2d::Identity() * 0.1;
    Eigen::Matrix2d Q = Eigen::Matrix2d::Identity() * 0.5;


    std::cout <<"--- 작전 시작:: 초기 불확실성 ---" << std::endl;
    std::cout <<P<< std::endl;

    for (int i = 0 ; i <=5; ++i){
        P = P + Q;

        std::cout << "\n[" << i << "단계 이동 후] 구름(불확실성)의 크기:" << std::endl;
        std::cout << P << std::endl;
        
        // .norm()을 통해 이 '불안함'을 하나의 숫자로 측정해봅니다.
        std::cout << "현재 불안 지수: " << P.norm() << std::endl;
    }

    return 0;
}