//Quiz.cpp
#include "Quiz.h"

//sets score to 0
int Quiz::score = 0;

//returns the question
std::string Quiz::getQuestion() {
    return question;
}

//returns the answer
std::string Quiz::getAnswer() {
    return answer;
}

//returns the score
int Quiz::getScore() {
    return score;
}

//updates the score based on if they got it right or wrong
void Quiz::updateScore(int val) {
    Quiz::score += val;
    
    //keeps the score at 0 if it goes below 0
    if (Quiz::score <= 0) {
       Quiz::score = 0;
    }
}