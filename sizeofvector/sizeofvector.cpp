#include <iostream>
#include <vector>

int main()
{
    std::cout << "Vektor es tomb\n";

    int egesz = 1;
    std::cout << "Size of int: " << sizeof(egesz) << " byte" << std::endl;

    int tombszaz[100];
    std::cout << "Size of array with 100 ints: " << sizeof(tombszaz) << " byte" << std::endl;

    std::vector<double>vektor;
    std::cout << "Size of empty vector: " << sizeof(vektor) << "byte (8*4)" << std::endl;
    for (int i = 0; i < 400000000; i++)
    {
        vektor.push_back(i);
    }
    std::cout << "Let's delete elements!" << std::endl;
    for (int i = 0; i < 400000000; i++)
    {
        vektor.pop_back();
    }
    std::cout << "Done!";
}
