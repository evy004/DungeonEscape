//CSCI1300 Spring 2023
//Author: Evy Ng
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <string>
#include "Player.h"
#ifndef NPC_H
#define NPC_H
using namespace std;

class NPC
{
    //declaring variables in private scope
    private:
        int steps;
        string name;
        string dialogue;
        bool check_input(string input);
        vector<string> split(string input_string, string separator);

    //declaring functions in public
    public:

        //default constructor
        NPC();

        //parameterized constructor
        NPC(string name_, int steps_);

        //reveals the space as an NPC space when the player enters for the first time
        void revealNPCSpace(bool hasNPC);

        //moves the party a single space in any of the cardinal directions
        void moveParty(bool move);

        //decreases each party member's fullness level with a 20% chance of dropping by 1
        void decreaseFullness(bool move);

        //presents the player with a riddle puzzle to solve
        bool solveRiddle(bool solve);

        //adjusts the item prices according to the number of cleared rooms
        void adjustPrices(int num_cleared_rooms);

        //allows the player to barter for goods with the NPC
        void openMerchantMenu(int num_cleared_rooms, Player &player);

        //if NPC is hostile, summons a random monster to fight 
        bool summonMonster(bool hostile);

        //handles the actions to take when the player speaks to the NPC
        void speakNPC(int num_cleared_rooms);

        //ends the game when the player chooses to give up.
        void giveUp();
};

#endif