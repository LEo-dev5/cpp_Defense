#include <iostream>
#include <random>
#include <Eigen/Dense>

Eigen::Vector2d apply_noise(Eigen::Vector2d move_step, double sigma){
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::normal_distribution<double> dist(0.0, sigma);
    double noise_x = dist(gen);
    double noise_y = dist(gen);

    Eigen::Vector2d actual_move(move_step.x() + noise_x, move_step.y() + noise_y);

    return actual_move;
}   

int main(){
    Eigen::Vector2d current_pos(0.0,0.0);
    
    for (int i = 1; i <=5; ++i){
        Eigen::Vector2d result = apply_noise(Eigen::Vector2d(1.0, 0.0), 0.1);
        current_pos += result;
        std::cout << "결과 : (" << result.x() << ", " << result.y() << ")" << std::endl;
    }
    std::cout << "(5.0,0.0) 과 비교 : (" << current_pos.x() << "," << current_pos.y() << ")" << std::endl;
    return 0;
}