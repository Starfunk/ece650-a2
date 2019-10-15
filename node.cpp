#include <iostream>
#include <vector>
#include "headers/node.h"

Node::Node(void){}

Node::Node(unsigned num, std::vector<unsigned> vec) {
	id = num;
	parent_id = vec;
}

unsigned Node::getId(void) {
	return id;
}

std::vector<unsigned> Node::getParentId(void) {
	return parent_id;
}

void Node::printParentId(void) {
	for (unsigned i = 0; i < parent_id.size(); i++) {
		
		if (i == parent_id.size()-1) {
			std::cout << parent_id[i];
		}
		else
			std::cout << parent_id[i] << "-";
	}
	std::cout << "\n";
}