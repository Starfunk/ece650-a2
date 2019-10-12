
#include <vector>
#include "headers/node.h"

Node::Node(void){}

Node::Node(unsigned num, std::vector<unsigned> vec) {
	id = num;
	std::vector<unsigned> parent_id = vec;
}

unsigned Node::getId(void) {
	return id;
}

std::vector<unsigned> Node::getParentId(void) {
	return parent_id;
}
