#include <iostream>
#include "Matrix.h"
#include <complex>

int main()
{
    std::cout << "Size of containers:" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " byte or " << sizeof(char) * 8 << " bit." << std::endl;
    std::cout << "Size of short: " << sizeof(short) << " byte or " << sizeof(short) * 8 << " bit." << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " byte or " << sizeof(int) * 8 << " bit." << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " byte or " << sizeof(long) * 8 << " bit." << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " byte or " << sizeof(float) * 8 << " bit." << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " byte or " << sizeof(double) * 8 << " bit." << std::endl;
    std::cout << "Size of int*: " << sizeof(int*) << " byte or " << sizeof(int*) * 8 << " bit." << std::endl;
    std::cout << "Size of double*: " << sizeof(double*) << " byte or " << sizeof(double*) * 8 << " bit." << std::endl;
    std::cout << "Size of std::string: " << sizeof(std::string) << " byte or " << sizeof(std::string) * 8 << " bit." << std::endl;
    std::cout << std::endl;

    Numeric_lib::Matrix<int> a(10);
    std::cout << "Size of Numeric_lib::Matrix<int> a(10): " << sizeof(a) << " byte or " << sizeof(a) * 8 << " bit." << std::endl;
    std::cout << "Number of elements: " << a.size() << std::endl;
    Numeric_lib::Matrix<int> b(100);
    std::cout << "Size of Numeric_lib::Matrix<int> b(100): " << sizeof(b) << " byte or " << sizeof(b) * 8 << " bit." << std::endl;
    std::cout << "Number of elements: " << b.size() << std::endl;
    Numeric_lib::Matrix<double> c(10);
    std::cout << "Size of Numeric_lib::Matrix<double> c(10): " << sizeof(c) << " byte or " << sizeof(c) * 8 << " bit." << std::endl;
    std::cout << "Number of elements: " << c.size() << std::endl;
    Numeric_lib::Matrix<double> d1(100);
    std::cout << "Size of Numeric_lib::Matrix<double> d1(100): " << sizeof(d1) << " byte or " << sizeof(d1) * 8 << " bit." << std::endl;
    std::cout << "Number of elements: " << d1.size() << std::endl;
    Numeric_lib::Matrix<int, 2> d(10, 10);
    std::cout << "Size of Numeric_lib::Matrix<int,2> d(10,10): " << sizeof(d) << " byte or " << sizeof(d) * 8 << " bit." << std::endl;
    std::cout << "Number of elements: " << d.size() << std::endl;
    Numeric_lib::Matrix<int, 3> e(10, 10, 10);
    std::cout << "Size of Numeric_lib::Matrix<int,3> e(10,10,10) " << sizeof(e) << " byte or " << sizeof(e) * 8 << " bit." << std::endl;
    std::cout << "Number of elements: " << e.size() << std::endl << std::endl;

    int x;
    std::cout << "Write 3 ints!" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> x;
        std::cout << "sqrt(x) ( if x < 0 -> sqrt(-x) ): " << sqrt(abs(x)) << std::endl;
    }
    std::cout << std::endl;

    float y;
    Numeric_lib::Matrix<double> mymatrix(5);
    std::cout << "Write 5 floats!" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> y;
        mymatrix(i) = y;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Elements of the matrix: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << mymatrix(i) << " " << std::endl;
    }
    std::cout << std::endl;

    x = 11;
    int x2 = 11;
    while (x < 0 || x>10 || x2>10 || x2<0)
    {
        std::cout << "Melyik ket szam szorzatat szeretned? (0-10)" << std::endl;
        std::cin >> x;
        std::cin >> x2;
    }

    std::cout << x << " x " << x2 << " = ";
    Numeric_lib::Matrix<int,2> szorzas(11,11);
    int i = 0;
    int j = 0;
    for (i = 0; i < 11; i = i + 1)
    {
        for (j = 0; j < 11; j = j + 1)
        {
            szorzas(i, j) = i * j;
        }
    }
    //i++ and j++ is not good!!!
    std::cout << szorzas(x, x2) << std::endl << std::endl;

    std::complex<double> sum;
    for (int i = 0; i < 10; ++i) {
        std::complex<double> val;
        std::cin >> val;
        sum += val;
    }
    std::cout << sum << std::endl;

    Numeric_lib::Matrix<int, 2> m(2, 3);
    for (int i = 0; i < 2; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            std::cin >> m[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}