//Quiz.h
#ifndef QUIZ_H_
#define QUIZ_H_
#include <iostream>

//declaration of Quiz class
class Quiz
{
private:
    std::string question = "";
    std::string answer = "";
    static int score;
public:
    Quiz() = default;
    Quiz(std::string q, std::string a) : question{q}, answer{a} {}
    std::string getQuestion();
    std::string getAnswer();
    static int getScore();
    static void updateScore(int val);
    
    friend std::string printResult(int questions, int correct, int wrong);
};

#endif