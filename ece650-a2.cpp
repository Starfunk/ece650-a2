// Compile with c++ ece650-a2cpp -std=c++11 -o ece650-a2
// Use pointers when I want the function to modify the variable
// and not modify a copy of the variable (the func creates a copy).
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>


#include "headers/node.h"
#include "headers/amatrix.h"

// separator character
//~ const char comma = ',';
//~ const char left_par = '{';
//~ const char right_par = '}';
//~ const char left_arrow = '<';
//~ const char right_arrow = '>';   
//~ const char space = ' ';


//~ bool check_separator(char input) {
	//~ switch (input)
	//~ {
    //~ case comma: // code to be executed if
        //~ return true;
    //~ case left_par: // code to be executed if 
        //~ return true;
        
    //~ case right_par: // code to be executed if 
        //~ return true;
	//~ case space:
		//~ return true;
    //~ case right_arrow: // code to be executed if
        //~ return true;
    //~ default:
		//~ return false;// code to be executed if n doesn't match any cases
	//~ }
//~ }

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
			unsigned number_of_vertices;
			input >> number_of_vertices;
			if (input.fail()) {
				std::cerr << "\nError parsing vertex creation\n";
			}
			
			std::cout << number_of_vertices;
			
			matrix.setMatrix(number_of_vertices);
			matrix.printMatrix();
		}
		
		else if (command == 'E') {
			//~ // while there are characters in the input line
			unsigned num;
			char separator;
			input >> separator;
			input >> separator;
			while (!input.eof()) {
				input >> num;

				nums.push_back(num);
				input >> separator;
				input >> num;

				nums.push_back(num);
				input >> separator;
				input >> separator;
				
				input >> separator;
			}
			
			//~ for (unsigned x: nums) {
				//~ std::cout << x << " ";
			//~ }
			//~ std::cout << "We get until here.";
			matrix.assignEdge(nums);
			matrix.printMatrix();
		}	
		
		else if (command == 's') {
			unsigned s;
			unsigned t;
			input >> s;
			if (input.fail()) {
				std::cerr << "\nError parsing while finding shortest path\n";
			}
			input >> t;
			if (input.fail()) {
				std::cerr << "\nError parsing while finding shortest path\n";
			}
			// Case 1: if s = t and they are in the set of vertices
			// Case 2: if s != t and there is a shortest path
			// Case 3: if s != t and there is not a shortest path
			// Case 4: one of s or t don't exist (or both don't exist).
			// though as long as one doesn't exist, we can output false.
			
			if (matrix.find_shorted_path(s,t)) {
				matrix.printShortestPath();
			}
			
			else
				std::cerr << "There is no shortest path. Exit from main";
				
			matrix.resetAMatrix();
		}     
			
    }
}

//~ // Could use pointer here?
//~ // This function returns true if key is in v and false otherwise.
//~ bool is_in_vec(std::vector<unsigned> v, unsigned key) {
	
	//~ if (std::find(v.begin(), v.end(), key) != v.end()) {
		//~ return true;
	//~ }
	//~ else
		//~ return false;
//~ }

//~ /* row: row i of the adjacency matrix
 //~ * to_visit: stores all vertices (unvisited) connected to vertex i 
 //~ * visited_vertices: 
 //~ */
//~ // updates the vectors to_visit, visited_vertices, and visited_nodes
//~ // accordingly. If index == t, then return true.
//~ bool is_t_connected(unsigned * t,
					//~ std::vector<unsigned> * row, 
					//~ std::vector<unsigned> * to_visit, 
					//~ std::vector<unsigned> * visited_vertices,
					//~ std::vector<unsigned> parent_id, // make it pointer? 
					//~ std::vector<Node> * visited_nodes) {
					
	//~ // Get indices for where s is connected.
	//~ for (unsigned index = 0; index <row.length(); index++) {
		//~ if (row[index] == 1) {
			//~ if (index == t) {
				//~ return true;
			//~ }
			//~ else if (!is_in_vec(visited_vertices, index)) {
				//~ to_visit.push_back(index);
				//~ Node node(index,parent_id)
				//~ visited_nodes.push_back(node);
					//~ }
				//~ }
			//~ }
			
	//~ return false;
	
//~ }
	
	
	
	
	
//--------------------------------------------------------
			//~ if (s or t > number_of_vertices - 1) {
				//~ std::cerr << "Error: s or t is an invalid number";
				//~ break;
			//~ }
			
			//~ else if (s == t) {
				//~ std::cout << t << "-" << t << "\n";
				//~ break;
			//~ }
			
			//~ mat = matrix.getMatrix();
			//~ for (unsigned index = 0; index < number_of_vertices; index++) {
				//~ is_t_connected(t, mat[index],
				
			//~ }
			
			//~ while (t_found != true) {
				
				
				//~ for (unsigned index = 0; index <node.length(); index++) {
					//~ if (node[index] == 1) {
						//~ to_visit.push_back(index);
						//~ // MY QUESTION IS: IF I TAKE THE parent_id from node_s and add an element, 
						//~ // does that change the vector for node_s? Also, does it matter? No.
						//~ // 
						//~ Node node_i(index,node_s.getParentId().push_back(node_s.getId()))
					//~ }
				//~ }
				
				//~ // for loop that looks at each vertex in to_visit
				//~ for (unsigned 
			
			//~ // node is one row of the matrix
			//~ std::vector<unsigned> node = matrix.getMatrix()[s];	
