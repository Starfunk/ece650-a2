#include <vector>
#include <iostream>
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
