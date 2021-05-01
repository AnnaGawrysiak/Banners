//Napisz funkcjê int banner(vector<int>& H), która maj¹c tablicê H sk³adaj¹c¹ siê z N liczb ca³kowitych, 
//zwraca minimaln¹ ³¹czn¹ powierzchniê co najwy¿ej dwóch banerów, które bêdziemy musieli zamówiæ.

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <iomanip>

bool test1();

bool test2();

bool TestSingleElement();

bool TestOneMaxValueInMiddle();

bool TestOneMaxValueAtBegin();

bool TestOneMaxValueAtEnd();

bool TestMoreMaxValuesInMiddle();

bool TestMoreMaxValuesAtBegin();

bool TestMoreMaxValuesAtEnd();

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
    //std::vector<int> list_of_buildings; // tablica H 

    //int number_of_buildings = random(1, 100000); // liczba budynkow (N) jest liczb¹ ca³kowit¹ z zakresu [1–100 000];

    //for (int i = 0; i < number_of_buildings; i++)
    //{
      //  int height = random(1, 10000); // ka¿dy element tablicy jest liczb¹ ca³kowit¹ z zakresu [1..10 000].
      //  list_of_buildings.push_back(height);
    //}

   // std::cout<< " Minimum surface needed to cover the buildings: " << find_surface(list_of_buildings) << std::endl;

    if (test1())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (test2())
        std::cout << "Test 2: Success! " << std::endl;
    else
        std::cout << "Test 2: Failure " << std::endl;


    if (TestSingleElement())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (TestOneMaxValueInMiddle())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (TestOneMaxValueAtBegin())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (TestOneMaxValueAtEnd())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (TestMoreMaxValuesInMiddle())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (TestMoreMaxValuesAtBegin())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    if (TestMoreMaxValuesAtEnd())
        std::cout << "Test 1: Success! " << std::endl;
    else
        std::cout << "Test 1: Failure " << std::endl;

    std::vector<int> B = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

    for (auto building_height : B)
    {
        std::vector<int> H{};
        int number_of_buildings = building_height;

        for (int i = 0; i < number_of_buildings; i++)
            H.push_back(random(1, 10000));

        auto start = std::chrono::high_resolution_clock::now();
        find_surface(H);
        auto finish = std::chrono::high_resolution_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
        //std::cout << std::fixed << std::setprecision(9) << std::left;
        std::cout << "Test time of execution for: " << number_of_buildings << " elements: " << std::chrono::nanoseconds(finish - start).count() / 1000 << " [us]" << std::endl;
    }

    return 0;
}

int find_surface(std::vector<int>& buildings)
{

    int total_width = buildings.size();
    int total_maximum_height = *max_element(buildings.begin(), buildings.end());

    int one_banner_surface = total_width * total_maximum_height;

    int point_of_division = 1;
    int surface = one_banner_surface;
    
    int current_summit_left = 0;
    int current_summit_right = 0;

    for (int i = 0; i < total_width; i++)
    {
        
        if (buildings.at(i) == total_maximum_height)
            break;
        
        if (buildings.at(i) > current_summit_left)
            current_summit_left = buildings.at(i);
       
        int current_surface = one_banner_surface - (total_maximum_height - current_summit_left)*(i +1);

        if (surface > current_surface)
            surface = current_surface;
    }

    for (int i = (total_width-1); i >= 0; i--)
    {

        if (buildings.at(i) == total_maximum_height)
            break;

        if (buildings.at(i) > current_summit_right)
            current_summit_right = buildings.at(i);

        int current_surface = one_banner_surface - (total_maximum_height - current_summit_right) * (total_width - i);

        if (surface > current_surface)
            surface = current_surface;
    }
   
    return surface;
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

bool TestSingleElement()
{
    std::vector<int> H = { 5 };
    int expected_result = 5;
    int result = find_surface(H);

    return (expected_result == result) ? true : false;
}

bool TestOneMaxValueInMiddle()
{
    std::vector<int> H = { 2, 3, 1, 5, 3, 4, 3 };
    int expected_result = 9 + 20;
    int result = find_surface(H);

    return (expected_result == result) ? true : false;
}

bool TestOneMaxValueAtBegin()
{
    std::vector<int> H = { 5, 4, 2 };
    int expected_result = 12;
    int result = find_surface(H);

    return (expected_result == result) ? true : false;
}

bool TestOneMaxValueAtEnd()
{
    std::vector<int> H = { 2, 4, 5 };
    int expected_result = 12;
    int result = find_surface(H);

    return (expected_result == result) ? true : false;
}

bool TestMoreMaxValuesInMiddle()
{
    std::vector<int> H = { 2, 3, 5, 2, 5, 4 };
    int expected_result = 6 + 20;
    int result = find_surface(H);

    return (expected_result == result) ? true : false;
}

bool TestMoreMaxValuesAtBegin()
{
    std::vector<int> H = { 5, 2, 5, 3, 3 };
    int expected_result = 15 + 6;
    int result = find_surface(H);

    return (expected_result == result) ? true : false;
}

bool TestMoreMaxValuesAtEnd()
{
    std::vector<int> H = { 3, 3, 5, 2, 5 };
    int expected_result = 15 + 6;
    int result = find_surface(H);

    return (expected_result == result) ? true : false;
}