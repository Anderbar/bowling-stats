#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bowling {
    private:
        string FirstName;
        string LastName;
        vector<int> Throws;
        vector<int> Scores;
        vector<string> Frames;
        
        // int CurrentThrow;



    public:
        Bowling();
        Bowling(string fName, string lName , vector<int> throws);

        int maxNameLength;

        // Getters
        string PrintFrame(vector<int> Scores, vector<string> Frames, int maxNameLength, string FirstLast);
        void CurrentScore();
        string getFirstName();
        string getLastName();
        vector<int> getThrows();
        string getThrowsString();
        string getFirstLastName();
        string Padding(string Name, int MaxLengthName);
        string numPadding(int num);
        int getStrikes();
        int getGutters();
        int getScore();
        

        // Setters
        void setScoresAndFrames(vector<int> Throws, vector<int> &Scores, vector<string> &Frames);
        
        void setScores(vector<int> scores);
        void setFrames(vector<string> frames);




    

};