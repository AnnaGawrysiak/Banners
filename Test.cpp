#include "Test.h"
#include "Banner.h"
#include <iostream>

Test::Test()
{
}

Test* Test::wsk = nullptr;

Test* Test::get_instance()
{
	if (!wsk)
		wsk = new Test();

	return wsk;

}

//bool Test::test1()
//{
	/*
	
	const std::string cypher = "abc";
	const std::string expected_result = "def";


	const int overlap = 3;

	First_Cylinder* first = new First_Cylinder(overlap, cypher);
	first->rotate();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
	*/
//}


//bool Test::test2()
//{
	/*
	std::string cypher = "xyz";
	std::string expected_result = "abc";

	Caesar test(cypher);

	int overlap = 3;

	First_Cylinder* first = new First_Cylinder(overlap, cypher);
	first->rotate();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
	*/

//}

void Test::run()
{
	/*
	if (test1())
		std::cout << "Test 1: Sukces! " << std::endl;
	else
		std::cout << "Test 1: Porazka " << std::endl;

	if (test2())
		std::cout << "Test 2: Sukces! " << std::endl;
	else
		std::cout << "Test 2: Porazka " << std::endl;
	*/


}