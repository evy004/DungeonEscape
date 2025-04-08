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
#include "dungeon.h"
using namespace std;

vector<string> Dungeon::split(string input_string, string separator)
{
// This function takes a string and splits it on a separator
// It returns a vector of strings with the split results
    vector<string> result; // Create a vector to store the split strings
    int previousSeperatorIndex = 0; // Create a variable to store the index of the separator from the last iteration
    for(int i = 0; i <= input_string.length(); i ++){ // Loop over each character in the string
        
        // If we reach the end of the string, or we find the separator
        if (i == input_string.length() || ( (i < input_string.length() - separator.length()) && (input_string.substr(i, separator.length())) == separator)){

            // Add the string before the separator to the result vector
            result.push_back(input_string.substr(previousSeperatorIndex, i-previousSeperatorIndex));
            // Set the previous separator to the index of the current separator
            previousSeperatorIndex = i + separator.length();
        }
    }
    return result; // Return the vector of split strings
}

//dungeon class to hold monsters
//default constructor
Dungeon::Dungeon()
{
    vector<Monster> defeatedMonsters;
    Monster monster;
    vector<Monster> list = monster.monsterList(monster);
}

//obtain monster list
void Dungeon::getMonsterList(vector<Monster> list)
{
    //output the list of monsters that will be read from the source text
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.at(i).getMonsterName() << endl;
        cout << list.at(i).getMonsterDiff() << endl;
    }
}

//create a monster object to spawn random monster
Monster Dungeon::getRandomMonster(int num_rooms_cleared, vector<Monster> monster_list)
{
    ifstream in_file("monsters.txt");
    string copy = "";
    int line = 0;
    vector<Monster> valid_monsters;
    Monster return_monster;
    int difficulty = num_rooms_cleared + 1;
    int count = 0;

    for (int i = 0; i < monster_list.size(); i++) // iterates through all the monsters in list
    {
        if (monster_list.at(i).getMonsterDiff() == difficulty) // checks if the difficulty of the room is equal to monster diff
        {
            valid_monsters.push_back(monster_list.at(i)); // if so, add monster to valid_monsters vector
            count++;
        }
    }

    // generates random number between 0 and i
    int rand_num = rand() % count;
    return_monster = valid_monsters.at(rand_num); // gets monster at rand_num value

    return return_monster; // returns random monster
}

//checks to see if player has properly slain the monster
bool Dungeon::isMonsterDefeated(Monster monster, vector<Monster> monster_list)
{
    if (monster.getMonsterLife() == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// //function to handle a battle with a monster
// void Dungeon::handleBattle(Player player, Dungeon dungeon, Monster encountered_monster)
// {
//     //based on the player, dungeon, and monster
//     //commence battle, the player will battle against the monster
//     //based on the outcome, the percentage changes will be implemented
//     cout << "You are battling!" << endl;
// }

// //function to handle a player's turn in the game
// void Dungeon::playerTurn(Player player, Dungeon dungeon)
// {
//     //changing the player's turn
//     cout << "It is your turn!" << endl;
// }