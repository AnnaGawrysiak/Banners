#include "Banner.h"
#include <iostream>
#include <vector>

Banner::Banner()
{

}

int Banner::find_surface(std::vector<int>& buildings)
{
    auto it = max_element(std::begin(buildings), std::end(buildings));

    int total_maximum_height = *it;

    int one_banner_surface = buildings.size()* total_maximum_height;

    for (std::vector<int>::iterator i1 = buildings.begin(); i1 != buildings.end(); i1++)
    {
        int height_of_the_first_banner = 0;

        auto point_of_division_index = std::distance(buildings.begin(), it);

        if (height_of_the_first_banner != total_maximum_height)
        {
            auto it2 = max_element(point_of_division_index, std::end(buildings));

            height_of_the_first_banner = *it2*(buildings.size());
        }
           
        int surface_of_the_first_banner = *it *

        int height_of_the_second_banner = 0;

    }

    std::vector<int> first_banner_surface;
    first_banner_surface.reserve(buildings.size());

    std::vector<int> second_banner_surface;
    second_banner_surface.reserve(buildings.size());

    return surface;
}

int Banner::find_surface(std::vector<int>& buildings)
{

}