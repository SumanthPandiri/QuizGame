//main function

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>  
#include <ctime> 
#include "Quiz.h"
#include "printResult.h"

int main(int argc, char const *argv[]) {
    //declaration of variables
    std::string w(argv[1]);
    std::ifstream dataFile(w);
    std::vector<Quiz> quizVector;
    std::string Line, q, a, input, answer, m, n, b;
    int g = 0;
    int h = 0;
    m = "Q: ";
    n = "A: ";

    //reading text file to quiz vector
    if (dataFile.is_open()){
        while (getline(dataFile, Line)) {
            //reading question
            b = Line.substr(0,3);
            if (m.compare(b) == 0) {
            q = Line;
            q.erase(0, 3); //erasing the "Q: "
            }

            //reading answer
            getline(dataFile, Line);
            b = Line.substr(0,3);
            if (n.compare(b) == 0) {
            a = Line;
            a.erase(0, 3); //erasing the "A: "
            }

            //adding the question and answer to the vector
            quizVector.push_back(Quiz(q,a));
        }
    }

    //randomizes the order of the questions
    srand(unsigned(time(0)));
    std::random_shuffle (quizVector.begin(), quizVector.end());

    
    //performs the quiz game with input
    for (unsigned int i = 0; i < quizVector.size(); i++) {
        //asks question, takes in input, and formats input
        answer.clear();
        answer = quizVector[i].getAnswer();
        std::cout << quizVector[i].getQuestion() << std::endl;
        std::cout << "Type in your answer: ";
        std::getline (std::cin,input); 
    

        //checks the input to see if it matches the answer
        if (input.compare(answer) == 0) {
            Quiz::updateScore(1);
            g++; //counts number of correct answers
            std::cout << "Correct!" << std::endl;
            std::cout << "Current score: " << std::to_string(Quiz::getScore()) << std::endl;
            std::cout << std::endl;
        }
        else {
            Quiz::updateScore(-1);
            h++; //counts number of wrong answers
            std::cout << "Wrong! Correct answer: " << quizVector[i].getAnswer() << std::endl;
            std::cout << "Current score: " << std::to_string(Quiz::getScore()) << std::endl;
            std::cout << std::endl;
        }
    }
    
    //uses printResult function to print the result
    std::cout << printResult(quizVector.size(), g, h);

  } 