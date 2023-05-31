// Single Responsibility Principle (SRP)
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Printer {
public:
    void print(vector<string>* spots) {
        vector<string> spots_ = *spots;
        string formatted_first_row = spots_[0] + " | " + spots_[1] + " | " + spots_[2] + "\n" + spots_[3] + " | " + spots_[4] + " | " + spots_[5] + "\n" + spots_[6] + " | " + spots_[7] + " | " + spots_[8];
        cout << formatted_first_row << "\n";
    }
};

class Parser {
public:
    vector<string> FirstRow(vector<string>* spots) {
        vector<string> spots_ = *spots;
        vector<string> first_row;
        first_row.push_back(spots_[0]);
        first_row.push_back(spots_[1]);
        first_row.push_back(spots_[2]);
        return first_row;
    }

    vector<string> SecondRow(vector<string>* spots) {
        vector<string> spots_ = *spots;
        vector<string> second_row;
        second_row.push_back(spots_[3]);
        second_row.push_back(spots_[4]);
        second_row.push_back(spots_[5]);
        return second_row;
    }

    vector<string> ThirdRow(vector<string>* spots) {
        vector<string> spots_ = *spots;
        vector<string> third_row;
        third_row.push_back(spots_[6]);
        third_row.push_back(spots_[7]);
        third_row.push_back(spots_[8]);
        return third_row;
    }

};

class Board {
public:
    Board() {
        for (int i = 0; i < 9; i++) {
            spots_.push_back(to_string(i));
        }
    }

    vector<string> FirstRow() {
        parser_.FirstRow(&spots_);
    }

    vector<string> SecondRow() {
        parser_.SecondRow(&spots_);
    }

    vector<string> ThirdRow() {
        parser_.ThirdRow(&spots_);
    }

    void Display() {
        printer_.print(&spots_);
    }

private:
    vector<string> spots_;
    Printer printer_;
    Parser parser_;
};