//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"
#include "npc.h"
#include "roomSpace.h"
#include "game.h"
#ifndef MONSTER_H
#define MONSTER_H
using namespace std;

class Monster
{
    //declaring variables in a private scope
    private:
        int difficulty; //challenge rating of monster
        bool isMonsterAlive = true;
        string name; //name of monster
        vector<string> split(string input_string, string separator);

    //declaring functions in a public scope
    public:

        //default constructor
        Monster();

        //parameterized constructor
        Monster(string name, int difficulty);

        //gets the name of the monster
        string getMonsterName();

        //sets the name of the monster
        void setMonsterName(string monster_name);

        //gets the difficulty of the monster
        int getMonsterDiff();

        //sets the difficulty of the monster
        void setMonsterDiff(int monster_diff);

        //get the monster life
        bool getMonsterLife();

        vector<Monster> monsterList(Monster monster);

        // Function to calculate the outcome of a battle
        bool battleOutcome(int num_weapons, int num_armor_sets, Player team[], Player player, vector<int> weapons);

        // Checks if monster is alive
        vector<Monster> checkMonsterLife(vector<Monster> monster_list, Monster monster);

        // Function to print the outcome of a battle
        void printBattleOutcome(bool win, Monster defeated_monster);

        // Function to print a message for a player encounter with a monster
        void printEncounterMessage(Monster return_monster);

        // Function to play the game
        void playGame();

        //party surrenders
        int partySurrender(bool party_surrender, Player team[], int num_party_members, Game &game);

};

#endif