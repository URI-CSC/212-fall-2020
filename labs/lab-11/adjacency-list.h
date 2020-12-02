/*
	C++ program to represent a directed and weighted graph.
*/
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

class AdjList{
	private:
		std::vector<std::list<std::pair<unsigned int, unsigned int>>> adjList;

	public:
		AdjList();
		void addEdge(unsigned int source, unsigned int destination, unsigned int cost);
		bool isAdjacent(unsigned int source, unsigned int destination);
		void printGraph();
		void outputGraph(std::string fname);
		void problem1(std::string fname);
		void problem2(std::string fname);
        void problem3(std::string fname);
        void problem4(std::string fname);
        void DFS(std::ofstream& of, unsigned int& vertex, bool visited[], int depth);
};

AdjList::AdjList(){

}

void AdjList::addEdge(unsigned int source, unsigned int destination, unsigned int cost){
    while(source >= this->adjList.size() || destination >= this->adjList.size()){
        std::list<std::pair<unsigned int, unsigned int>> temp;
        this->adjList.push_back(temp);
    }
	this->adjList[source].push_back(std::make_pair(destination, cost));
}

bool AdjList::isAdjacent(unsigned int source, unsigned int destination){
    // Check if you can reach 'destination' from 'source'

    return false;
}

void AdjList::printGraph(){
	for(unsigned int i = 0; i < this->adjList.size(); i++){
		for(std::list<std::pair<unsigned int, unsigned int>>::iterator it = this->adjList[i].begin(); it != this->adjList[i].end(); ++it){
			std::cout << i << " -> " << (*it).first << " : " << (*it).second << std::endl;
		}
	}
}

void AdjList::outputGraph(std::string fname){
    std::ofstream of(fname+"_default.dot");

    of << "digraph G {\n" << std::endl;

	for(unsigned int i = 0; i < this->adjList.size(); i++){
		for(std::list<std::pair<unsigned int, unsigned int>>::iterator it = this->adjList[i].begin(); it != this->adjList[i].end(); ++it){
			of << "\t" << i << " -> " << (*it).first << ";" << std::endl;
		}
	}

    of << "\n}";
}

// Attach the edge's weights to the visualization using the '[label=X]' command.
void AdjList::problem1(std::string fname){
    std::ofstream of(fname+"_problem1.dot");

    of << "digraph G {\n" << std::endl;

	// Your code here!

    of << "\n}";
}

// Color all edges with even weights blue, and odd weights red.
void AdjList::problem2(std::string fname){
    std::ofstream of(fname+"_problem2.dot");

    of << "digraph G {\n" << std::endl;

	// Your code here!

    of << "\n}";
}

// Give each edge a color based on its position in a vertex's adjacency list.
void AdjList::problem3(std::string fname){
    std::string colors[] = {"green", "blue", "red", "purple"};

    std::ofstream of(fname+"_problem3.dot");

    of << "digraph G {\n" << std::endl;

    // Your code here!

    of << "\n}";
}

// Give each edge a color that represents the number of "steps" away it is from the first vertex.
void AdjList::problem4(std::string fname){
    std::ofstream of(fname+"_problem4.dot");

    of << "digraph G {\n" << std::endl;

    // Mark all the vertices as not visited
    bool* visited = new bool[this->adjList.size()];
    for (int i = 0; i < this->adjList.size(); i++){
        visited[i] = false;
    }
    unsigned int start = 0;
    for(std::list<std::pair<unsigned int, unsigned int>>::iterator it = this->adjList[0].begin(); it != this->adjList[0].end(); ++it){
        if (visited[(*it).first] == false){
            DFS(of, start, visited, 0);
        }
	}

    of << "\n}";
}

void AdjList::DFS(std::ofstream& of, unsigned int& vertex, bool visited[], int depth){
    static std::string colors[] = {"green", "blue", "red", "purple"};

    // Your code here!
	// Remember, this is recursive!
}