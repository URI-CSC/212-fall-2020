#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <string>

// Functions to be implemented:

bool inSet(std::set<std::string> countries, std::string check){
    

}

bool inMap(std::map<std::string, int> cases, std::string check){


}

int main(){
    std::set<std::string> countries;

    std::map<std::string, int> cases;

    std::ifstream data;

    std::string line;

    data.open("confirmed_cases.txt");
    while (std::getline(data, line)){
    // This is where you will implement your code for
    // insertion into maps and sets
    
    }
    data.close();

    //Space for custom test cases:
    
    

    //Test Case 1

        if (!inSet(countries, "Afghanistan")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (!inSet(countries, "Botswana")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (!inSet(countries, "United Kingdom")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (inSet(countries, "Queensland")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the the countries set." << std::endl;
        return 1;
    }
    if (inSet(countries, "Mayotte")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the the countries set." << std::endl;
        return 1;
    }
    if (inSet(countries, "Sichuan")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the countries set." << std::endl;
        return 1;
    }

    //Test Case 2:
    if (!inMap(cases, "Zimbabwe")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Zimbabwe not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (!inMap(cases, "Greenland")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Greenland not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (!inMap(cases, "Botswana")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Botswana not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (inMap(cases, "United Kingdom")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }
    if (inMap(cases, "China")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }
    if (inMap(cases, "US")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }

    //Test Case 3:
    if (countries.size() != 190){
        std::cout << "Test Case 3: Failed" << std::endl;
        std::cout << "Size of set incorrect. Check your insertion" << std::endl;
        return 1;
    }

    if (cases.size() != 729){
        std::cout << "Test Case 3: Failed" << std::endl;
        std::cout << "Size of map incorrect. Check your insertion" << std::endl;
        return 1;
    }
    std::cout << "All tests passed!" << std::endl;
}
