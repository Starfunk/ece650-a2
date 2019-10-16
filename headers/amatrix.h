#ifndef AMATRIX_H
#define AMATRIX_H

class AMatrix {
	public:
		AMatrix();
		AMatrix(unsigned num);
		void printMatrix( void );
		void printShortestPath(void); 
		void printVisitedNodes(void);
		unsigned getVertexCount( void );
		std::vector<unsigned> findNode(unsigned id); 
		void assignEdge(std::vector<unsigned> vec); 
		void setMatrix(unsigned num);
		void resetAMatrix(void);
		std::vector< std::vector<unsigned> > getMatrix(void);
		bool find_shorted_path(unsigned s, unsigned t);
		bool is_in_visited_vertices(unsigned num);
	private:
		unsigned number_of_vertices;
		std::vector<unsigned> to_visit1;
		std::vector<unsigned> to_visit2;
		std::vector<unsigned> visited_vertices;
		std::vector<Node> visited_nodes;	
		std::vector< std::vector<unsigned> > matrix;
};

#endif
