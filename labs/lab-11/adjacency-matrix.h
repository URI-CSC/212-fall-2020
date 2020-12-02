/*
	C++ program to represent a directed and weighted graph.
*/
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

class AdjMatrix{
	private:
		std::vector<std::vector<int>> adjMatrix;

	public:
		AdjMatrix();
		void addEdge(unsigned int source, unsigned int destination, unsigned int weight);
		bool isAdjacent(unsigned int source, unsigned int destination);
		void printGraph();
		void outputGraph(std::string fname);
};

AdjMatrix::AdjMatrix(){

}

void AdjMatrix::addEdge(unsigned int source, unsigned int destination, unsigned int weight){
    // Add rows to the matrix if we need to
    while(source >= this->adjMatrix.size() || destination >= this->adjMatrix.size()){
        std::vector<int> temp;
        this->adjMatrix.push_back(temp);
    }

    // Add columns to every row if we need to
    for(unsigned int i = 0; i < this->adjMatrix.size(); i++){
        while(adjMatrix[i].size() < this->adjMatrix.size()){
            adjMatrix[i].push_back(0);
        }
    }

    // Add the edge

}

bool AdjMatrix::isAdjacent(unsigned int source, unsigned int destination){
    // Check bounds
    if(source > this->adjMatrix.size() || destination > this->adjMatrix.size()){
        return false;
    }

	// Return whether or not this connection exists
}

// Basic display to console
void AdjMatrix::printGraph(){
	for(unsigned int i = 0; i < this->adjMatrix.size(); i++){
		for(unsigned int j = 0; j < this->adjMatrix[i].size(); j++){
			std::cout << this->adjMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Output the graph to .dot format
void AdjMatrix::outputGraph(std::string fname){
    std::ofstream of(fname+"_default.dot");

    of << "digraph G {\n" << std::endl;

	for(unsigned int i = 0; i < this->adjMatrix.size(); i++){
		for(unsigned int j = 0; j < this->adjMatrix[i].size(); j++){
		    if(adjMatrix[i][j]){
			    of << "\t" << i << " -> " << j << ";" << std::endl;
		    }
		}
	}

    of << "\n}";
}
