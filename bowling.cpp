#include <iostream>
#include <vector>
#include <algorithm>
#include "bowling.h"

using namespace std;

Bowling::Bowling(){
    FirstName = "";
    LastName = "";
    vector<int> Throws;
    vector<int> Scores;
    vector<string> Frames;
}


Bowling::Bowling(string fName, string lName, vector<int> throws) { 
    FirstName = fName;
    LastName = lName;
    Throws = throws;
}
void Bowling::setScores(vector<int> scores){
    Scores = scores;
}
void Bowling::setFrames(vector<string> frames) {
    Frames = frames;
}
string Bowling::getFirstName() {
    return FirstName;
}
string Bowling::getLastName() {
    return LastName;
}
vector<int> Bowling::getThrows() {
    return Throws;
}
string Bowling::getThrowsString() {
    string ThrowsString;
    for (int i = 0; i < Throws.size(); i++) {
        ThrowsString += std::to_string(Throws[i]) + " ";
    }
    return ThrowsString;
}
void Bowling::setScoresAndFrames(vector<int> Throws, vector<int> &Scores, vector<string> &Frames) {
    int score = 0;

    for (int i = 0; i < Throws.size(); i++) {
        
        if (Frames.size() >= 9) {
            if (Frames.size() == 9) {
                Frames.push_back("");
                Scores.push_back(score);
            }


           // Checking for strike
            if (Throws[i] == 10){
                Frames[Frames.size() - 1] += " X";
                Scores[Scores.size() - 1] +=  Throws[i];
            }
            else {
                // Checking for spare
                if (Throws[i] + Throws [i+1] == 10) {
                    if (Throws[i] == 0) {
                        Frames[Frames.size() - 1] += "- /";
                        Scores[Scores.size() - 1] += 10;
                        i += 1;
                    }
                    else {
                        Frames[Frames.size() - 1] += std::to_string(Throws[i]) + " /";
                        Scores[Scores.size() - 1] += 10;
                        i += 1;
                    }
                }
                else {
                    if (Throws.size() -1 == i) {
                        if (Throws[i] == 0) {
                            Frames[Frames.size() - 1] += " -";
                        }
                        else {
                            Frames[Frames.size() - 1] += " " + std::to_string(Throws[i]);
                            Scores[Scores.size() - 1] += (Throws[i]);
                        }
                    }
                    else {
                        if (Throws[i] == 0) {
                            Frames[Frames.size() - 1] += "- " + std::to_string(Throws[i+1]);
                            Scores[Scores.size() - 1] += (Throws[i] + Throws[i+1]);
                        }
                        else if (Throws[i+1] == 0) {
                            Frames[Frames.size() - 1] += std::to_string(Throws[i]) + " -";
                            Scores[Scores.size() - 1] += (Throws[i] + Throws[i+1]);
                        }
                        else {
                            Frames[Frames.size() - 1] += std::to_string(Throws[i]) + " " + std::to_string(Throws[i+1]);
                            Scores[Scores.size() - 1] += (Throws[i] + Throws[i+1]);
                        } 
                    }
                    i += 1;
                }
            } 
        }
        else{
            // Checking for strike
            if (Throws[i] == 10){
                Frames.push_back("  X");
                // What if at 9?
                score += (10 + Throws[i+1] + Throws[i+2]);
                // Logic might work with score += !
                Scores.push_back(score);
            }
            else {
                // Checking for spare
                if (Throws[i] + Throws [i+1] == 10) {
                    if (Throws[i] == 0) {
                        Frames.push_back("- /");
                        score += (10 + Throws[i+2]);
                        Scores.push_back(score);
                        i += 1;
                    }
                    else {
                        Frames.push_back(std::to_string(Throws[i]) + " /");
                        score += (10 + Throws[i+2]);
                        Scores.push_back(score);
                        i += 1;
                    }
                }
                else {
                    if (Throws[i] == 0) {
                        Frames.push_back("- " + std::to_string(Throws[i+1]));
                        score += (Throws[i] + Throws[i+1]);
                        Scores.push_back(score);
                        i += 1;
                    }
                    else if (Throws[i+1] == 0) {
                        Frames.push_back(std::to_string(Throws[i]) + " -");
                        score += (Throws[i] + Throws[i+1]);
                        Scores.push_back(score);
                        i += 1;
                    }
                    else if (Throws[i] == 0 && Throws[i+1] == 0) {
                        Frames.push_back("- -");
                        score += (Throws[i] + Throws[i+1]);
                        Scores.push_back(score);
                        i += 1;
                    }
                    else {
                        Frames.push_back(std::to_string(Throws[i]) + " " + std::to_string(Throws[i+1]));
                        score += (Throws[i] + Throws[i+1]);
                        Scores.push_back(score);
                        i += 1;  
                    }
                }
            }
        }
        
    }
    setScores(Scores);
    setFrames(Frames);
}

string Bowling::getFirstLastName() {
    return FirstName + " " + LastName;
}
string Bowling::Padding(string Name, int MaxNameLength) {
    return string(MaxNameLength - Name.size(), ' ');
}
string Bowling::numPadding(int num) {
    string scoreAndSpaces;
    string number = std::to_string(num);

    if (number.size() == 1) {
        scoreAndSpaces = "  " + number;
    }
    else if (number.size() == 2) {
        scoreAndSpaces = " " + number;
    }
    else {
        scoreAndSpaces = number;
    }

    return scoreAndSpaces;

}
string Bowling::PrintFrame(vector<int> Scores, vector<string> Frames, int maxNameLength, string FirstLast) {
    string output = "| " + FirstLast + Padding(FirstLast, maxNameLength) + " | ";

    for (int i = 0; i < Frames.size(); i++) {
        if (i == 9) {
            output += Frames[i] + " |";
        }
        else {
            output += Frames[i] + " | ";
        }
    }
    output += "\n";

    string spacing2 = string(maxNameLength, ' ');

    output += "| " + spacing2 + " | ";

    for (int i = 0; i < Scores.size(); i++) {
        if (i == 9) {
            output += "  " + numPadding(Scores[i]) + " |";
        }
        else {
            output += numPadding(Scores[i]) + " | ";
        }
    }
    output += "\n";

    return output;
}
int Bowling::getStrikes() {
    return count(Throws.begin(), Throws.end(), 10);
}
int Bowling::getGutters() {
    return count(Throws.begin(), Throws.end(), 0);
}
int Bowling::getScore() {
    return Scores[Scores.size()-1];
}