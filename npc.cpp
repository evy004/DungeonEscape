//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include "npc.h"
#include "roomSpace.h"
#include "Player.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <string>
#include <random>

vector<string> NPC::split(string input_string, string separator)
{
    //declare and initialize variables
    vector<string> result;
    int previous_delimiter_index = 0;
    
    //return 0 if the string is empty
    if (input_string.empty())
    {
        return result;
    }

    //iterate through the string
    for (int i = 0; i < input_string.length(); i++)
    {
        //if end of the string is reached, or separator is found
        if (i == input_string.length() || ( (i < input_string.length() - separator.length()) && (input_string.substr(i, separator.length())) == separator)){

            // Add the string before the separator to the result vector
            result.push_back(input_string.substr(previous_delimiter_index, i - previous_delimiter_index));
            // Set the previous separator to the index of the current separator
            previous_delimiter_index = i + separator.length();
        }

    }
    //returns the amount of split segments
    return result;
}

bool NPC::check_input(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        // if the number at i is less than the ascii value of 0 and larger than ascii value of 9
        if (input[i] < '0' || input[i] > '9')
        {
            return false; 
        }
    }
    return true;
}

//default constructor
NPC::NPC()
{
    steps = 0;
    name = "";
    dialogue = "";
}

//parameterized constructor
NPC::NPC(string name_, int steps_)
{
    name = name_;
    steps = steps_;
}

//reveals the space as an NPC space when the player enters for the first time
void NPC::revealNPCSpace(bool hasNPC)
{
    if (hasNPC == true) // Checks if the space at the space has an NPC
    {
        ifstream in_file("riddles.txt"); // If so, then open file for riddles.txt
        string copy; // Declare a string that copies getline copies
        vector<string> vect; // Declare a string vector for the split function

        //create randomizer for riddles
        //from https://www.w3schools.blog/select-one-random-element-of-a-vector-in-c
        int random = rand() % vect.size();
        string riddle_element = vect[random];
        
        int num_line = 0;
        while (getline(in_file, copy)) // Iterate a while loop that loops for the duration of the file
        {
            split(copy, "~"); // Split the lines from the riddle question from the riddle answer
            cout << vect.at(0) << endl; // Print out the riddle question
            
            num_line++;
        }
    }
    
    hasNPC = true;
    return;
}

//moves the party a single space in any of the cardinal directions
void NPC::moveParty(bool move)
{
    move = true;
    cout << "Moved" << endl;
}

//decreases each party member's fullness level with a 20% chance of dropping by 1
void NPC::decreaseFullness(bool move)
{
    move = true;
    cout << "Your health has decreased" << endl;
    //will modify to account for the chance percentage
}

//presents the player with a riddle puzzle to solve
bool NPC::solveRiddle(bool solve)
{
    solve = true;
    return solve;
}

//adjusts the item prices according to the number of cleared rooms
void NPC::adjustPrices(int num_cleared_rooms)
{
    //will account for the change in number of cleared rooms
    //the price adjustments will be changed accordingly
    cout << "The price has been adjusted" << endl;
}

//allows the player to barter for goods with the NPC
/**
 * Algorithm:
 * 1. Prompt the user for what they wish to buy
 * 2. update inventory based on choice
 * 3. implement input validation for each one
*/
void NPC::openMerchantMenu(int num_cleared_rooms, Player &player)
{
    cout << "You are eligible to barter" << endl;
    string input; // Input for main merchant menu
    string choice1; // Input for each sub-menu from the main menu choices
    string option1; // Input for yes or no confirmations

    // This is for increased merchant rates based on num_cleared_rooms
    double price = 1 + (0.25 * num_cleared_rooms);

    // Prints out introduction
    cout << "Between the 5 of you, you have 100 gold pieces." << endl;
    cout << "You will need to spend the some of your money on the following items:" << endl;
    cout << endl;

    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    cout << endl;

    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. \nBut beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;
    cout << endl;

    // Prints inventory
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << player.getGold() << endl;
    cout << "| Ingredients | " << player.getIngredients() << " kg" << endl;
    cout << "| Cookware    | P: " << player.getPot() << " | F: " << player.getPan() << " | C: " << player.getCauldron() << endl;
    cout << "| Weapons     | C: " << player.getStone() << " | S: " << player.getIron() << " | R: " << player.getRapier() << " | B: " << player.getAxe() << " | L: " << player.getLongsword() << endl;
    cout << "| Armor       | " << player.getArmor() << endl;
    cout << "| Treasures   | R: " << player.getSilver() << " | N: " << player.getRuby() << " | B: " << player.getEmerald() << " | C: " << player.getDiamond() << " | G: " << player.getGem() << endl;
    cout << endl;

    // Prints menu choices
    cout << "Choose one of the following:" << endl;
    cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
    cout << "2. Cookware: You will need something to cook those ingredients." << endl;
    cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
    cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
    cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
    cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
    cout << endl;

    cin.ignore();
    
    // Prompts user input
    getline(cin, input);

    //if valid input
    while (true)
    {
        if (!check_input(input)){ // if the input is not a valid integer, set input to -1 so that it will trigger the default case.
            input = "-1";
        }
        switch(stoi(input))
        {
            // if user inputs 1
            case 1:
                cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
                getline(cin, choice1); // prompts choice1 
                cout << endl;

                while (!check_input(choice1)){
                    cout << "That is not a valid input. Please enter a positive multiple of 5, or 0 to cancel." << endl;
                    getline(cin, choice1);
                    cout << endl;
                }
            
                // user validation for if choice1 is a multiple of 5 or a negative integer value
                if (stoi(choice1) % 5 != 0 || stoi(choice1) < 0)
                {
                    while (stoi(choice1) % 5 != 0 || stoi(choice1) < 0)
                    {
                        cout << "Your request is either not a multiple of 5 or is less than 0! Try again." << endl;
                        cout << endl;

                        cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
                        getline(cin, choice1); // prompts choice1
                        cout << endl;

                        while (!check_input(choice1)){
                            cout << "That is not a valid input. Please enter a positive multiple of 5, or 0 to cancel." << endl;
                            getline(cin, choice1);
                            cout << endl;
                        }
                    }
                }

                else if (stoi(choice1) == 0)
                {
                    cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    
                    break;
                }

                cout << "You want to buy " << choice1 << " kg of ingredients for " << stoi(choice1) * price << " Gold? (y/n)" << endl;
                getline(cin, option1); // prompts option1
                cout << endl;

                if (option1 == "y")
                {
                    if (player.getGold() - (stoi(choice1) * price) < 0)
                    {
                        cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }
                    else
                    {
                        player.setIngredients(player.getIngredients() + stoi(choice1));
                        player.setGold(player.getGold() - stoi(choice1) * price);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;

                    }
                }
                else if (option1 == "n")
                {
                    cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                }
                else
                {
                    cout << "Sorry, I don't understand that." << endl;
                }

                break;
            
            case 2:
                cout << "I have a several types of cookware, which one would you like?" << endl;
                cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
                cout << endl;

                cout << "Choose one of the following:" << endl;
                cout << "1. (25%) Ceramic Pot [2 Gold]" << endl;
                cout << "2. (10%) Frying Pan [10 Gold]" << endl;
                cout << "3. ( 2%) Cauldron [20 Gold]" << endl;
                cout << "4. Cancel" << endl;
                cout << endl;

                getline(cin, choice1); // prompts choice1
                cout << endl;

                while (!check_input(choice1)){
                    cout << "That is not a valid input. Please enter a number 1-4." << endl;
                    getline(cin, choice1);
                    cout << endl;
                }

                // input validation for if user input is not between 1 and 4 
                if (stoi(choice1) < 1 || stoi(choice1) > 4)
                {
                    while (stoi(choice1) < 1 || stoi(choice1) > 4)
                    {
                        cout << "You entered an invalid request. Try again." << endl;
                        cout << endl;

                        cout << "Choose one of the following:" << endl;
                        cout << "1. (25%) Ceramic Pot [2 Gold]" << endl;
                        cout << "2. (10%) Frying Pan [10 Gold]" << endl;
                        cout << "3. ( 2%) Cauldron [20 Gold]" << endl;
                        cout << "4. Cancel" << endl;
                        cout << endl;

                        getline(cin, choice1); // prompts choice1
                        cout << endl;
                    }
                }

                if (choice1 == "1")
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1))
                    {
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (choice1 == "0")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    // user validation for if choice1 is a multiple of 5 or a negative integer value
                    if (stoi(choice1) < 0)
                    {
                        while (stoi(choice1) < 0)
                        {
                            cout << "Your request is less than 0! You can't cheat me! Try again." << endl;
                            cout << endl;

                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            getline(cin, choice1); // prompts choice1
                            cout << endl;

                            while (!check_input(choice1)){
                                cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                                getline(cin, choice1);
                                cout << endl;
                            }
                        }
                    }

                    cout << "You want to buy " << choice1 << " Ceramic Pot(s) for " << stoi(choice1) * 2 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts choice1
                    cout << endl;

                    if (option1 == "y")
                    {
                        if (player.getGold() - (stoi(choice1) * price) < 0)
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;

                            break;
                        }
                        else
                        {
                            player.setPot(player.getPot() + stoi(choice1));
                            player.setGold(player.getGold() - stoi(choice1) * 2 * price);
                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 2)
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    cout << "You want to buy " << choice1 << " Frying Pan(s) for " << stoi(choice1) * 10 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts choice1 
                    cout << endl;

                    if (option1 == "y")
                    {
                        if (player.getGold() - (stoi(choice1) * price) < 0)
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;

                            break;
                        }
                        else
                        {
                            player.setPan(player.getPan() + stoi(choice1));
                            player.setGold(player.getGold() - stoi(choice1) * 10 * price);
                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 3)
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> choice1;
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    cout << "You want to buy " << choice1 << " Cauldron(s) for " << stoi(choice1) * 20 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;

                    if (option1 == "y")
                    {
                        if (player.getGold() - (stoi(choice1) * price) < 0)
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;

                            break;
                        }
                        else
                        {
                            player.setCauldron(player.getCauldron() + stoi(choice1));
                            player.setGold(player.getGold() - (stoi(choice1) * 20 * price));
                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 4)
                {
                    cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                }
                else
                {
                    cout << "Sorry, that's not one of the options provided. Try again?" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << "\n\n";
                }
                cout << endl;

                break;

            case 3:
                cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
                cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
                cout << endl;
                
                cout << "Choose one of the following:" << endl;
                cout << "1. Stone Club [2 Gold]" << endl;
                cout << "2. Iron Spear [2 Gold]" << endl;
                cout << "3. (+1) Mythril Rapier [5 Gold]" << endl;
                cout << "4. (+2) Flaming Battle-Axe [15 Gold]" << endl;
                cout << "5. (+3) Vorpal Longsword [50 Gold]" << endl;
                cout << "6. Cancel" << endl;
                cout << endl;

                getline(cin, choice1); // prompts choice1
                cout << endl;

                while (!check_input(choice1)){
                    cout << "That is not a valid input. Please enter a number between 1-6." << endl;
                    getline(cin, choice1);
                    cout << endl;
                }

                if (stoi(choice1) == 1)
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while(!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    cout << "You want to buy " << choice1 << " Stone Club(s) for " << stoi(choice1) * 2 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts choice1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        if ((player.getGold() - (stoi(choice1) * price )< 0))
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;

                            break;
                        }
                        else
                        {
                            player.setStone(player.getStone() + stoi(choice1));
                            player.setGold(player.getGold() - stoi(choice1) * 2 * price);
                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 2)
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    cout << "You want to buy " << choice1 << " Iron Spear(s) for " << stoi(choice1) * 2 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        if (player.getGold() - (stoi(choice1) * price) < 0)
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;

                            break;
                        }
                        else
                        {
                            player.setIron(player.getIron() + stoi(choice1));
                            player.setGold(player.getGold() - stoi(choice1) * 2 * price);
                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 3)
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    cout << "You want to buy " << choice1 << " (+1) Mythril Rapier(s) for " << stoi(choice1) * 5 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        if (player.getGold() - (stoi(choice1) * price) < 0)
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;
                            break;
                        }
                        else
                        {
                            player.setRapier(player.getRapier() + stoi(choice1));
                            player.setGold(player.getGold() - stoi(choice1) * 5 * price);
                            cout << "Which member would you like to add this to?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 4)
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    cout << "You want to buy " << choice1 << " (+2) Flaming Battle-Axe(s) for " << stoi(choice1) * 15 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        if (player.getGold() - (stoi(choice1) * price) < 0)
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;
                            break;
                        }
                        else
                        {
                            player.setAxe(player.getAxe() + stoi(choice1));
                            player.setGold(player.getGold() - stoi(choice1) * 15 * price);
                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 5)
                {
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    cout << "You want to buy " << choice1 << " (+3) Vorpal Longsword(s) for " << stoi(choice1) * 50 * price << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        if (player.getGold() - (stoi(choice1) * price) < 0)
                        {
                            cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                            cout << endl;
                            break;
                        }
                        else
                        {
                            player.setLongsword(player.getLongsword() + stoi(choice1));
                            player.setGold(player.getGold() - stoi(choice1) * 50 * price);
                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        }
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 6)
                {
                    cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                }
                else
                {
                    cout << "Sorry, that's not one of the options. Try again." << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << "\n\n";
                }
                
                cout << endl;

                break;
            
            case 4:
                cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
                getline(cin, choice1); // prompts choice1
                cout << endl;

                while (!check_input(choice1)){
                    cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                    getline(cin, choice1);
                    cout << endl;
                }

                if (stoi(choice1) == 0)
                {
                    cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    cout << endl;

                    break;
                }

                cout << "You want to buy " << choice1 << " suit(s) of armor for " << stoi(choice1) * 5 * price << " Gold? (y/n)" << endl;
                getline(cin, option1); // prompts option1
                cout << endl;

                if (option1 == "y")
                {
                    if (player.getGold() - (stoi(choice1) * price) < 0)
                    {
                        cout << "You do not have enough to buy this! What else can I get for you?" << endl;
                        cout << endl;
                        break;
                    }
                    else
                    {
                        player.setArmor(player.getArmor() + stoi(choice1));
                        player.setGold(player.getGold() - stoi(choice1) * 5 * price);
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        cout << endl;
                    }
                }
                else if (option1 == "n")
                {
                    cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    cout << endl;
                }
                else
                {
                    cout << "Sorry, I don't understand that." << endl;
                }

                break;

            case 5:
                cout << "If you have some sweet loot, I will be more than happy to accept it... with monetary reward of course!" << endl;
                cout << "Please choose which item you would like to sell!" << endl;
                cout << endl;

                cout << "Choose one of the following:" << endl;
                cout << "1. Silver Ring [10 Gold]" << endl;
                cout << "2. Ruby Necklace [20 Gold]" << endl;
                cout << "3. Emerald Bracelet [30 Gold]" << endl;
                cout << "4. Diamond Circlet [40 Gold]" << endl;
                cout << "5. Gem-Encrusted Goblet [50 Gold]" << endl;
                cout << "6. Cancel" << endl;
                cout << endl;

                getline(cin, choice1); // prompts choice1
                cout << endl;

                while (!check_input(choice1)){
                    cout << "That is not a valid input. Please enter a number between 1-6." << endl;
                    getline(cin, choice1);
                    cout << endl;
                }

                if (stoi(choice1) == 1)
                {
                    cout << "How many Silver Rings would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getSilver() == 0)
                    {
                        cout << "You do not have any items to sell. What else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getSilver() < stoi(choice1))
                    {
                        while (player.getSilver() < stoi(choice1))
                        {
                            cout << "You do not have enough of this item to sell the desired amount. Please enter another amount!" << endl;
                            getline(cin, choice1); // prompts choice1
                        }
                    }

                    cout << "You want to sell " << choice1 << " Silver Ring(s) for " << stoi(choice1) * 10 << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        player.setSilver(player.getSilver() - stoi(choice1));
                        player.setGold(player.getGold() + stoi(choice1) * 10);
                        cout << "Thank you for your contribution! What else can I do for you?" << endl;
                        cout << endl;
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 2)
                {
                    cout << "How many Ruby Necklaces would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getRuby() == 0)
                    {
                        cout << "You do not have any items to sell. What else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getRuby() < stoi(choice1))
                    {
                        while (player.getRuby() < stoi(choice1))
                        {
                            cout << "You do not have enough of this item to sell the desired amount. Please enter another amount!" << endl;
                            getline(cin, choice1); // prompts choice1
                        }
                    }

                    cout << "You want to sell " << choice1 << " Ruby Necklace(s) for " << stoi(choice1) * 20 << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        player.setRuby(player.getRuby() - stoi(choice1));
                        player.setGold(player.getGold() + stoi(choice1) * 20);
                        cout << "Thank you for your contribution! What else can I do for you?" << endl;
                        cout << endl;
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 3)
                {
                    cout << "How many Emerald Bracelets would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getEmerald() == 0)
                    {
                        cout << "You do not have any items to sell. What else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getEmerald() < stoi(choice1))
                    {
                        while (player.getEmerald() < stoi(choice1))
                        {
                            cout << "You do not have enough of this item to sell the desired amount. Please enter another amount!" << endl;
                            getline(cin, choice1); // prompts choice1
                        }
                    }

                    cout << "You want to sell " << choice1 << " Emerald Bracelet(s) for " << stoi(choice1) * 30 << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        player.setEmerald(player.getEmerald() - stoi(choice1));
                        player.setGold(player.getGold() + (stoi(choice1) * 30));
                        cout << "Thank you for your contribution! What else can I do for you?" << endl;
                        cout << endl;
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 4)
                {
                    cout << "How many Diamond Circlets would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getDiamond() == 0)
                    {
                        cout << "You do not have any items to sell. What else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getDiamond() < stoi(choice1))
                    {
                        while (player.getDiamond() < stoi(choice1))
                        {
                            cout << "You do not have enough of this item to sell the desired amount. Please enter another amount!" << endl;
                            getline(cin, choice1); // prompts choice1
                        }
                    }

                    cout << "You want to sell " << choice1 << " Diamond Circlet(s) for " << stoi(choice1) * 40 << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        player.setDiamond(player.getDiamond()- stoi(choice1));
                        player.setGold(player.getGold() + (stoi(choice1) * 40));
                        cout << "Thank you for your contribution! What else can I do for you?" << endl;
                        cout << endl;
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }
                else if (stoi(choice1) == 5)
                {
                    cout << "How many Gem-Encrusted Goblets would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, choice1); // prompts choice1
                    cout << endl;

                    while (!check_input(choice1)){
                        cout << "That is not a valid input. Please enter a positive integer, or 0 to cancel." << endl;
                        getline(cin, choice1);
                        cout << endl;
                    }

                    if (stoi(choice1) == 0)
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getGem() == 0)
                    {
                        cout << "You do not have any items to sell. What else can I get for you?" << endl;
                        cout << endl;

                        break;
                    }

                    if (player.getGem() < stoi(choice1))
                    {
                        while (player.getGem() < stoi(choice1))
                        {
                            cout << "You do not have enough of this item to sell the desired amount. Please enter another amount!" << endl;
                            getline(cin, choice1); // prompts choice1
                        }
                    }

                    cout << "You want to sell " << choice1 << " Gem-Encrusted Goblet(s) for " << stoi(choice1) * 50 << " Gold? (y/n)" << endl;
                    getline(cin, option1); // prompts option1
                    cout << endl;
                    
                    if (option1 == "y")
                    {
                        player.setGem(player.getGem() - stoi(choice1));
                        player.setGem(player.getGold() + (stoi(choice1) * 50));
                        cout << "Thank you for your contribution! What else can I do for you?" << endl;
                        cout << endl;
                    }
                    else if (option1 == "n")
                    {
                        cout << "You've changed your mind? No worries, what else can I do for you?" << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << "Sorry, I don't understand that." << endl;
                    }
                }

                break;
            
            case 6:
                cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
                getline(cin, option1); // prompts option1
                cout << endl;

                if (option1 == "y")
                {
                    cout << "Stay safe out there! Goodbye!" << endl;
                    cout << endl;
                    return;
                }
                else if (option1 == "n")
                {
                    cout << "You've changed your mind? No worries, what else can I get for you?" << endl;
                    cout << endl;
                }
                else
                {
                    cout << "Sorry, I don't understand that." << endl;
                }

                break;  
            default:
                cout << "\nThat is not a valid option. Please choose an option 1-6." << endl;
                cout << "Choose one of the following:" << endl;
                cout << endl;

                cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
                cout << "2. Cookware: You will need something to cook those ingredients." << endl;
                cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
                cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
                cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
                cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
                cout << endl;

                getline(cin, input); //prompt user    
        }

        cout << "+-------------+" << endl;
        cout << "| INVENTORY   |" << endl;
        cout << "+-------------+" << endl;
        cout << "| Gold        | " << player.getGold() << endl;
        cout << "| Ingredients | " << player.getIngredients() << " kg" << endl;
        cout << "| Cookware    | P: " << player.getPot() << " | F: " << player.getPan() << " | C: " << player.getCauldron() << endl;
        cout << "| Weapons     | C: " << player.getStone() << " | S: " << player.getIron() << " | R: " << player.getRapier() << " | B: " << player.getAxe() << " | L: " << player.getLongsword() << endl;
        cout << "| Armor       | " << player.getArmor() << endl;
        cout << "| Treasures   | R: " << player.getSilver() << " | N: " << player.getRuby() << " | B: " << player.getEmerald() << " | C: " << player.getDiamond() << " | G: " << player.getGem() << endl;
        cout << endl;

        cout << "Choose one of the following:" << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cout << endl;

        getline(cin, input); // prompts input
    }

    return;
    //based on the number of cleared room, the bartering options will change
}

//if NPC is hostile, summons a random monster to fight 
bool NPC::summonMonster(bool hostile)
{
    //if the NPC is hostile, will summon a random monster
    //if the monster is summoned successfully, return true
    hostile = true;
    return hostile;
}

//handles the actions to take when the player speaks to the NPC
void NPC::speakNPC(int num_cleared_rooms)
{
    //will output specific dialogue
    cout << dialogue << endl;
}

//ends the game when the player chooses to give up.
void NPC::giveUp()
{
    //will account for player giving up
    //changing alive status
    //restarts game
    cout << "You have given up" << endl;
}