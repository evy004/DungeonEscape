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
#ifndef ROOMSPACE_H
#define ROOMSPACE_H

using namespace std;

class RoomSpace
{   
    //declare variables in a private scope
    private:
        bool isRoom; //checks whether the space is marked as a room
        bool hasKey; //checks whether the room has a key
        bool hasNPC; //checks whether the room has an NPC
        int cleared_rooms; //checks the number of rooms cleared by the player

    //declare variables in public scope
    public:

        //default constructor
        RoomSpace();
        
        //checks to see if currently in room
        bool getIsRoom();

        //declares in room
        void setIsRoom(bool isRoom);

        //checks to see if the user currently has a key
        bool getHasKey();

        //sets the user to having a key
        void setHasKey(bool hasKey);

        //checks to see if the current room has an NPC
        bool getHasNPC();

        //sets the room to having an NPC
        void setHasNPC(bool hasNPC);

        //returns the number of cleared rooms as an integer
        int getClearedRooms();

        //set number of cleared rooms
        void setClearedRooms(int cleared_rooms);

        //open door
        void openDoor(Player team[], int &num_keys, int &num_cleared_rooms);

};


#endif
