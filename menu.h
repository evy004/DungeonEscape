//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include "Player.h"
#ifndef MENU_H
#define MENU_H
using namespace std;

//may or may not use
class Menu
{
    //declaring variables in a private scope
    private:
        int options; //generates based on the number of selections
        int key_count;
        Player player;
        Player team[5];

    //declaring functions in public scope
    public:

        //default constructor
        Menu();

        //paramterized constructor
        Menu(Player team[]);

        //get key count
        int getKeyCount();

        //cook menu (for readability)
        void cookMenu();

        //player menu
        void playerMenu();

        //split
        vector<string> split(string input_string, string separator);

        //scores
        void score(int num_cleared_rooms, Player team[]);

        //tracks leaderboard
        void printLeaderBoard();
};

#endif