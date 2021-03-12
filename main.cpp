//Napisz funkcjê int banner(vector<int>& H), która maj¹c tablicê H sk³adaj¹c¹ siê z N liczb ca³kowitych, 
//zwraca minimaln¹ ³¹czn¹ powierzchniê co najwy¿ej dwóch banerów, które bêdziemy musieli zamówiæ.

#include <iostream>
#include <chrono>
#include <random>
#include <vector>

bool test1();

bool test2();

std::mt19937& rng()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 g(seed);
    return g;
}

int random(int min, int max)
{
    std::uniform_real_distribution <double> d(min, max);
    return d(rng());
}

int find_surface(std::vector<int>& buildings);

int main()
{
    std::vector<int> list_of_buildings; // tablica H 

    int number_of_buildings = random(1, 100000); // liczba budynkow (N) jest liczb¹ ca³kowit¹ z zakresu [1–100 000];

    for (int i = 0; i < number_of_buildings; i++)
    {
        int height = random(1, 10000); // ka¿dy element tablicy jest liczb¹ ca³kowit¹ z zakresu [1..10 000].
        list_of_buildings.push_back(height);
    }

    std::cout<< " Minimum surface needed to cover the buildings: " << find_surface(list_of_buildings) << std::endl;

    if (test1())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (test2())
        std::cout << "Test 2: Success! " << std::endl;
    else
        std::cout << "Test 2: Failure " << std::endl;

    return 0;
}

int find_surface(std::vector<int>& buildings)
{

    int total_width = buildings.size();
    int total_maximum_height = *max_element(buildings.begin(), buildings.end());

    int one_banner_surface = total_width * total_maximum_height;

    int minimum_surface = one_banner_surface;

    for (std::vector<int>::iterator i1 = buildings.begin()+1; i1 != buildings.end(); i1++) // begin + 1 (szerokosc to minum 1)
    {
        int point_of_division_index = std::distance(buildings.begin(), i1);

        int height_of_the_first_banner = *max_element(buildings.begin(), buildings.begin()+ point_of_division_index);

        int surface_of_the_first_banner = height_of_the_first_banner * point_of_division_index;

        int height_of_the_second_banner = 0;
            
        if (height_of_the_first_banner == total_maximum_height)
                height_of_the_second_banner = *max_element(buildings.begin() + point_of_division_index, buildings.end());
         else
                height_of_the_second_banner = total_maximum_height;

         int surface_of_the_second_banner = height_of_the_second_banner * (total_width - point_of_division_index);
         
         int surface_of_two_banners = surface_of_the_first_banner + surface_of_the_second_banner;
         
         if (minimum_surface > surface_of_two_banners)
             minimum_surface = surface_of_two_banners;
    }

    return minimum_surface;
}

bool test1()
{
    std::vector<int> buildings;
    buildings.push_back(3);
    buildings.push_back(1);
    buildings.push_back(4);

    const int expected_result = 10;

    int result = find_surface(buildings);

    if (result == expected_result)
        return true;

    return false;
}


bool test2()
{
    std::vector<int> buildings;
    buildings.push_back(5);
    buildings.push_back(3);
    buildings.push_back(5);
    buildings.push_back(2);
    buildings.push_back(1);

    const int expected_result = 19;

    int result = find_surface(buildings);

    if (result == expected_result)
        return true;

    return false;

}
