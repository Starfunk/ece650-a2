#include <vector>
#include <iostream>
#include "headers/node.h"
#include "headers/amatrix.h"

AMatrix::AMatrix(void){}

AMatrix::AMatrix(unsigned num) {
	number_of_vertices = num;
	// Resize matrix based on the number of vertices.
	matrix.resize(number_of_vertices,
		std::vector<unsigned>(number_of_vertices));
}

void AMatrix::setMatrix(unsigned num) {
	number_of_vertices = num;
	// Resize matrix based on the number of vertices.
	matrix.resize(number_of_vertices,
		std::vector<unsigned>(number_of_vertices));
}

void AMatrix::assignEdge(std::vector<unsigned> vec) {
	for (int i = 0; i < vec.size() - 1; i = i + 2) {
		matrix[vec[i]][vec[i + 1]] = 1;
		matrix[vec[i + 1]][vec[i]] = 1;      
	}  	
}


void AMatrix::printShortestPath(void) {
	unsigned n = visited_nodes.size();
	Node parent_id = visited_nodes[n-1];
	parent_id.printParentId();

}

void AMatrix::printVisitedNodes(void) {
	for (Node node : visited_nodes) {
		std::cout << "Node " << node.getId() << ":";
		node.printParentId();
	}
}

void AMatrix::printMatrix(void) {
	for (int i = 0; i < number_of_vertices; i++) {
		std::cout << "[";
		for (int j = 0; j < number_of_vertices; j++) {
			if (j != number_of_vertices - 1) {
				std::cout << matrix[i][j] << " ";
			}
			else
				std::cout << matrix[i][j];
				
			if (j == number_of_vertices - 1) {
					std::cout << "]";
			}
		}
		std::cout << "\n";
	}
}

unsigned AMatrix::getVertexCount(void) {
	return number_of_vertices;
}

std::vector< std::vector<unsigned> > AMatrix::getMatrix(void) {
	return matrix;
}

bool AMatrix::is_in_visited_vertices(unsigned num) {
	if (std::find(visited_vertices.begin(), 
		visited_vertices.end(), num) != visited_vertices.end()) {
		return true;
	}
	else
		return false;
}

// returns the node parent_id from visited_nodes with id
std::vector<unsigned> AMatrix::findNode(unsigned id) {
	for (Node node : visited_nodes) {
		if (node.getId() == id) {
			return node.getParentId();
		}
	}
	
	std::cerr << "Error: node not in visited_nodes.";
	std::vector<unsigned> null;
	return null;
}

void AMatrix::resetAMatrix(void) {
	visited_nodes.clear();
	visited_vertices.clear();
	to_visit1.clear();
	to_visit2.clear();
}

bool AMatrix::find_shorted_path(unsigned s, unsigned t) {
	bool t_found = false;
	if (s > number_of_vertices - 1 or t > number_of_vertices - 1) {
			std::cout << number_of_vertices;
			std::cerr << "Error: s or t is an invalid number";
			return false;
		}
	else if (s == t) {
		std::cout << t << "-" << t << "\n";
		return true;
	}
	
	std::vector<unsigned> parent_id;
	parent_id.push_back(s);
	Node node_s(s,parent_id);
	visited_nodes.push_back(node_s);
	visited_vertices.push_back(s);

	
	//~ unsigned n = visited_nodes.size();
	//~ Node parent_id1 = visited_nodes[n-1];
	//~ parent_id1.printParentId();
	
	std::cout << "Before s row\n";
	printVisitedNodes();
	
	// Only for s row
	for (unsigned index = 0; index < number_of_vertices; index++) {
		if (matrix[s][index] == 1) {
			if (index == t) {
				std::vector<unsigned> parent_id 
					= visited_nodes[0].getParentId();
				parent_id.push_back(index); // the first node is s
				Node node_i(index,parent_id);
				visited_nodes.push_back(node_i);
				return true;
			}
			else if (is_in_visited_vertices(index) != true) {
				to_visit1.push_back(index);
				std::vector<unsigned> parent_id 
					= visited_nodes[0].getParentId();
				parent_id.push_back(index);
				Node node_i(index,parent_id);
				visited_nodes.push_back(node_i);
			}
		}
	}
	
	std::cout << "After s row\n";
	printVisitedNodes();
	
	while (t_found != true) {
		
		std::cout << "This second part is running!\n"; // HELPER
		
		to_visit2 = {};
		
		if (to_visit1.size() == 0) {
			std::cerr << "Error: there is no shortest path between"
				<< s << " and " << t << " . Because to_visit1 is empty";
			return false;	
		}
		
		for (unsigned i = 0; i < to_visit1.size(); i++) {
			unsigned vertex = to_visit1[i];
			for (unsigned index = 0; index < number_of_vertices; index++) {
				
				
				if (matrix[vertex][index] == 1) {
					std::vector<unsigned> parent_id 
						= findNode(vertex);
					if (index == t) {
						parent_id.push_back(index); // the first node is s
						Node node_i(index,parent_id);
						visited_nodes.push_back(node_i);
						return true;
					}
					else if (!is_in_visited_vertices(index)) {
						to_visit2.push_back(index);
						parent_id.push_back(index);
						Node node_i(index,parent_id);
						visited_nodes.push_back(node_i);
					}
				}
			}
			if (i == number_of_vertices - 1) {
				std::cerr << "Error: there is no shortest path between"
					<< s << " and " << t << " .";
				return false;	
			}
		}

		to_visit1 = {};
		
		if (to_visit2.size() == 0) {
			std::cerr << "Error: there is no shortest path between"
					<< s << " and " << t << " . Because to_visit2 is empty";
				return false;	
		}

		for (unsigned i = 0; i < to_visit2.size(); i++) {
			unsigned vertex = to_visit2[i];
			for (unsigned index = 0; index < number_of_vertices; index++) {
				
				
				if (matrix[vertex][index] == 1) {
					std::vector<unsigned> parent_id 
						= findNode(vertex);
					if (index == t) {
						parent_id.push_back(index); // the first node is s
						Node node_i(index,parent_id);
						visited_nodes.push_back(node_i);
						return true;
					}
					else if (!is_in_visited_vertices(index)) {
						to_visit1.push_back(index);
						parent_id.push_back(index);
						Node node_i(index,parent_id);
						visited_nodes.push_back(node_i);
					}
				}
			}
			if (i == number_of_vertices - 1) {
				std::cerr << "Error: there is no shortest path between"
					<< s << " and " << t << " .";
				return false;	
			}
		}
	
	}
	return false;
}



