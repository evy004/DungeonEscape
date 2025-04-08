//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"
#include "monster.h"
#ifndef DUNGEON_H
#define DUNGEON_H
using namespace std;

//dungeon class to hold monsters
class Dungeon
{
    private:
        Monster monster;
        vector<Monster> list; //holds monsters
        vector<Monster> defeatedMonsters; //defeated monsters
        vector<string> split(string input_string, string separator);

    public:
        //default constructor
        Dungeon();

        //parameterized constructor
        Dungeon(string monsterFile);

        //obtain monster list
        void getMonsterList(vector<Monster> list);

        //create a monster object to spawn random monster
        Monster getRandomMonster(int num_rooms_cleared, vector<Monster> monster_list);

        //defeats monster, implements the choice conditions
        void defeatMonster(Monster defeated_monster);

        //checks to see if player has properly slain the monster
        bool isMonsterDefeated(Monster monster, vector<Monster> monster_list);

        // Function to handle a battle with a monster
        void handleBattle(Player player, Dungeon dungeon, Monster encountered_monster);

        // Function to handle a player's turn in the game
        void playerTurn(Player player, Dungeon dungeon);
};

#endif