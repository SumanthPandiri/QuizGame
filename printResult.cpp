//printResult.cpp

#include "printResult.h"

//definition of printResult function
std::string printResult(int questions, int correct, int wrong) {
    //uses stringstream to create one long string for output
    std::stringstream s;
    s << "Number of questions: " << std::to_string(questions) << std::endl;
    s << "Number correct answers: " << std::to_string(correct) << std::endl;
    s << "Number wrong answers: " << std::to_string(wrong) << std::endl;
    s << "Final score: " << std::to_string(Quiz::score)  << std::endl;

    //returns the stringstream as a string
    return s.str();
}