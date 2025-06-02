//#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
#include <iostream>
#include "lib/eigen-3.4.0/Eigen/Dense"
 
using Eigen::MatrixXd;
 
int main()
{   
    MatrixXd n = MatrixXd::Random(3,3);
    MatrixXd m = MatrixXd::Random(3,3);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    MatrixXd d = m*n;
    std::cout << d << std::endl;

}
