//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "dungeon.h"
#include "game.h"
#include "Map.h"
#include "menu.h"
#include "monster.h"
#include "npc.h"
#include "Player.h"
#include "roomSpace.h"

using namespace std;

int main()
{
    //create objects for object creation
    Game game;
    Map map;
    NPC merchant;
    Player player;
    Player member1;
    Player member2;
    Player member3;
    Player member4;
    Player team[5];

    //declare and initialize any needed variables
    string input = "";
    string name;
    string comp[5];
    string begin_game = "";

    //start title
    cout << "\n\n\n\n\n" << endl;
    cout << "===========================" << endl;
    cout << "||     DUNGEON ESCAPE     ||" << endl;
    cout << "===========================" << endl;
    cout << "\n" << endl;

    //while loop to check for valid input
    while (begin_game != "1" && begin_game != "2")
    {
        //output starting options
        cout << "Press 1 to begin your journey." << endl;
        cout << "Press 2 to quit the game." << endl;

        getline(cin, begin_game);

        //check for valid input
        if (begin_game != "1" && begin_game != "2")
        {
            cout << "Invalid option. Please select 1 or 2." << endl;
        }
    }

    //check for options
    if(begin_game == "2")
    {
        //output goodbye message
        cout << "\nFarewell! We hope you will join us in future conquests." << endl;

        //end game
        game.end(2);

        //reset the map
        map.resetMap();
    }
    else if (begin_game == "1")
    {
        //start game
        game.start();
    
        //prompt user for the name of the player they'll be playing with
        cout << "Welcome! Please enter your name below: " << endl;
        cin >> name;

        //set name to player object
        player.setPlayerName(name);
        
        //prompt user for their team
        cout << "\nWho are you traveling with?" << endl;

        //iterate for the 4 team members
        for (int i = 0; i < 4; i++)
        {
            //prompt for names
            cout << "Enter the name of team member " << i + 1 << ":" << endl;
            cin >> name;
            cout << "\n";

            //add each member into the team
            comp[i] = name;
        }

        //set it to player object
        game.setPlayerTeam(comp);

        //set the names of the members within the team
        member1.setPlayerName(comp[0]);
        member2.setPlayerName(comp[1]);
        member3.setPlayerName(comp[2]);
        member4.setPlayerName(comp[3]);

        //append new members to team
        team[0] = player;
        team[1] = member1;
        team[2] = member2;
        team[3] = member3;
        team[4] = member4;

        //time to visit the merchant!
        merchant.openMerchantMenu(0, player);
        
        //plant random number generator
        srand(time(NULL));

        //run player option menu
        Menu menu(team);

        menu.playerMenu();
        return 0;
    }
}