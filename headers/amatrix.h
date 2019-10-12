#ifndef AMATRIX_H
#define AMATRIX_H

class AMatrix {
	public:
		unsigned getVertexCount( void );
		void assignEdge(std::vector<unsigned> vec);
		void setMatrix(unsigned num);
		std::vector< std::vector<unsigned> > getMatrix(void);
		void printMatrix( void );
		AMatrix(unsigned num);
		AMatrix();
		
	private:
		unsigned number_of_vertices;
		std::vector< std::vector<unsigned> > matrix;	
};

#endif
