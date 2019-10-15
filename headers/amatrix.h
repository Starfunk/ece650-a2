#ifndef AMATRIX_H
#define AMATRIX_H

class AMatrix {
	public:
		unsigned getVertexCount( void );
		void assignEdge(std::vector<unsigned> vec);
		void setMatrix(unsigned num);
		std::vector< std::vector<unsigned> > getMatrix(void);
		bool find_shorted_path(unsigned s, unsigned t);
		bool is_in_visited_vertices(unsigned num);
		std::vector<unsigned> findNode(unsigned id); // returns node with id
		void printMatrix( void );
		void printShortestPath(void);
		void printVisitedNodes(void);
		void resetAMatrix(void);
		AMatrix(unsigned num);
		AMatrix();
		
	private:
		unsigned number_of_vertices;
		std::vector< std::vector<unsigned> > matrix;	
		std::vector<unsigned> to_visit1;
		std::vector<unsigned> to_visit2;
		std::vector<unsigned> visited_vertices;
		std::vector<Node> visited_nodes;	
};

#endif
