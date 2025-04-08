//CSCI1300 Spring 2023
//Author: Evy Ng
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "monster.h"
#include "dungeon.h"
#include "game.h"
using namespace std;

//sets current default space conditions
RoomSpace::RoomSpace()
{
    isRoom = false;
    hasKey = false;
    hasNPC = false;
    cleared_rooms = 0;
}

//checks to see if user is currently in a room
bool RoomSpace::getIsRoom()
{
    return isRoom;
}

//if currently in a room, set it to be as such
void RoomSpace::setIsRoom(bool isRoom)
{
    isRoom = true;
}

//checks to see whether the current room has a key
bool RoomSpace::getHasKey()
{
    return hasKey;
}

//set the room to having a key
void RoomSpace::setHasKey(bool hasKey)
{
    hasKey = true;
}

//checks to see if the room currently has an NPC
bool RoomSpace::getHasNPC()
{
    return hasNPC;
}

//sets the room to having an NPC
void RoomSpace::setHasNPC(bool hasNPC)
{
    hasNPC = true;
}

//checks the number of cleared rooms
int RoomSpace::getClearedRooms()
{
    return cleared_rooms;
}

//sets the number of cleared rooms
void RoomSpace::setClearedRooms(int new_clear)
{
    cleared_rooms = new_clear;
}

//open door
void RoomSpace::openDoor(Player team[], int &num_keys, int &num_cleared_rooms)
{
    //declare and initialize any needed variables
    char player_choice;
    int rand_num = 0;
    Game game;
    Monster monster;
    Dungeon dungeon;
    int num_weapons = team[0].getWeaponCount();
    int num_armor_sets = team[0].getArmorCount();
    vector<Monster> monster_list = monster.monsterList(monster);
    vector<int> weapons = team[0].getWeapon();

    //initialize a random seed generator
    srand(time(NULL));

    //check to see if the player is able to open the door
    if (num_keys > 0)
    {
        cout << "Would you like to enter the Dungeon? It will cost you 1 key. (y/n)" << endl;
        cin >> player_choice;

        if (player_choice == 'y')
        {
            //subtract 1 key from the current key count
            num_keys -= 1;

            //output fight prompt
            cout << "\n\n\n\n\n\n\n\n" << endl;
            cout << "==============================" << endl;
            cout << "=        MONSTER FIGHT       =" << endl;
            cout << "==============================" << endl;
            cout << "\n\n\n" << endl;

            //randomly select a monster that is 2 levels higher than the current amount of cleared rooms
            Monster rand_monster = dungeon.getRandomMonster(num_cleared_rooms, monster_list);

            cout << "You have chosen to pick a fight with " << rand_monster.getMonsterName() << "!" << endl;

            rand_monster.battleOutcome(num_weapons, num_armor_sets, team, team[0], weapons);

            /*
             * CODE HERE, MOVE THE RESULTS IF NEEDED
            */

            //if party successfully defeats the monster there is a 60% chance of misfortune occurring
            if (dungeon.isMonsterDefeated(monster, monster_list) == true)
            {
                rand_num = rand() % 100;

                //checks to see if a misfortune will occur under the 60%
                if (rand_num < 60)
                {
                    game.misfortune(team, 1);
                }

                //increase the number of rooms cleared
                num_cleared_rooms++;
            }

            //if party failed in defeating the monster
            if (dungeon.isMonsterDefeated(monster, monster_list) == false)
            {
                rand_num = rand() % 100;

                //40% chance of a misfortune occurring
                if (rand_num < 40)
                {
                    game.misfortune(team, 1);
                }
            }
        }
        else if (player_choice == 'n')
        {
            //output farewell message
            cout << "\nWe'll see you again shortly." << endl;
        }
        else
        {
            //input validation
            cout << "Sorry, that's an invalid option." << endl;
        }
    }
}

