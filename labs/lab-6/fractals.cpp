#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string koch_snowflake(int degree);
std::string snowflake(int degree);
std::string sierpinski_triangle(int degree, int len);

int main(){
    std::ofstream of("l-system.txt");

    int degree = 3;

    of << koch_snowflake(degree);
    //of << sierpinski_triangle(degree, std::pow(2, degree - 1));
}

// *** DO NOT TOUCH! ***
std::string koch_snowflake(int degree){
    std::string commands = "";

	// This handles generating the 4 'sides' of the snowflake.
    for(int i = 0; i < 4; i++){
        commands += snowflake(degree);
        commands += "+ + ";
    }

    return commands;
}

std::string snowflake(int degree){
    if(degree == 0){
        return "F ";
    }
    std::string commands = "";

	// Logic for generating the snowflake goes here.

    return commands;
}

std::string sierpinski_triangle(int degree, int len){
    if(degree == 0){
        return "";
    }

    std::string commands = "";

    // Logic for generating the triangles goes here.

    return commands;
}