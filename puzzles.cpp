//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "npc.h"
#include "puzzles.h"
#include "monster.h"
#include "dungeon.h"
using namespace std;

//split string function
// Algorithm:
// Initialize the counter variable to 0, the arr_count variable to 0, and the previous_delimiter_index variable to 0.
// If the input string is empty, return 0.
// Loop through each character c in the input string:
// a. If c is not the separator:
// i. Increment counter by 1.
// b. If c is the separator:
// i. Copy the substring of the input string from previous_delimiter_index to counter characters after previous_delimiter_index (not including the separator character) into the arr[arr_count] element.
// ii. Increment arr_count by 1.
// iii. Set previous_delimiter_index to i + 1.
// iv. Set counter to 0.
// c. If c is the last character of the input string:
// i. Copy the substring of the input string from previous_delimiter_index to the end of the string into the arr[arr_count] element.
// ii. Increment arr_count by 1.
// If arr_count is greater than or equal to arr_size, return -1.
// Return arr_count.
int Puzzle::split(string input_string, char separator, string arr[], int arr_size)
{
    //declare and initialize variables
    int counter = 0;
    int arr_count = 0;
    int previous_delimiter_index = 0;

    //return 0 if the string is empty
    if (input_string.empty())
    {
        return 0;
    }

    //iterate through the string
    for (int i = 0; i < input_string.length(); i++)
    {
        //check to see if the number of splits is greater than allowed size
        if (arr_count >= arr_size)
        {
            //returns -1 if not allowed
            return -1;
        }

        //iterates through the characters and checks that they're are not delimiters
        if (input_string[i] != separator)
        {
            counter++;
        }
        //if the index contains a delimiter
        else if (input_string[i] == separator)
        {
            //place the current string of letters between delimiters into array
            arr[arr_count] = input_string.substr(previous_delimiter_index, counter);
            arr_count++;
            // i + 1 because the next word starts after the delimiter
            previous_delimiter_index = i + 1;
            //reset the counter to not repeat string segments
            counter = 0;
        }
        //checks to see if the string does not contain a delimiter
        if (i == input_string.length() - 1)
        {
            //place the current string of letters between delimiters into array
            arr[arr_count] = input_string.substr(previous_delimiter_index, counter);
            arr_count++;
            // i + 1 because the next word starts after the delimiter
            previous_delimiter_index = i + 1;
            //reset the counter to not repeat string segments
            counter = 0;
        }

    }
    //returns the amount of split segments
    return arr_count;
}


//declare static use of array
Puzzle Puzzle::riddles[riddles_size];

//default constructor
Puzzle::Puzzle()
{
    npc = 0;
    srand(time(NULL));
}

//parameterized constructor
Puzzle::Puzzle(string r, string a)
{
    riddle = r;
    answer = a;
    srand(time(NULL));
}

//get the riddle
string Puzzle::getRiddle()
{
    return riddle;
}

//get the answer
string Puzzle::getAnswer()
{
    return answer;
}

//npc puzzle
// Algorithm:
// Declare and initialize any needed variables, such as the current player, file input stream, and vectors for storing riddles and answers.
// Open the "riddles.txt" file for reading.
// Read the contents of the file line by line using a while loop.
// For each line read from the file, split it into two parts separated by the "|" character using the split() function.
// If the split was successful and the number of read riddles is less than the maximum allowed, store the riddle and answer in their respective vectors.
// Seed a random number generator to be used later for selecting a random riddle.
// Output a message prompting the user to answer a riddle to unlock the NPC's shop.
// Select a random riddle from the array of stored riddles and output it to the user.
// Prompt the user to enter their answer to the riddle.
// If the user's answer matches the answer for the selected riddle, congratulate them and open the NPC's merchant menu using the openMerchantMenu() function.
// If the user's answer is incorrect, output a message informing them that they have failed to answer the riddle and summon a random monster for the user to fight.
// Determine the outcome of the battle by calling the battleOutcome() function and passing in the current player's weapons and armor, as well as the list of monsters and player team.
// Generate a random number between 0 and 9 using rand(), and if the number is 0, increment the key count variable.
// If the user wins the battle, execute the same code as if they had correctly answered the riddle and opened the NPC's merchant menu.
// If the user loses the battle, execute the same code as if they had answered the riddle incorrectly and summoned a monster, including generating a new random number and incrementing the key count if necessary.
// Close the file input stream.

void Puzzle::npcPuzzle(int num_cleared_rooms, Player team[], int &key_count)
{
    Player player = team[0];
    //declare and initialize any needed variables
    ifstream file("riddles.txt");
    string line = "";
    string arr[2];
    vector<string> riddles;
    vector<string> answers;
    int num_splits = 0;
    int rand_riddle = 0;
    string get_riddle = "";
    string player_answer = "";
    NPC npc;
    Dungeon dungeon;
    Monster monster;
    vector<Monster> monster_list = monster.monsterList(monster);
    int num_weapons = player.getWeaponCount();
    int num_armor_sets = player.getArmorCount();
    vector<int> weapons = player.getWeapon();

    //open file
    file.open("resources/riddles.txt");

    //check to see if file is able to be opened
    if (file.is_open())
    {
        //initiate a while loop to read the file
        while (getline(file, line))
        {
            //split the read line into four parts
            num_splits = split(line, '|', arr, 2);
            
            //check to see if the split was valid
            if(num_splits == 2 && num_riddles < riddles_size)
            {
                riddles.push_back(arr[0]);
                answers.push_back(arr[1]);

                //increase the number of read posts by one
                num_riddles++;
            }
        }

        //seed a random number generator
        rand_riddle = rand() % num_riddles;

        //output riddle for the user to persuade them to buy his merch
        cout << "\nYou deem yourself worthy of my treasures?" << endl;
        cout << "First, you must answer this riddle to unlock my shop.\n" << endl;

        //choose a random riddle from the array
        cout << riddles[rand_riddle] << endl;
        cout << "Answer: ";

        cin >> player_answer; //takes in the user's answer

        //check to see if the player was correct
        if (player_answer == answers[rand_riddle])
        {
            //tell player that they were correct
            cout << "\nI'm impressed... you have correctly answered my riddle." << endl;
            npc.openMerchantMenu(num_cleared_rooms, player);
        }
        else
        {
            //tell the user that they answered incorrectly
            cout << "\nYou have failed to answer my riddle and are deemed unworthy of my wares..." << endl;
            
            //summon a random monster for user
            Monster rand_monster = dungeon.getRandomMonster(num_cleared_rooms, monster_list);

            cout << rand_monster.getMonsterName() << " has been summoned! Now you must fight!" << endl;

            bool outcome = monster.battleOutcome(num_weapons, num_armor_sets, team, player, weapons);

            int rand_num = rand() % 10; // generates a random number between 0 and 9
        
            if (rand_num == 0) // checks if the random number is equal to 0
            {
                key_count++;
            }
        }
    }
    else
    {
        cout << "file not opened :(" << endl;
    }
}

//door puzzle
// Algorithm:
// Initialize variables:
// hearts = 3
// won_game = false
// player_choice = ""
// player_num = 0
// door_choice = 0
// Check if key_count is less than or equal to 0. If so, perform the following steps:
// a. Display the message "HOW DARE YOU ATTEMPT TO TRESPASS".
// b. Display the message "Now you must commence in a game of Boulder/Parchment/Shears against me. You may enter if you beat me; however, if you lose, there will be consequences."
// c. Enter a while loop that continues until either the player has won or they have lost all their hearts.
// i. Display the message "Boulder, Parchment, Shears!" and prompt the player to enter their choice.
// ii. Convert the player's choice to an integer value for comparison.
// iii. Generate a random integer between 0 and 2 to represent the door's choice.
// iv. Compare the player's choice and the door's choice to determine the winner of the round.
// v. If the player wins the round, display the message "Victory is yours. You may proceed." and set won_game to true to exit the while loop.
// vi. If the player loses the round, decrement hearts by 1 and display the message "A loss to you.".
// vii. If the round is a tie, display the message "TIE! We must continue."
// d. Check if hearts is equal to 0. If so, return 1 to indicate the player has lost the game.
// Otherwise, return 0 to indicate the player has won the game.
int Puzzle::doorPuzzle(int key_count)
{
    //declare and initialize any needed variables
    int hearts = 3;
    bool won_game = false;
    string player_choice = "";
    int player_num = 0;
    int door_choice = 0;

    if (key_count <= 0)
    {
        //output message
        cout << "HOW DARE YOU ATTEMPT TO TRESPASS" << endl;
        cout << "\nNow you must commence in a game of Boulder/Parchment/Shears against me." << endl;
        cout << "You may enter if you beat me; however, if you lose, there will be consequences." << endl;

        //prompt the user for their choice
        while (hearts != 0 && won_game == false)
        {
            //output message
            cout << "\n\nBoulder, Parchment, Shears!" << endl;
            cout << "Enter choice below: " << endl;
            cin >> player_choice;

            //set player_choice to an integer value for comparison
            if (player_choice == "boulder" || player_choice == "Boulder")
            {
                player_num = 1;
            }
            else if (player_choice == "parchment" || player_choice == "Parchment")
            {
                player_num = 2;
            }
            else if (player_choice == "shears" || player_choice == "Shears")
            {
                player_num = 3;
            }
            else
            {
                //output invalid choice message
                cout << "That is not a valid option in this game." << endl;
            }

            //determine the door's choice
            //seed the random number generator
            srand(time(nullptr));
            
            //generate a random integer between 0 and 2
            door_choice = rand() % 3;

            //compare answers between the player and the door
            if (player_num == door_choice)
            {
                //output tie message
                cout << "\n\nTIE! We must continue.\n" << endl;
            }
            else if (door_choice == 1 && player_num == 3)
            {
                //door wins, boulder beats shears
                cout << "\n\nA loss to you.\n" << endl;

                //lose one heart
                hearts -= 1;
            }
            else if (door_choice == 2 && player_num == 1)
            {
                //door wins, parchment beats boulder
                cout << "\n\nA loss to you.\n" << endl;

                //lose one heart
                hearts -= 1;
            }
            else if (door_choice == 3 && player_num == 2)
            {
                //door wins, shears beats parchment
                cout << "\n\nA loss to you.\n" << endl;

                //lose one heart
                hearts -= 1;
            }
            else
            {
                //output victory message
                cout << "\n\nVictory is yours. You may proceed.\n" << endl;

                //set boolean to true to exit the while loop
                won_game = true;
            }
        }
    }

    //check to see if player lost
    if (hearts == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
