//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include "Player.h"
#include "monster.h"
#include "npc.h"
#include "roomSpace.h"
#include "game.h"
using namespace std;

/**
 * Algorithm: 
 * 1. Define a vector of strings called result to store the split strings.
 * 2. Define an integer variable called previousSeparatorIndex and set it to 0. This variable will be used to keep track of the index of the separator from the last iteration.
 * 3. Loop over each character in the input string using a for loop:
    a. Check if we have reached the end of the string, or if the current substring of length separator.length() matches the separator string. If so:
        i. Extract the substring before the separator using input_string.substr(previousSeparatorIndex, i-previousSeparatorIndex) and add it to the result vector using result.push_back().
        ii. Update the previousSeparatorIndex variable to the index of the current separator.
 * 4. Return the result vector containing the split strings.
*/
vector<string> Monster::split(string input_string, string separator)
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

//default constructor
Monster::Monster()
{
    difficulty = 0;
    name = "";
    isMonsterAlive = true;
}

//parameterized constructor
Monster::Monster(string name_, int difficulty_)
{
    name = name_;
    difficulty = difficulty_;
    isMonsterAlive = true;
}

//gets the name of the monster
string Monster::getMonsterName()
{
    return name;
}

//sets the name of the monster
void Monster::setMonsterName(string monster_name)
{
    name = monster_name;
}

//gets the difficulty of the monster
int Monster::getMonsterDiff()
{
    return difficulty;
}

//sets the difficulty of the monster
void Monster::setMonsterDiff(int monster_diff)
{
    difficulty = monster_diff;
}

bool Monster::getMonsterLife()
{
    return isMonsterAlive;
}

vector<Monster> Monster::monsterList(Monster monster)
{
    ifstream in_file("monsters.txt"); // initializes an input file stream for "monsters.txt"
    string copy = ""; // Initialize empty string for getline
    vector<Monster> monster_list; // declares a vector of Monster type
    int i = 0; // counter

    while (getline(in_file, copy)) // run as long as file not end
    {
        vector<string> separations = split(copy, ","); // splits vector
        monster.setMonsterName(separations[0]); // set 0th index of split as monster name
        monster.setMonsterDiff(stoi(separations[1])); // set 1st index of split as monster diff

        monster_list.push_back(monster); // pushback on monster_list vector with monster
        
        i++; // increment index counter
    }

    return monster_list; // return the monster_list
}

// Function to calculate the outcome of a battle
/**
 * Algorithm: 
 * 1. Declare variables
 * 2. Initialize unique_weapons_count and damage to 0.
 * 3. Generate random1 and random2 using rand() function.
 * 4. Set win to false, Set has_key to false.
 * 5. Get the amount of gold and ingredients held by player object.
 * 6. Iterate through the weapons vector and increment unique_weapons_count for each player who has a weapon.
 * 7. Calculate damage dealt by the party's weapons as follows:
 *  If the weapon is a rapier, set damage to the number of rapiers times 1.
 *  If the weapon is an axe, set damage to the number of axes times 2.
 *  If the weapon is a longsword, set damage to the number of longswords times 3.
    Calculate the party's weapon bonus by adding num_weapons to damage.
    Calculate the outcome of the battle as follows:
    Multiply (random1 + weapon_bonus) by unique_weapons_count.
    Subtract (random2 * difficulty) divided by (num_armor_sets + 1).
    If the outcome of the battle is greater than 0, set win to true, set isMonsterAlive to false, and perform the following actions:
    Print "You have won!" to the console.
    Increase player's gold by 10 * difficulty.
    Increase player's ingredients by 5 * difficulty.
    Iterate through the team array and decrease each member's fullness by 1 with a 50% chance.
    Decrease player's fullness by 1 with a 50% chance.
    Remove the dead monster from the vector.
    If the outcome of the battle is less than or equal to 0, set win to false and perform the following actions:
    Print "You have lost!" to the console.
    Decrease player's gold by 25%.
    Decrease player's ingredients by a random amount between 0 and 30.
    Iterate through the team array and decrease each member's fullness by 1 with a 50% chance.
    Decrease player's fullness by 1 with a 50% chance.
    For each team member who has armor, roll a die with 1 in 5 odds of them dying. Print "Oh no! (player name) died!" to the console if they die.
    For each team member who does not have armor, roll a die with 1 in 10 odds of them dying. Print "Oh no! (player name) died!" to the console if they die.
    Return win.
*/
bool Monster::battleOutcome(int num_weapons, int num_armor_sets, Player team[], Player player, vector<int> weapons)
{
    int unique_weapons_count = 0;
    int damage;

    int random1 = rand() % 7; // generates one random integer between 0 and 6
    int random2 = rand() % 7; // generates second random integer between 0 and 6

    bool win; // declaration of bool to determine whether party won or not

    bool has_key = false;

    int gold = player.getGold(); // gets party's gold
    int ingredients = player.getIngredients(); // gets party's ingredients

    for (int i = 0; i < weapons.size(); i++)
    {
        if (weapons[i] >= 1) // checks if the player at index i has a weapon
        {
            unique_weapons_count++; // if so, increment number of unique weapons
        }

        if (i == 2) // If the weapon is a rapier
        {
            damage = weapons[i] * 1; // damage is the number of rapiers times 1
        }
        else if (i == 3) // If the weapon is an axe
        {
            damage = weapons[i] * 2; // damage is the number of axes times 2
        }
        else if (i == 4) // If the weapon is a longsword
        {
            damage = weapons[i] * 3; // damage is the number of longswords times 3
        }
    }

    int weapon_bonus = num_weapons + damage; // calculates party's weapon bonus

    int battle = ((random1 + weapon_bonus) * unique_weapons_count) - ((random2 * difficulty) / (num_armor_sets + 1)); // calculates the outcome of the battle

    if (battle > 0) // if outcome outputs an integer greater than 0, then player wins
    {
        win = true; // set win bool to true
        isMonsterAlive = false; // bool to get set the status of the monster

        if (win == true) // if the player won
        {
            cout << "You have won!" << endl; // print this message
        }

        player.changeGold(10 * difficulty); // add 10 * difficulty amount of gold
        player.changeIngredients(5 * difficulty); // add 5 * difficulty amount of ingredients

        for (int i = 0; i < 5; i++)
        {
            int fifty_fifty = rand() % 2;

            if (fifty_fifty == 0)
            {
                team[i].decreaseFullness();
            }
        }

        int fifty_fifty = rand() % 2;

        if (fifty_fifty == 0)
        {
            player.decreaseFullness();
        }
    }

    else
    {
        win = false;

        if (win == false)
        {
            cout << "You have lost!" << endl;
        }
        
        player.changeGold(-1 * (gold / 4));
        
        int rand_ingredients = rand() % 31;
        player.changeIngredients(-rand_ingredients);

        for (int i = 0; i < 5; i++)
        {
            int fifty_fifty = rand() % 2;

            if (fifty_fifty == 0)
            {
                team[i].decreaseFullness();
            }
        }
        
        int fifty_fifty = rand() % 2;

        if (fifty_fifty == 0)
        {
            player.decreaseFullness();
        }

        for (int i = 1; i < 5; i++)
        {
            if (team[i].hasArmor() == true)
            {
                int armor_slain = rand() % 5;
                
                if (armor_slain == 0)
                {
                    team[i].isSlain();
                    cout << "Oh no! " << team[i].getPlayerName() << " died!" << endl; // replace bro with the member name (maybe move the team member name array into player class)
                }
            }
            else if (team[i].hasArmor() == false)
            {
                int no_armor_slain = rand() % 10;
                
                if (no_armor_slain == 0)
                {
                    team[i].isSlain();
                    cout << "Oh no! " << team[i].getPlayerName() << " died!" << endl; // also here, replace bro with member name at index i
                }
            }
        }
    }

    return win;
}

/**
 * Algorithm:
 * 1. Check if the current monster is alive or not.
 * 2. If the monster is dead, loop through the monster_list vector to find the monster with the same name as the current monster.
 * 3. Once found, erase the monster from the vector using the erase function.
 * 4. Return the updated monster_list vector.
*/
vector<Monster> Monster::checkMonsterLife(vector<Monster> monster_list, Monster monster)
{
    if (isMonsterAlive == false)
    {
        for (int i = 0; i < monster_list.size(); i++)
        {
            if (monster_list.at(i).getMonsterName() == monster.getMonsterName())
            {
                monster_list.erase(monster_list.begin() + i);
            }
        }
    }

    return monster_list;
}

// Function to print the outcome of a battle
/**
 * Algorithm:
 * 1. Check the value of the win parameter:
        If it is true, output "You have won!" to the console.
        If it is false, output "You have lost!" to the console.
    2. End the function
*/
void Monster::printBattleOutcome(bool win, Monster defeated_monster)
{
    if (win == true)
    {
        cout << "You have won!" << endl;
    }
    else
    {
        cout << "You have lost!" << endl;
    }
}

//function to print a message for a player encounter with a monster
void Monster::printEncounterMessage(Monster return_monster)
{
    //will create a monster object based off the text file
    cout << return_monster.getMonsterName() << "AHEAD! THEY LOOK HOSTILE!" << endl;
}

//function to play the game, may change to game class
void Monster::playGame()
{
    //commence game
    //start, displays etc
    cout << "Play" << endl;
}

//party surrenders
/**
 * Algorithm:
 * 1. Check if the party has surrendered
 * 2. If the party has surrendered, decrease the number of party members by 1
 * 3. Get the current size of the player team
 * 4. Generate a random number between 1 and the size of the player team to select a random party member
 * 5. Initialize a boolean variable 'rand_alive' to false
 * 6. Start a loop that continues until a living party member is found
 * 7. Check if the randomly selected party member is alive
 * 8. If the party member is alive, set 'rand_alive' to true
 * 9. Set the selected party member as slain, which means they cannot proceed further in the game
 * 10. Print a message indicating the misfortune and reduction in the party size
 * 11. Get the updated size of the player team
 * 12. Output the new size of the party
 * 13. If the randomly selected party member is not alive, generate a new random number to select another party member
 * 14. Repeat steps 7 to 13 until a living party member is found
 * 15. Return the updated number of party members.
*/
int Monster::partySurrender(bool party_surrender, Player team[], int num_party_members, Game &game)
{
    //the party surrenders, party members is decreased by one
    if (party_surrender == true)
    {
        num_party_members -= 1;
    }

    //get player size
    int team_size = game.getTeamSize(team);

    //randomly select a party member
    int rand_member = rand() % team_size + 1;

    //boolean to check for alive
    bool rand_alive = false;

    while (rand_alive == false)
    {
        //checking to see that the player is currently alive
        if (team[rand_member].isAlive())
        {
            //set alive to true
            rand_alive = true;

            //lock the player in room
            team[rand_member].setSlain();

            //output misfortune message
            cout << "OH NO! Your teammate " << team[rand_member].getPlayerName() << "is trapped in the previous room" << endl;
            cout << "and is unable to get through. You must continue without them." << endl;

            //get new party size
            int team_size = game.getTeamSize(team);

            //output party size
            cout << "Your party size has reduced to " << team_size << " members." << endl;
        }

        //change member
        if (rand_member < 5)
        {
            rand_member++;
        }
        else
        {
            rand_member = 1;
        }
    }

    return num_party_members;
}