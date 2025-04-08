//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <vector>
#include "Player.h"
#include "Map.h"
#ifndef GAME_H
#define GAME_H

using namespace std;

class Game
{   
    //declaring variables in private scope
    private:
        bool start_game;
        Player player_;
        Map map_ = Map();
        int level_difficulty;
        int num_items;
        const static int team_size = 5;
        string team[team_size];

    //declaring functions in public
    public:

        //default constructor
        Game();

        //display main menu
        void main_menu();

        //randomize map
        Map randomMap();

        //display player stats
        void displayStats(Player team[], int num_rooms_cleared, int key_count, int sorcerer_anger);

        //check player team
        void getPlayerTeam();

        //set player team
        void setPlayerTeam(string team[5]);

        //get current team size
        int getTeamSize(Player team[]);

        //get team fullness
        void getTeamFullness(Player team[]);

        //set team fullness
        void setTeamFullness(Player team[5]);

        //set weapons for the team
        void setTeamWeapons(Player team[]);

        //prompt the occurrence of a misfortune
        void misfortune(Player team[], int prev_move);

        //start game
        void start();

        //final boss (maybe)
        void final_boss();

        //end game stats
        void endGameStats(Player team[], int rooms_cleared, int spaces_explored, int monsters_defeated, int turns, Player &player);

        //end game
        bool end(int win_lose);

        
};

#endif