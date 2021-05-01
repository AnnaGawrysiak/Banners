#pragma once
#include <vector>

class Banner
{
private:
	int surface;
	int total_maximum_height;
	int surface_of_one_banner;

	int point_of_division;
	int surface_of_the_first_banner;
	int surface_of_the_second_banner;

public:
	Banner();
	int find_point_of_division(std::vector<int> buildings);
	int find_surface(std::vector<int>& buildings);
	
};

