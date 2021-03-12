//Napisz funkcjê int banner(vector<int>& H), która maj¹c tablicê H sk³adaj¹c¹ siê z N liczb ca³kowitych, 
//zwraca minimaln¹ ³¹czn¹ powierzchniê co najwy¿ej dwóch banerów, które bêdziemy musieli zamówiæ.

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "Banner.h"

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

int main()
{
    std::vector<int> list_of_buildings; // tablica H 

    int number_of_buildings = random(1, 100000); // liczba budynkow (N) jest liczb¹ ca³kowit¹ z zakresu [1–100 000];

    for (int i = 0; i < number_of_buildings; i++)
    {
        int height = random(1, 10000); // ka¿dy element tablicy jest liczb¹ ca³kowit¹ z zakresu [1..10 000].
        list_of_buildings.push_back(height);

    }


    return 0;
}

int Banner::find_surface(std::vector<int>& buildings)
{

    int total_width = buildings.size();
    auto it = max_element(std::begin(buildings), std::end(buildings));
    int total_maximum_height = *it;
    int one_banner_surface = total_width * total_maximum_height;
    int minimum_surface = one_banner_surface;

    for (std::vector<int>::iterator i1 = buildings.begin(); i1 != buildings.end(); i1++) // begin + 1 (szerokosc to minum 1)
    {
        auto point_of_division_index = std::distance(buildings.begin(), it);

        int height_of_the_first_banner = 0;

        height_of_the_first_banner = *max_element(buildings.begin(), buildings.begin()+ point_of_division_index);

        int surface_of_the_first_banner = height_of_the_first_banner *point_of_division_index;

        int height_of_the_second_banner = 0;
            
        if (height_of_the_first_banner == total_maximum_height)
            {
                //auto it2 = max_element(buildings.begin() + point_of_division_index, buildings.end());
                //height_of_the_second_banner = *it2;
                height_of_the_second_banner = *max_element(buildings.begin() + point_of_division_index, buildings.end());
            }
         else
                height_of_the_second_banner = total_maximum_height;

         int surface_of_the_second_banner = height_of_the_second_banner * (total_width - point_of_division_index);
         
         int surface_of_two_banners = surface_of_the_first_banner + surface_of_the_second_banner;
         
         if (one_banner_surface > surface_of_two_banners)
             minimum_surface = surface_of_two_banners;

    }

    return minimum_surface;
}