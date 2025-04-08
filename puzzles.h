//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <string>
#include "npc.h"
#ifndef PUZZLES_H
#define PUZZLES_H
using namespace std;

//class declaration
class Puzzle
{
    //declaring variables in private scope
    private:
        int npc;
        int num_riddles;
        const static int riddles_size = 20;
        static Puzzle riddles[riddles_size];
        string riddle;
        string answer;

    //declaring functions in public
    public:

        //split function
        int split(string input_string, char separator, string arr[], int arr_size);

        //default constructor
        Puzzle();

        //parameterized constructor
        Puzzle(string riddle, string answer);

        //get the riddle
        string getRiddle();

        //get the answer
        string getAnswer();

        //npc puzzle
        void npcPuzzle(int num_cleared_rooms, Player team[], int &key_count);

        //door puzzle
        int doorPuzzle(int key_count);
};

#endif