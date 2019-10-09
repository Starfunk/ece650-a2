// Compile with c++ ece650-a2cpp -std=c++11 -o ece650-a2
// Use pointers when I want the function to modify the variable
// and not modify a copy of the variable (the func creates a copy).
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

// separator character
const char comma = ',';
const char left_par = '{';
const char right_par = '}';
const char left_arrow = '<';
const char right_arrow = '>';   
const char space = ' ';
unsigned number_of_vertices;


struct Node {
	int id; // ID of node.
	int parent_id; // ID of parent node.
};

class AMatrix {
	public:
		unsigned getVertexCount( void );
		void assignEdge(std::vector<unsigned> vec);
		void setMatrix(unsigned num);
		void printMatrix( void );
		AMatrix(unsigned num);
		AMatrix();
		
	private:
		unsigned number_of_vertices;
		std::vector< std::vector<unsigned> > matrix;
		
};

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
	std::cout << "PRINT MATRIX\n";
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

bool check_separator(char input) {
	switch (input)
	{
    case comma: // code to be executed if
        return true;
    case left_par: // code to be executed if 
        return true;
        
    case right_par: // code to be executed if 
        return true;
	case space:
		return true;
    case right_arrow: // code to be executed if
        return true;
    default:
		return false;// code to be executed if n doesn't match any cases
	}
	
}

AMatrix matrix;

int main() {
	

    while (!std::cin.eof()) {
        // Read a line of input until EOL and store in a string.
        std::cout << "HELLO WORLD.\n";
        std::string line;
        
        // Get the input line. The last character is the newline '\n'.
        std::getline(std::cin, line);
        // Create an input stream based on the line.
        // We will use the input stream to parse the line.
        std::istringstream input(line);
        
        /* We expect each line to contain a list of numbers.
        This vector will store the numbers.
        They are assumed to be unsigned (i.e., positive) */
        std::vector<unsigned> nums;
        
		// Store the input command.
        char command;
        input >> command;
        
        if (command == 'V') {
			input >> number_of_vertices;
			if (input.fail()) {
				std::cerr << "\nError parsing vertex creation\n";
			}
			
			std::cout << number_of_vertices;
			
			matrix.setMatrix(number_of_vertices);
			matrix.printMatrix();
		}
		//~ E {<2,1>}
		else if (command == 'E') {
			
			//~ // while there are characters in the input line
			unsigned num;
			char separator;
			input >> separator;
			input >> separator;
			while (!input.eof()) {
				std::cout << "In While Loop: ";
				input >> num;
				std::cout << num;
				nums.push_back(num-1);
				input >> separator;
				input >> num;
				std::cout << num;
				nums.push_back(num-1);
				input >> separator;
				std::cout << separator;
				input >> separator;
				std::cout << separator;
				
				//~ if (separator == right_par) {
					//~ break;
				//~ }
				//~ if (input.eof()) {
					//~ break;
				//~ }
				input >> separator;
				std::cout << separator;
				
				std::cout << "\n";
				
			//E {<2,6>,<2,8>,<2,5>,<6,5>,<5,8>,<6,10>,<10,8>}
			
			//~ // read a character
            //~ // Note that whitespace is ignored
				
				//~ input >> separator;
				//~ if (check_separator(separator)) {
					//~ continue;
				//~ }
					// if eof bail out
				//~ if (input.eof())
					//~ break;
					
				//~ else if (separator == left_arrow) {
					
					//~ // parse an integer
					//~ input >> num;
					//~ std::cout << "\nPrinting num: " << num;
					//~ if (input.fail()) {
						//~ std::cerr << "\nError parsing a number\n";
						//~ break;
					//~ }
					//~ else
						//~ nums.push_back(num);
			
					//~ input >> separator;
					//~ std::cout << "\nPrinting separator: " << separator;
					
					//~ input >> num;
					//~ std::cout << "\nPrinting num2: " << num;
					//~ if (input.fail()) {
						//~ std::cerr << "\nError parsing a number\n";
						//~ break;
					//~ }
					//~ else
						//~ nums.push_back(num);
				//~ }
			}
			
			for (unsigned x: nums) {
				std::cout << x << " ";
			}
			std::cout << "We get until here.";
			matrix.assignEdge(nums);
			matrix.printMatrix();
		}	
		
		else if (command == 's') {
			unsigned vertex1;
			unsigned vertex2;
			input >> vertex1;
			if (input.fail()) {
				std::cerr << "\nError parsing while finding shortest path\n";
			}
			input >> vertex2;
			if (input.fail()) {
				std::cerr << "\nError parsing while finding shortest path\n";
			}
		}     
    }
}
