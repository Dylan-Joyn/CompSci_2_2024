// PEMMDAS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include<cmath>
using namespace std;



double modulusQuiz();
double pemmdasQuiz();
void printScores(vector<double> modulus, vector<double> pemmdas);

int main()
{
    srand(time(0));
    char selection;
    vector<double> modulusScores;
    vector<double> pemmdasScores;


    do {
        cout << "Welcome to PEMMDAS practice.  " << endl
            << endl
            << "Select a menu option to proceed: " << endl
            << "1  Modulus Practice" << endl
            << "2  PEMMDAS Practice" << endl
            << "3  Score Report" << endl;
        cin >> selection;

        double tempScore = 0.0;
        switch (selection) {
        case '1': tempScore = modulusQuiz();
            modulusScores.push_back(tempScore);
            break;
        case '2': tempScore = pemmdasQuiz();
            pemmdasScores.push_back(tempScore);
            break;
        case '3': printScores(modulusScores, pemmdasScores);
            break;
        case '4': return 0;
        default:
            cout << " Please enter a valid entry.";
        }
    } while (true);
    return 0;

}


double modulusQuiz() {
    int times = 0;
    int score = 0;
    cout << "How many problems would you like to solve?" << endl;
    cin >> times;
    int total = times;


    while (times > 0) {
        int num1 = rand() % 10;
        int num2 = rand() % 9 + 1;
        int answer = 0;

        cout << "What is:" << endl
            << num1 << " % " << num2 << endl;
        cin >> answer;
        if (answer == (num1 % num2)) {
            cout << "That's right!" << endl;
            score++;
        }
        else {
            cout << "No, the answer is " << (num1 % num2) << endl;

        }
        times--;

    }

    double percent = score / static_cast<double>(total) * 100;
    cout << "You scored " << score << " out of " << total << endl
        << "That's " << percent << "%." << endl;

    return percent;
}

double pemmdasQuiz() {
    srand(static_cast<unsigned int>(time(0)));

    //Ask user how many problems they would like to solve
    int numProblems;
    cout << "How many problems would you like?";
    cin >> numProblems;

    double totalScore = 0.0;
    for (int i = 0; i < numProblems; ++i) {
        //random numbers and operators loop
        int numbers[9];
        char operators[8];

        //random numbers
        for (int j = 0; j < 9; ++j) {
            numbers[j] = rand() % 20 + 1;

        }
        for (int j = 0; j < 8; ++j) {
            int randOpp = rand() % 4;
            switch (randOpp) {
            case 0: operators[j] = '+'; break;
            case 1: operators[j] = '-'; break;
            case 2: operators[j] = '*'; break;
            case 3: operators[j] = '/'; break;

            }
        }
        cout << "Problem: " << (i + 1) << "; ";
        for (int j = 0; j < 8; ++j) {
            cout << numbers[j] << " " << operators[j] << " ";
        }
        cout << numbers[8] << endl;

        double score = 10.0;
        totalScore += score;
    }
    return totalScore / numProblems;
}

//implement a quiz for PEMMDAS-- give the user about 9 random integers
//between 1 and 20, seperated by random arithmetic operators, and have the user solve the problem 
//check if the user is correct
//return the percentage of right answers 




void printScores(vector<double> modulus, vector<double> pemmdas) {
    int modCount = 1, pemCount = 1;
    cout << "Your percentages on modulus quizzes are:" << endl;
    for (double percent : modulus) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }
    cout << endl << endl;
    cout << "Your percentages on PEMMDAS quizzes are:" << endl;
    for (double percent : pemmdas) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }



}
