/**
 * An example unit test using doctest. See documentation at
 * https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "headers/node.h"
#include "headers/amatrix.h"
#include <vector>

TEST_CASE("Successful Test Example") {
    int a = 5;
    CHECK(a == 5);
}
TEST_CASE("Failing Test Examples") {
    CHECK(true == false);
}


//~ TEST_CASE("Check node Id") {
	//~ std::vector<unsigned> vec;
	//~ vec.push_back(1);
	//~ vec.push_back(3);
	//~ vec.push_back(5);
	//~ Node node(2,vec);
	
	//~ CHECK(2 == node.getId());
//~ }

//~ TEST_CASE("Check node Parent Id") {
	//~ std::vector<unsigned> vec;
	//~ vec.push_back(1);
	//~ vec.push_back(3);
	//~ vec.push_back(5);
	//~ Node node(2,vec);
	
	//~ CHECK(vec == node.getParentId());
//~ }

//~ TEST_CASE("Initialize AMatrix object") {
	
//~ }


