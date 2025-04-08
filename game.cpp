//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <vector>
#include <fstream>
#include "monster.h"
#include "Player.h"
#include "Map.h"
#include "roomSpace.h"
#include "npc.h"
#include "game.h"
using namespace std;

//default constructor
Game::Game()
{
    start_game = true;
    //player_;
    //map_;
    level_difficulty = 0;
    num_items = 0;
}

//display main menu
void Game::main_menu()
{
    //will update later to output basee on each of the selected options
    cout << "Select one:" << endl;
    cout << "1. Move" << endl;
    cout << "2. Investigate" << endl;
    cout << "3. Pick a Fight" << endl;
    cout << "4. Cook and Eat" << endl;
    cout << "5. Give up" << endl;
}

//randomize map
/**
 * Algorithm:
 * 1. Initialize variables: Set `room_count` and `npc_count` to zero, and create `row`, `column`, and `map` variables.
 * 2. Generate rooms: Use a `while` loop to generate 5 different rooms. In each iteration of the loop, generate random `row` and `column` values between 1-12. 
 *    Check if the generated coordinates are free by calling the `isFreeSpace` function on the `map` object with the `row` and `column` parameters. If the function 
 *    returns `true`, add a room to the `map` object at the `row` and `column` coordinates by calling the `addRoom` function, and set the location to no longer 
 *    be free by calling the `isRoomLocation` function with the `row` and `column` parameters. Finally, increment `room_count`.
 * 3. Generate NPCs: Use another `while` loop to generate 5 random NPC locations. In each iteration of the loop, generate random `row` and `column` values between 1-12. 
 *    Check if the generated coordinates are free by calling the `isFreeSpace` function on the `map` object with the `row` and `column` parameters. If the function 
 *    returns `true`, add an NPC to the `map` object at the `row` and `column` coordinates by calling the `addNPC` function, and set the location to no longer be free 
 *    by calling the `isNPCLocation` function with the `row` and `column` parameters. Finally, increment `npc_count`.
 * 4. Display the map: Call the `displayMap` function on the `map` object to display the new map.
 * 5. Return the map: Return the `map` object from the function.
*/
Map Game::randomMap()
{
    //add a room
        int room_count = 0;
        int npc_count = 0;
        int row = 0;
        int column = 0;
        Map map;

        //generate 5 different rooms
        while (room_count < 5)
        {
            //randomize numbers between 1-12
            row = rand() % 12 + 1;

            //randomize numbers between 1-12
            column = rand() % 12 + 1;

            //check to see if the generated coords are free
            if(map.isFreeSpace(row, column) == true)
            {
                //add room into map
                map.addRoom(row, column);

                //set it to no longer a free space
                map.isRoomLocation(row, column);

                //increase room count
                room_count++;
            }
        }

        //generate 5 random NPC locations
        while (npc_count < 5)
        {
            //randomize numbers between 1-12
            row = rand() % 12 + 1;

            //randomize numbers between 1-12
            column = rand() % 12 + 1;

            //check to see if the generated coords are free
            if(map.isFreeSpace(row, column) == true)
            {
                //add room into map
                map.addNPC(row, column);

                //set it to no longer a free space
                map.isNPCLocation(row, column);

                //increase room count
                npc_count++;
            }
        }

        //display the new map
        map.displayMap();

        //return map
        return map;
}

//display player stats
/**
 * Algorithm:
 * 1. Define a function called displayStats that takes in an array of Player objects called team, an integer called num_rooms_cleared, an integer called key_count, 
 *    and an integer called sorcerer_anger.
 * 2. Declare and initialize two variables called npc and player.
 * 3. Output a menu with the heading "STATUS".
 * 4. Output the number of rooms cleared, keys, and sorcerer anger level.
 * 5. Output another menu with the heading "INVENTORY".
 * 6. Output the player's gold, ingredients, cookware, weapons, armor, and treasures.
 * 7. Output another menu with the heading "PARTY".
 * 8. Check if the first player in the array (the party leader) is alive, and output their name and fullness if they are.
 * 9. If the first player is dead, output their name and "DEAD".
 * 10. Repeat steps 8-9 for each of the remaining party members in the array.
 * 11. Output the end line.
*/
void Game::displayStats(Player team[], int num_rooms_cleared, int key_count, int sorcerer_anger)
{
    //declare and initialize any needed variables
    NPC npc;
    Player player;

    //output display menu
    cout << "+-------------+" << endl;
    cout << "|    STATUS   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << num_rooms_cleared << " | Keys: " << key_count << " | Anger Level: " << sorcerer_anger << endl;
    cout << "+-------------+" << endl;
    cout << "|  INVENTORY  |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << player.getGold() << endl;
    cout << "| Ingredients | " << player.getIngredients() << " kg" << endl;
    cout << "| Cookware    | P: " << player.getPot() << " | F: " << player.getPan() << " | C: " << player.getCauldron() << endl;
    cout << "| Weapons     | C: " << player.getStone() << " | S: " << player.getIron() << " | R: " << player.getRapier() << " | B: " << player.getAxe() << " | L: " << player.getLongsword() << endl;
    cout << "| Armor       | " << player.getArmor() << endl;
    cout << "| Treasures   | R: " << player.getSilver() << " | N: " << player.getRuby() << " | B: " << player.getEmerald() << " | C: " << player.getDiamond() << " | G: " << player.getGem() << endl;
    cout << "+-------------+" << endl;
    cout << "|    PARTY    |" << endl;
    cout << "+-------------+" << endl;

    //check to see if party leader is dead
    if (team[0].isAlive())
    {
        cout << "| " << team[0].getPlayerName() << " | Fullness: " << team[0].getFullness() << endl;
    }
    else if (team[0].isSlain())
    {
        cout << "| " << team[0].getPlayerName() << " | DEAD" << endl;
    }

    //party member 1:
    if (team[1].isAlive())
    {
        cout << "| " << team[1].getPlayerName() << " | Fullness: " << team[1].getFullness() << endl;
    }
    else if (team[1].isSlain())
    {
        cout << "| " << team[1].getPlayerName() << " | DEAD" << endl;
    }

    //party member 2:
    if (team[2].isAlive())
    {
        cout << "| " << team[2].getPlayerName() << " | Fullness: " << team[2].getFullness() << endl;
    }
    else if (team[2].isSlain())
    {
        cout << "| " << team[2].getPlayerName() << " | DEAD" << endl;
    }

    //party member 3:
    if (team[3].isAlive())
    {
        cout << "| " << team[3].getPlayerName() << " | Fullness: " << team[3].getFullness() << endl;
    }
    else if (team[3].isSlain())
    {
        cout << "| " << team[3].getPlayerName() << " | DEAD" << endl;
    }

    //party member 4:
    if (team[4].isAlive())
    {
        cout << "| " << team[4].getPlayerName() << " | Fullness: " << team[4].getFullness() << endl;
    }
    else if (team[4].isSlain())
    {
        cout << "| " << team[4].getPlayerName() << " | DEAD" << endl;
    }

    //output the end line
    cout << "+-------------+" << endl;
    cout << endl;
}

//get player team
void Game::getPlayerTeam()
{
    for (int i = 0; i < 4; i++)
    {
        cout << team[i] << endl;
    }
}

//set player team
void Game::setPlayerTeam(string a[])
{
    for (int i = 0; i < 4; i++)
    {
        team[i] = a[i];
    }
}

//checks the current size of the team
/**
 * Algorithm:
 * 1. Initialize an integer variable "alive_count" to 0.
 * 2. Loop through each Player object in the team array using a for loop.
    a. Check if the current Player object is alive using the isAlive() function.
    b. If the current Player object is alive, increment the alive_count variable by 1.
    3. Return the alive_count variable as the output of the function.
*/
int Game::getTeamSize(Player team[])
{
    //declare and initialize any needed variables
    int alive_count = 0;

    //loop through to see the members of the team that are still alive
    for (int i = 0; i < 5; i++)
    {
        //check to see which are still alive
        if (team[i].isAlive() == true)
        {
            alive_count++;
        }
    }

    return alive_count;
}

//gets team fullness
/**
 * Algorithm:
 * 1. Take in the array of the team
 * 2. Iterate through the team and output fullness for each member
*/
void Game::getTeamFullness(Player team[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << team[i].getFullness() << endl;
    }

}

//prompt misfortune
/**
 * Algorithm
 * 1. Generate a random number between 1-100 to determine chance of misfortune.
 * 2. If chance is less than or equal to 30, team gets robbed by dungeon bandits:
 * 3. Randomly select an item to be robbed of: ingredients, cookware, or armor.
 * 4. Subtract the stolen item from the player's inventory.
 * 5. If chance is between 31-40, player's armor breaks.
 * 6. If chance is between 41-70, a random party member suffers from food poisoning 
 *    and their fullness decreases by 10 points.
*/
void Game::misfortune(Player team[], int prev_move)
{
    //declare and initialize any needed variables
    int rand_num = 0;
    NPC npc;
    Player player;
    
    //4 misfortunes that may occur
    //seed the random number generator
    srand(time(NULL));

    //generate a random number within 1-100 for chance
    rand_num = rand() % 100 + 1;

    //check to see chance of misfortune occurring
    if (rand_num <= 30) //30% chance of being robbed by bandits
    {
        //output oh no message
        cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;

        //randomly select an item to be robbed of
        int stolen_goods = rand() % 3;

        //determine amount based on item stolen
        if (stolen_goods == 0)
        {
            //if user currently possesses at least 10 kg of ingredients
            if (player.getIngredients() >= 10)
            {
                //output misfortune back to user
                cout << "You lost 10 kg of ingredients!" << endl;

                //subtract 10kg from current amount
                player.changeIngredients(-10);
            }
            else
            {
                //player loses all current ingredients
                cout << "\nYou have lost all your ingredients." << endl;

                //set ingredients back to 0
                player.setIngredients(0);
            }
        }
        else if (stolen_goods == 1)
        {
            //make sure player currently owns cookware to be robbed of
            if (player.getCookware() > 0)
            {
                //randomly select
                int rand_cookware = rand() % 3;

                //subtract the piece of cookware from player inventory
                if (rand_cookware == 0)
                {
                    //check to see if user owns enough pots
                    if(player.getPot() > 0)
                    {
                        //subtract one from pot count
                        player.setPot(-1);

                        //output misfortune message
                        cout << "\nYou have lost 1 Pot!" << endl;
                    }
                }
                else if (rand_cookware == 1)
                {
                    //check to see if user owns enough pans
                    if(player.getPan() > 0)
                    {
                        //subtract one from pan count
                        player.setPan(-1);

                        //output misfortune message
                        cout << "\nYou have lost 1 Pan!" << endl;
                    }
                }
                else if (rand_cookware == 2)
                {
                    //check to see if user owns enough pots
                    if(player.getCauldron() > 0)
                    {
                        //subtract one from pot count
                        player.setCauldron(-1);

                        //output misfortune message
                        cout << "\nYou have lost 1 Cauldron!" << endl;
                    }
                }
                else //rob the user of whichever they have
                {
                    //check to see if user owns enough pots
                    if(player.getPot() > 0)
                    {
                        //subtract one from pot count
                        player.setPot(-1);

                        //output misfortune message
                        cout << "\nYou have lost 1 Pot!" << endl;
                    }
                    //check to see if user owns enough pans
                    else if(player.getPan() > 0)
                    {
                        //subtract one from pot count
                        player.setPan(-1);

                        //output misfortune message
                        cout << "\nYou have lost 1 Pan!" << endl;
                    }
                    //check to see if user owns enough pots
                    else if(player.getCauldron() > 0)
                    {
                        //subtract one from pot count
                        player.setCauldron(-1);

                        //output misfortune message
                        cout << "\nYou have lost 1 Cauldron!" << endl;
                    }
                }
            }
        }
        else if (stolen_goods == 2) //stolen armor !
        {
            //check to see if user has enough armor
            if (player.getArmor() > 0)
            {
                //subtract 1 piece of armor
                player.setArmor(-1);

                //output misfortune message
                cout << "\nYou have lost 1 Piece of Armor!" << endl;
            }
        }
        else
        {
            //output poor people message
            cout << "\nLucky! You got away because you had nothing of value." << endl;
        } 
    }
    else if (rand_num <= 40) //10% chance of weapon/armor breaking
    {
        cout << "Your armor broke :(" << endl;
    }
    else if (rand_num <= 70) //30% chance of food poisoning
    {
        //create a boolean for party member selection
        bool rand_alive = false;

        //get player size
        int team_size = getTeamSize(team);

        //randomly select a party member
        int rand_member = rand() % team_size + 1;

        //while loop to check for a while loop
        while (rand_alive == false)
        {
            //check to see if the player was currently alive
            if (team[rand_member].isAlive())
            {
                //set alive to true
                rand_alive = true;

                //decrease that party member's fullness by 10 points
                team[rand_member].increaseHunger(10);

                //output message to user
                cout << "\nOH NO! " << team[rand_member].getPlayerName() << " ate something funky and got food poisoning." << endl;
                cout << "Their hunger has decreased by ten points." << endl;

                //check to see if anyone died
                for (int i = 1; i < 5; i++)
                {
                    //check to see if player currently has fullness
                    if (team[i].getFullness() < 1)
                    {
                        //member dies of hunger
                        team[i].die();
                    }
                }

                //check to see if player has died of hunger
                if (team[rand_member].getFullness() < 0)
                {
                    //player dies of hunger
                    player.die();

                    //check to see if that was the last player standing
                    int team_status = getTeamSize(team);

                    //see if player lost the game
                    if (team_status == 1)
                    {
                        //run end game
                        end(1);
                    }
                }
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
    }
    else //30% of player being locked behind, given that the previous move was room
    {
        if (prev_move == 1) //if previous move was player trying to open door
        {
            //get player size
            int team_size = getTeamSize(team);

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
                    int team_size = getTeamSize(team);

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
        }
    }
}

//start game
void Game::start()
{
    cout << "\nLoading...\n\n" << endl;
    //starting the game, will display main menu
}

//final boss
/**
 * Algorithm:
 * 1. Declare and initialize the necessary variables
 * 2. Output the sorcerer picture
 * 3. Start stage 1 while boss1_hp > 0
    a. Prompt the user for attack or defend
    b. Check the user's choice
    c. Based on the user's choice, attack or defend
    d. Calculate the damage done by the user and the boss
    e. Update boss1_hp and user_hp
 * 4. Output "You have downed the Sorcerer!"
 * 5. Start stage 2 while boss2_hp > 0
    a. Prompt the user for attack or defend
    b. Check the user's choice
    c. Based on the user's choice, attack or defend
    d. Calculate the damage done by the user and the boss
    e. Update boss2_hp and user_hp
 * Output "Congratulations! You have defeated the Sorcerer!"
*/
void Game::final_boss()
{
    //declare and initialize variables
    int prob_hit = 0;
    int prob_def = 0;
    int user_hp = 200;
    int rand_puzzle = 0;
    int secret_num = 0;
    string choice = "";
    int num_guess = 0;
    ifstream file("resources/sorcerer.txt");
    string line = "";

    //when encountering the final boss, the difficulty will be increased
    //have 2 stages of the fight
    cout << "Here is the final boss!" << endl;

    //output the sorcerer pic
    while(getline(file, line))
    {
        cout << line << endl;
    }

    //seed a random number generator
    srand(time(NULL));

    //stage 1:
    int boss1_hp = 50;

    //output
    cout << "\n\n\n\n\n\n\n\n" << endl;
    cout << "==============================" << endl;
    cout << "=       SORCERER BATTLE      =" << endl;
    cout << "==============================" << endl;
    cout << "\n\n\n\n\n\n\n\n" << endl;

    //while the boss is still alive
    while(boss1_hp > 0)
    {
        //check to see if user still has health
        if (user_hp < 1)
        {
            //output loss message
            cout << "The Sorcerer absolutely demolished you." << endl;

            //end game
            end(1);
        }

        //prompt user for attack
        cout << "Do you wish to attack or defend?" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;
        getline(cin, choice);

        //check user's choice
        if (choice == "1")
        {
            //prompt a random hit
            prob_hit = rand() % 100;

            //5% chance of the boss losing 15 hp
            if(prob_hit < 5)
            {
                //subtract health
                boss1_hp -= 15;

                //update user
                cout << "WOW! The Sorcerer has lost 15 hp!" << "HP Left: " << boss1_hp << endl;
            }
            else if (prob_hit < 25) //20% chance of the boss losing 10hp
            {
                boss1_hp -= 10;

                //update user
                cout << "NICE HIT! The Sorcerer has lost 10 hp!" << "HP Left: " << boss1_hp << endl;
            }
            else if (prob_hit < 60) //35% chance of the boss losing 5 hp
            {
                boss1_hp -= 5;

                //update user
                cout << "Good hit! The Sorcerer has lost 5 hp!" << "HP Left: " << boss1_hp << endl;
            }
            else //40% chance of boss losing 3 hp
            {
                boss1_hp -= 3;

                //update user
                cout << "Nice! The Sorcerer has lost 3 hp!" << "HP Left: " << boss1_hp << endl;
            }

            //user takes hit
            cout << "The Sorcerer strikes back! You have lost 7 health." << endl;
            user_hp -= 7;
        }
        else if (choice == "2")
        {
            //defend against attack
            prob_def = rand() % 100;

            //5% chance of losing 15 hp
            if(prob_def < 5)
            {
                //subtract health
                user_hp -= 15;

                //update user
                cout << "OUCH! The Sorcerer set you ablaze! HP Left: " << user_hp << endl;
            }
            else if (prob_def < 25) //20% chance of losing 10hp
            {
                user_hp -= 10;

                //update user
                cout << "OOH! The Sorcerer sliced your skin! HP Left: " << user_hp << endl;
            }
            else if (prob_def < 60) //35% chance of losing 5 hp
            {
                user_hp -= 5;

                //update user
                cout << "Oh! The Sorcerer seared your hair!" << "HP Left: " << user_hp << endl;
            }
            else //40% chance losing 2 hp
            {
                user_hp -= 2;

                //update user
                cout << "Nice Block! The Sorcerer barely got you!" << "HP Left: " << user_hp << endl;
            }
        }
        else
        {
            //invalid input
            cout << "Not a valid choice, sorry! Choose again." << endl;
        }
    
    }

    //tell the user they beat the first stage
    cout << "You have downed the Sorcerer!" << endl;
    cout << "\n.........\n" << endl;

    //stage 2:
    int boss2_hp = 100;

    //output
    cout << "The sorcerer has risen once again! His health has increased to 100." << endl;

    //while the boss is still alive
    while(boss2_hp > 0)
    {
        //check to see if user still has health
        if (user_hp < 1)
        {
            //output loss message
            cout << "The Sorcerer absolutely demolished you." << endl;

            //end game
            end(1);
        }
        
        //prompt user for attack
        cout << "Do you wish to attack or defend?" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;
        getline(cin, choice);

        //check user's choice
        if (choice == "1")
        {
            //prompt a random hit
            prob_hit = rand() % 100;

            //3% chance of the boss losing 15 hp
            if(prob_hit < 3)
            {
                //subtract health
                boss2_hp -= 20;

                //update user
                cout << "WOW! The Sorcerer has lost 15 hp! HP Left: " << boss2_hp << endl;
            }
            else if (prob_hit < 25) //20% chance of the boss losing 10hp
            {
                boss2_hp -= 10;

                //update user
                cout << "NICE HIT! The Sorcerer has lost 10 hp! HP Left: " << boss2_hp << endl;
            }
            else if (prob_hit < 60) //35% chance of the boss losing 5 hp
            {
                boss2_hp -= 5;

                //update user
                cout << "Good hit! The Sorcerer has lost 5 hp! HP Left: " << boss2_hp << endl;
            }
            else //40% chance of boss losing 3 hp
            {
                boss2_hp -= 3;

                //update user
                cout << "Nice! The Sorcerer has lost 3 hp! HP Left: " << boss2_hp << endl;
            }

            //user takes hit
            cout << "The Sorcerer strikes back! You have lost 7 health." << endl;
            user_hp -= 7;
        }
        else if (choice == "2")
        {
            //defend against attack
            prob_def = rand() % 100;

            //5% chance of losing 15 hp
            if(prob_def < 5)
            {
                //subtract health
                user_hp -= 15;

                //update user
                cout << "OUCH! The Sorcerer set you ablaze! HP Left: " << user_hp << endl;
            }
            else if (prob_def < 25) //20% chance of losing 10hp
            {
                user_hp -= 10;

                //update user
                cout << "OOH! The Sorcerer sliced your skin! HP Left: " << user_hp << endl;
            }
            else if (prob_def < 60) //35% chance of losing 5 hp
            {
                user_hp -= 5;

                //update user
                cout << "Oh! The Sorcerer seared your hair!" << "HP Left: " << user_hp << endl;
            }
            else //40% chance losing 2 hp
            {
                user_hp -= 2;

                //update user
                cout << "Nice Block! The Sorcerer barely got you!" << "HP Left: " << user_hp << endl;
            }
        }
        else
        {
            //invalid input
            cout << "Not a valid choice, sorry! Choose again." << endl;
        }

        //prompt 20% chance for random puzzle
        rand_puzzle = rand() % 20;
        if(rand_puzzle < 2)
        {
            //generate secret number
            secret_num = rand() % 10 + 1;

            //prompt user for their guess
            cout << "QUICK! Choose a number from 1-10!" << endl;
            cin >> num_guess;

            //check to see if user guessed correctly
            if (num_guess == secret_num)
            {
                //subtract sorcerer health
                boss2_hp -= 25;

                //secret attack unlocked
                cout << "NICE! You sizzled the Sorcerer's beard! He lost 25 hp. HP Left: " << boss2_hp << endl;
            }
            else
            {
                cout << "Sorry, but WRONG! Better luck next time." << endl;
            }
        }
    }
}

//end game stats
/**
 * Algorithm:
 * 1. Output the display menu with the header "END GAME STATS".
 * 2. Output the number of rooms cleared.
 * 3. Output the amount of gold remaining for the player.
 * 4. Output the number of treasures possessed by the player, including silver, ruby, emerald, diamond, and gem.
 * 5. Output the number of spaces explored.
 * 6. Output the number of monsters defeated.
 * 7.Output the number of turns elapsed.
 * 8. Output the display menu with the header "PARTY".
 * 9. Output the name of the leader of the team.
 * 10. Loop through the remaining members of the team (indices 1-4).
 * 11. Check if the member is still alive.
 * 12. If the member is alive, output their name.
 * 13. End the loop.
 * 14. End the function.
*/
void Game::endGameStats(Player team[], int rooms_cleared, int spaces_explored, int monsters_defeated, int turns, Player &player)
{
    //output display menu
    cout << "+=====================+" << endl;
    cout << "|    END GAME STATS   |" << endl;
    cout << "+=====================+" << endl;
    cout << "| Rooms Cleared: " << rooms_cleared << endl;
    cout << "| Gold Remaining: " << player.getGold() << endl;
    cout << "| Treasures Possessed: " << player.getSilver() << " | N: " << player.getRuby() << " | B: " << player.getEmerald() << " | C: " << player.getDiamond() << " | G: " << player.getGem() << endl;
    cout << "| Spaces Explored: " << spaces_explored << endl;
    cout << "| Monsters Defeated: " << monsters_defeated << endl;
    cout << "| Turns Elapsed: " << turns << endl;
    cout << "+=====================+" << endl;
    cout << "|        PARTY        |" << endl;
    cout << "+=====================+" << endl;
    cout << "| Leader: " << team[0].getPlayerName() << endl;

    //determine which members are still alive
    for (int i = 1; i < 5; i++)
    {
        //check to see if the member is alive
        if (team[i].isAlive() == true)
        {
            //output player
            cout << "| Member: " << team[i].getPlayerName() << endl;
        }
    }
}

//end game
/**
 * Algorithm:
 * 1. Outputs different messages based on outcome
*/
bool Game::end(int win_lose)
{
    //output loss message
    if (win_lose == 1)
    {
        //player has lost the game
        cout << "\n\n\n\n\n\n\n\n" << endl;
        cout << "==============================" << endl;
        cout << "=      YOU WERE DEFEATED     =" << endl;
        cout << "==============================" << endl;
        cout << "\n\n\n\n\n\n\n\n" << endl;
    }
    else if (win_lose == 2)
    {
        //player has exited the game
        cout << "\n\n\n\n\n\n\n\n" << endl;
        cout << "==============================" << endl;
        cout << "=          FAREWELL!         =" << endl;
        cout << "==============================" << endl;
        cout << "\n\n\n\n\n\n\n\n" << endl;
    }
    else
    {
        //player won
        cout << "\n\n\n\n\n\n\n\n" << endl;
        cout << "==============================" << endl;
        cout << "=       CONGRATULATIONS      =" << endl;
        cout << "==============================" << endl;
        cout << "\n\n\n\n\n\n\n\n" << endl;
    }
    return true;
}