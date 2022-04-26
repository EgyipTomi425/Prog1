#include <iostream>
#include "Matrix.h"

int main()
{
    std::cout<<"Size of containers:"<<std::endl;
    std::cout<<"Size of char: "<<sizeof(char)<<" byte or "<<sizeof(char)*8<<" bit."<<std::endl;
    std::cout<<"Size of short: "<<sizeof(short)<<" byte or "<<sizeof(short)*8<<" bit."<<std::endl;
    std::cout<<"Size of int: "<<sizeof(int)<<" byte or "<<sizeof(int)*8<<" bit."<<std::endl;
    std::cout<<"Size of long: "<<sizeof(long)<<" byte or "<<sizeof(long)*8<<" bit."<<std::endl;
    std::cout<<"Size of float: "<<sizeof(float)<<" byte or "<<sizeof(float)*8<<" bit."<<std::endl;
    std::cout<<"Size of double: "<<sizeof(double)<<" byte or "<<sizeof(double)*8<<" bit."<<std::endl;
    std::cout<<"Size of int*: "<<sizeof(int*)<<" byte or "<<sizeof(int*)*8<<" bit."<<std::endl;
    std::cout<<"Size of double*: "<<sizeof(double*)<<" byte or "<<sizeof(double*)*8<<" bit."<<std::endl;
    std::cout<<"Size of std::string: "<<sizeof(std::string)<<" byte or "<<sizeof(std::string)*8<<" bit."<<std::endl;
    std::cout<<std::endl;
    Numeric_lib::Matrix<int> a(10);
    std::cout<<"Size of Numeric_lib::Matrix<int> a(10): "<<sizeof(a)<<" byte or "<<sizeof(a)*8<<" bit."<<std::endl;
}
