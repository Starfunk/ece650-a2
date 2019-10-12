#ifndef NODE_H
#define NODE_H

class Node {
	public:
	Node();
	Node(unsigned num1, std::vector<unsigned> vec);
	unsigned getId(void);
	std::vector<unsigned> getParentId(void);
	
	private:
	unsigned id; // ID of node.
	std::vector<unsigned> parent_id; // parent_id can be assigned a negative value, thus it is an int.
};

#endif
