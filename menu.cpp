//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "dungeon.h"
#include "Map.h"
#include "monster.h"
#include "npc.h"
#include "menu.h"
#include "puzzles.h"
#include "roomSpace.h"
#include "game.h"
using namespace std;

//split string function
/**
 * Algorithm:
 * 1. Define a function split that takes two string arguments: input_string and separator, and returns a vector of strings.
 * 2. Create an empty vector of strings called result to store the split strings.
 * 3. Create an integer variable called previousSeparatorIndex and initialize it to 0. This will store the index of the separator from the last iteration.
 * 4. Loop over each character in the input_string:
 * 5. Check if we have reached the end of the string, or if the current substring matches the separator. To do this, we can use the substr method to get a substring of length separator.length() starting at index i, and compare it to separator.
 * 6. If we have found a separator or we have reached the end of the string, add the substring before the separator to the result vector using the substr method again. The substring should start at previousSeparatorIndex and end at i - previousSeparatorIndex.
 * 7. Set previousSeparatorIndex to the index of the current separator plus its length, so that it points to the next character after the separator.
 * 8. Return the result vector, which should contain all the split strings.
*/
vector<string> Menu::split(string input_string, string separator)
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
Menu::Menu(Player team[])
{
    options = 0;
    // to distinguish between the player that is passed in and the player in the menu class
    for (int i =0; i < 5; i++){
        this->team[i] = team[i];
    }
    player = team[0];
}

//get key count
int Menu::getKeyCount()
{
    return key_count;
}

//cook and eat menu
/**
 * Algorithm:
 * 1. Declare and initialize variables for user input, ingredient usage, fullness drop, cookware choice, and file input/output
 * 2. Open the cooking.txt file and output its contents to the console
 * 3. Check if the player has enough ingredients and cookware to cook
 * 4. If the player has enough ingredients and cookware, prompt the user for how much ingredients they wish to cook
 * 5. Check if the amount of ingredients is valid (i.e., a multiple of 5)
 * 6. If the amount of ingredients is valid, prompt the user for the cookware they wish to use
 * 7. Based on the player's available cookware, output options for the user to choose from
 * 8. Take in the user's cooking choice
 * 9. If the player does not have enough ingredients or cookware, display an error message and return to the game.
*/
void Menu::cookMenu()
{
    //declare and initialize needed variables
    char player_choice;
    int player_option;
    int fullness_drop = 0;
    int kg_count = 0;
    int cookware_choice = 0;
    Map map;
    Game game;
    ifstream file("resource/cooking.txt");
    string line = "";

    //open file
    file.open("resources/cooking.txt");

    //output image lol
    while (getline(file, line))
    {
        cout << line << endl;
    }

    //check to see whether or not player has ingredients
    if (player.getIngredients() > 5 && player.getCookware() > 1)
    {
        //prompt the user for the amount of ingredients they wish to use
        cout << "You currently have " << player.getIngredients() << " kg of ingredients." << endl;
        cout << "How much do you wish to cook? (increment of 5)" << endl;
        cin >> kg_count;

        //check to see if the amount of ingredients is valid
        if (kg_count % 5 == 0)
        {
            //prompt user for the cookware they wish to use
            cout << "Do you wish to cook with:" << endl;

            //check the user's available cookware
            if (player.getPot() > 0)
            {
                //output it as an option
                cout << "1) Ceramic Pot" << endl;
            }
            if (player.getPan() > 0)
            {
                cout << "2) Frying Pan" << endl;
            }
            if (player.getCauldron() > 0)
            {
                cout << "3) Cauldron" << endl;
            }

            //take in user's cooking choice
            cin >> cookware_choice;
        }
        else
        {
            //enter invalidity message
            cout << "You didn't enter a valid amount of ingredients. \nDo you want your party to starve? :(" << endl;
        }
    }
    else
    {
        //display map
        cout << "\n\n\n\n" << endl;
        map.displayMap();

        //invalid items to cook
        cout << "\n" << endl;
        cout << "You don't have the proper cooking supplies! Come back after you visit a merchant." << endl;
        cout << "\n" << endl;
    }
}

/**
 * Algorithm:
 * 1. Open an output file stream to a file named "scores.txt".
 * 2. Create a variable member_count initialized to 0.
 * 3. Iterate from index 1 to index 4 (inclusive) of the team array.
 * 4. For each iteration:
    a. Check if the player at the current index is alive by calling team[i].isAlive().
    b. If the player is alive, increment the member_count variable.
 * 5. Calculate the score based on the following formula: score = 1000 + (num_cleared_rooms * 50) + (member_count * 100).
 * 6. Get the name of the player whose score is being calculated by calling player.getPlayerName().
 * Write the player's name and score to the output file in the following format: name|score\n.
 * Close the output file stream.
*/
void Menu::score(int num_cleared_rooms, Player team[])
{
    ofstream out_file("scores.txt"); // initialize and output file stream
    int member_count = 0;
    for (int i = 1; i < 5; i++) // sorts through team array to see if members are still alive
    {
        if (team[i].isAlive() == true) // if true
        {
            member_count++; // increment the member count
        }
    }

    int score = 1000 + (num_cleared_rooms * 50) + (member_count * 100); // score based on 1000 for player being alive, number of cleared rooms, and the number of team members alive by end

    string name = team[0].getPlayerName(); // gets the player's name

    out_file << name << "|" << score << endl; // outputs the name and score into out_file
}

//print leaderboard
/**
 * Algorithm:
 * 1. Open the "scores.txt" file for input.
 * 2. Initialize an empty string variable called "copy".
 * 3. Initialize an empty vector<string> called "scores".
 * 4. Read in each line of the input file using getline(in_file, copy) until there are no more lines.
 * 5. Add each line of scores from the file into the "scores" vector using scores.push_back(copy).
 * 6. Loop through each element of the "scores" vector using a nested for loop.
 * 7. Split the current score element and the next score element into two separate vectors called "current_score" and "next_score" respectively, using the split() function.
 * 8. If the score in "current_score" is less than the score in "next_score", swap the positions of the two elements in the "scores" vector using a temporary string variable called "temp".
 * 9. Once the vector is sorted in descending order by score, output the leaderboard using cout statements:
    a. Print out a line of equal signs to create a border.
    b. Print out the heading "LEADERBOARD" in the center of the border using the cout statement "|| LEADERBOARD ||".
    c. Print out another line of equal signs to create a border.
    d. Loop through each element of the "scores" vector using a for loop.
    e. Print out the element at index k of the "scores" vector using the cout statement "cout << scores.at(k) << endl;".
 * 10. Close the input file.
*/
void Menu::printLeaderBoard()
{
    ifstream in_file("scores.txt"); // input file

    string copy = ""; // copy the lines

    vector<string> scores; // vector stores the scores from the input file
    
    while (getline(in_file, copy)) // loops through the entire file
    {
        scores.push_back(copy); // adds each line of scores from the file into the vector
    }

    // nested for loop that loops through each of the vector elements
    for (int i = 0; i < scores.size() - 1; i++)
    {
        // this one compares an element at index i to every other elements of index j
        for (int j = 0; j < scores.size() - 1; j++)
        {
            string temp = ""; // creates a temporary string to store temporary values
            vector<string> current_score = split(scores.at(j), "|"); // current_score vector gets the split vector from the scores at index j
            vector<string> next_score = split(scores.at(j + 1), "|"); // next_score vector gets the split vector from the scores at index j + 1

            if (stoi(current_score.at(1)) < stoi(next_score.at(1))) // checks to see if the current score is less than the next score
            {
                temp = scores[j]; // if so, store the score at index j into the temp string variable
                scores[j] = scores[j + 1]; // set the scores at index j as the next score at j + 1
                scores[j + 1] = temp; // re-assign the temp string as scores at j + 1
            }
        }
    }

    //output leaderboard
    cout << "===========================" << endl;
    cout << "||      LEADERBOARD      ||" << endl;
    cout << "===========================" << endl;
    cout << endl;

    for (int k = 0; k < scores.size(); k++) // Prints out the leaderboard and the vector
    {
        cout << scores.at(k) << endl; // vector element at index k
    }
}

//player menu
/**
 * Algorithm: 
 * 1. Initialize all the required variables for the game such as the player choice, game, dungeon, monster, room, and puzzle instances, etc.
 * 2. Generate a random map for the game using the "randomMap" function of the game object.
 * 3. While the player's choice is not '4' (Give Up):
    a. Increase the number of turns taken by the player.
    b. Display the menu options to the user using cout statements.
    c. Accept the player's input as a character and store it in the player_choice variable.
    d. Check if the sorcerer's anger has reached 100, if yes, then display the end-game stats and end the game.
    e. Check if the player has cleared all rooms, if yes, then display the end-game stats and end the game.
    f. Check if the player still has enough team members to continue, if no, then display the end-game stats and end the game.
    g. If the player has chosen to investigate:
        i. Check if the space has already been explored, if yes, then display an appropriate message to the user.
        ii. If the space has not been explored, then determine if a key should drop using a random number generator.
        iii. Determine if the player has found any treasure using a random number generator and drop an appropriate item according to the number of cleared rooms.
    h. If the player has chosen to pick a fight, generate a random monster and let the player fight with it.
    i. If the player has chosen to cook and eat, let the player cook food using cookware and eat it to increase fullness.
    j. If the player has chosen to give up, then display the end-game stats and end the game.
 * 4. If the player chooses to give up, end the game.
*/
void Menu::playerMenu()
{
    //declare and initialize variables
    char player_choice;
    int player_option;
    int num_cleared_rooms = 0;
    int key_drop = 0;
    int treasure_drop = 0;
    int fullness_drop = 0;
    int kg_count = 0;
    int cookware_choice = 0;
    int monster_gen = 0;
    int prev_move = 0;
    int num_riddles = 0;
    int misfortune_prob = 0;
    int sorcerer_anger = 0;
    int num_weapons = 0;
    int num_armor_sets = 0;
    int spaces_explored = 0;
    int turns = 0;
    int monsters_defeated = 0;
    const int max_value = 100;
    const int percentage = 40;
    char move_direction;
    NPC merchant;
    Monster monster;
    Dungeon dungeon;
    Game game;
    RoomSpace room;
    Puzzle puzzle;
    Player members[4];
    Player player;
    vector<int> weapons = player.getWeapon();

    //generate random map
    Map map = game.randomMap();

    while(player_choice != '4')
    {
        //increase number of turns taken
        turns++;

        //output menu options
        cout << "===============================" << endl;
        cout << "Use keys WASD to move, \nor choose one of the options below:" << endl;
        cout << "1. Investigate" << endl;
        cout << "2. Pick a Fight" << endl;
        cout << "3. Cook and Eat" << endl;
        cout << "4. Give Up" << endl;
        cout << "===============================" << endl;

        cin >> player_choice;
        
        //check to see if the sorcerer's anger
        if(sorcerer_anger == 100)
        {
            //output to user
            cout << "\nThe Sorcerer's Anger has reached 100...\n" << endl;
            cout << "The Sorcerer has unleashed his wrath and destroyed the entire dungeon." << endl;
            cout << "All party members have tragically perished." << endl;
            
            //set all team members to dead
            for (int i = 0; i < 5; i++)
            {
                team[i].isSlain();
            }

            //print end of game stats
            game.endGameStats(team, num_cleared_rooms, spaces_explored, monsters_defeated, turns, player);
            
            //end game
            game.end(1);
        }

        //check to see if the player cleared all rooms
        if (num_cleared_rooms == 5)
        {
            //print end of game stats
            game.endGameStats(team, num_cleared_rooms, spaces_explored, monsters_defeated, turns, player);

            //end game
            game.end(0);
        }

        //see if player still has enough team members to continue
        if (game.getTeamSize(team) < 2)
        {
            //print end of game stats
            game.endGameStats(team, num_cleared_rooms, spaces_explored, monsters_defeated, turns, player);
            
            //end game
            game.end(1);
        }

        //investigate
        if(player_choice == '1')
        {
            //for misfortunes function
            int prev_move = 0;

            //plant random seed
            srand(time(NULL));

            //check to see if the space has already been explored
            if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
            {
                //empty space
                cout << "\n\n\n\n" << endl;

                //display the player's stats
                game.displayStats(team, num_cleared_rooms, key_count, sorcerer_anger);

                //display map again
                map.displayMap();

                //output explored message
                cout << "\nThis space has already been explored silly! Choose a different option." << endl;

            }
            else
            {
                //determine if a key drops
                key_drop = rand() % 10 + 1;

                //10% chance
                if (key_drop == 1)
                {
                    //output message and increase key count
                    cout << "\nYou have found a key!\n" << endl;
                    key_count++;
                }

                //20% chance that player finds a piece of treasure
                treasure_drop = rand() % 5;
                if (treasure_drop == 0)
                {
                    //determine which treasure will be dropped
                    switch(num_cleared_rooms)
                    {
                        case 1: 
                            //player finds a silver ring
                            cout << "Cool! You've stumbled across a silver ring." << endl;
                            player.setSilver(player.getSilver() + 1);

                            break;

                        case 2:
                            //player finds a ruby necklace
                            cout << "Nice! You've found a ruby necklace." << endl;
                            player.setRuby(player.getRuby() + 1);

                            break;

                        case 3:
                            //player finds an emerald bracelet
                            cout << "Wow! You have found an emerald bracelet." << endl;
                            player.setEmerald(player.getEmerald() + 1);

                            break;

                        case 4:
                            //player finds a diamond circlet
                            cout << "Amazing! You found a diamond circlet!" << endl;
                            player.setDiamond(player.getDiamond() + 1);

                            break;

                        case 5:
                            //player finds a gem-encrusted goblet
                            cout << "Spectacular! You found a gem-encrusted goblet!" << endl;
                            player.setGem(player.getGem() + 1);

                        default:
                            break;
                    }
                }
                
                //determine if the party's fullness drops
                fullness_drop = rand() % 2;
                if (fullness_drop == 0)
                {
                    //for each member within the team
                    for (int i = 0; i < 5; i++)
                    {
                        team[i].decreaseFullness();

                        //check to see if anyone died
                        if (team[i].getFullness() < 1)
                        {
                            //member dies of hunger
                            team[i].die();
                        }
                    }

                    //output decrease hunger message
                    cout << "\nThe party's fullness has decreased by one point.\n" << endl;
                }                

                //determine 20% chance that player fullness decreased
                if (rand() % 5 == 0)
                {
                    //generate a random number between 1 and 10
                    monster_gen = rand() % 10 + 1;
                    
                    cout << "\nYou picked a fight with a monster!\n" << endl;
                    //fight monster; implement monster class

                    //for each member within the team
                    for (int i = 0; i < 5; i++)
                    {
                        //determine 20% chance that player's fullness decreases
                        if (rand() % 5 == 0)
                        {
                            team[i].decreaseFullness();

                            //check to see if anyone died
                            if (team[i].getFullness() < 1)
                            {
                                //member dies of hunger
                                team[i].die();
                            }
                        }
                    }
                }

                //if the space explored is a room
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
                {
                    //for misfortunes function
                    int prev_move = 1;

                    //check to see if its not the 5th room
                    if (num_cleared_rooms < 5)
                    {
                        //check to see if player has a key to enter
                        if (key_count > 0)
                        {
                            //allow user to enter the room space
                            room.openDoor(team, key_count, num_cleared_rooms);
                        }
                        else
                        {
                            //if the player successfully beat the door puzzle
                            if (puzzle.doorPuzzle(key_count) == 0)
                            {
                                //allow user to enter room space
                                room.openDoor(team, key_count, num_cleared_rooms);
                            }
                        }
                    }
                    else
                    {
                        //prompt final boss fight
                        game.final_boss();
                    }
                }

                //check to see if the space explored is an npc place
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
                {
                    //prompt for a riddle before player can proceed
                    puzzle.npcPuzzle(num_cleared_rooms, team, key_count);
                }

                //mark new space as explored
                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());

                //increase counter for explored spaces
                spaces_explored++;

                //display the player's stats
                game.displayStats(team, num_cleared_rooms, key_count, sorcerer_anger);

                //display map again
                map.displayMap();
            }

            //generate a random number between 0 and 100
            misfortune_prob = rand() % max_value;

            //check if the number is 40% probability
            if (misfortune_prob < max_value * percentage / 100)
            {   
                //prompt game misfortune
                game.misfortune(team, prev_move);
            }
        }
        //pick a fight
        else if (player_choice == '2')
        {
            //for misfortunes function
            int prev_move = 0;

            //randomly pick a monster

            vector<Monster> monster_list = monster.monsterList(monster); // gets the list of monsters from "monsters.txt"

            Monster rand_monster = dungeon.getRandomMonster(num_cleared_rooms, monster_list); // generates a random monster from the list

            cout << "You have chosen to pick a fight with " << rand_monster.getMonsterName() << "!" << endl;

            rand_monster.battleOutcome(num_weapons, num_armor_sets, team, player, weapons); // calculates the battle outcome with the rand_monster

            /**
            - battleOutcome() function calculates the 10% chance, the fullness drop, etc.
            **/

            vector<Monster> new_monster_list = monster.checkMonsterLife(monster_list, rand_monster); // Checks if the monster is dead, and if it is, it wil remove it from the vector

            //after fighting the monster, there's a 10% chance of dropping a key

            //50% chance that players' fullness drops by one point

            //for each member within the team
            // for (int i = 0; i < 5; i++)
            // {
            //     //determine 50% chance that player's fullness decreases
            //     if (rand() % 2 == 0)
            //     {
            //         team[i].decreaseFullness();

                        // //check to see if anyone died
                        // if (team[i].getFullness() < 1)
                        // {
                        //     //member dies of hunger
                        //     team[i].die();
                        // }
            //     }
            // }

            // probably don't need the above since it is covered in battleOutcome()

            //generate a random number between 0 and 100
            misfortune_prob = rand() % max_value;

            //check if the number is 40% probability
            if (misfortune_prob < max_value * percentage / 100)
            {   
                //prompt game misfortune
                game.misfortune(team, prev_move);
            }

            //display the player's stats
            game.displayStats(team, num_cleared_rooms, key_count, sorcerer_anger);
            
            //display map again
            map.displayMap();

            //increase sorcerer's anger by 1
            sorcerer_anger++;
        }
        else if (player_choice == '3') //cook and eat
        {
            //for misfortunes function
            int prev_move = 0;

            //print cook menu
            cookMenu();

            //generate a random number between 0 and 100
            misfortune_prob = rand() % max_value;

            //check if the number is 40% probability
            if (misfortune_prob < max_value * percentage / 100)
            {   
                //prompt game misfortune
                game.misfortune(team, prev_move);
            }

            //increase sorcerer's anger by 1
            sorcerer_anger++;
        }
        else if (player_choice == '4')//give up
        {
            //all party members die
            for (int i = 0; i < 5; i++)
            {
                team[i].isSlain();
            }

            //output give up message
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
            cout << "Giving up so soon? Try harder next time.\n\n\n\n\n" << endl;
            cout << "==============================" << endl;
            cout << "=       YOU WERE SLAIN       =" << endl;
            cout << "==============================" << endl;
            cout << "\n\n\n\n\n\n\n\n" << endl;

            //print end game stats
            game.endGameStats(team, num_cleared_rooms, spaces_explored, monsters_defeated, turns, player);
            
            //end game
            game.end(1);
        }
        else
        {
            if(player_choice == 'w' || player_choice == 'a' || player_choice == 's' || player_choice == 'd')
            {
                //move 1 space in direction
                move_direction = player_choice;
                map.move(move_direction);

                //check to see if the current space is explored
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
                {
                    cout << endl;
                }
                else
                {
                    //increase sorcerer's anger by 1
                    sorcerer_anger++;
                }

                //display map
                cout << "\n\n\n\n" << endl;
                //display the player's stats
                game.displayStats(team, num_cleared_rooms, key_count, sorcerer_anger);
                map.displayMap();

                //determine if the location currently on is an occupied space
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
                {
                    //time to visit the merchant!
                    puzzle.npcPuzzle(num_cleared_rooms, team, key_count);
                    merchant.openMerchantMenu(num_cleared_rooms, player);
                }

                //for rooms
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
                {
                    cout << "If you wish to proceed into the room, choose option 1." << endl;
                }
                
                //for dungeon escape
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
                {
                    if (num_cleared_rooms > 4)
                    {
                        //output exiting message
                        cout << "\n\n\n\n\n\n\n\n" << endl;
                        cout << "==============================" << endl;
                        cout << "=         YOU SLAYED         =" << endl;
                        cout << "==============================" << endl;
                        cout << "\n\n..........\n\n" << endl;
                        cout << "Just Kidding !! You must defeat the last boss to exit.\n" << endl;

                        //prompt final boss fight
                        game.final_boss();
                    }
                    else
                    {
                        cout << "\nYou haven't cleared enough rooms. You can't exit, silly!\n" << endl;
                    }
                }

                //for each member within the team
                for (int i = 0; i < 5; i++)
                {
                    //determine 20% chance that player's fullness decreases
                    if (rand() % 5 == 0)
                    {
                        team[i].decreaseFullness();

                        //check to see if anyone died
                        if (team[i].getFullness() < 1)
                        {
                            //member dies of hunger
                            team[i].die();
                        }
                    }
                }
            }
            else
            {
                //display map
                cout << "\n\n\n\n" << endl;
                //display the player's stats
                game.displayStats(team, num_cleared_rooms, key_count, sorcerer_anger);
                map.displayMap();

                //input validation
                cout << "\nInvalid option. Try again!\n" << endl;
            }
        }
    }

    score(num_cleared_rooms, team); // deals with the score of playthroughs
    printLeaderBoard(); // prints the leaderboard
}