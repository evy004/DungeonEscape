//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

//player class
class Player
{
    //declare variables in private scope
    private:
        string name;
        int fullness;
        bool alive;
        bool slain;
        bool has_weapon;
        bool has_upgraded_weapon;
        int weapon_strength;
        int armor_count;
        bool has_armor;
        vector<int> weapons;

        int gold = 100;
        int ingredients = 0;
        int armor = 0;
        int pot = 0;
        int pan = 0;
        int cauldron = 0;
        int stone = 0;
        int iron = 0;
        int rapier = 0;
        int axe = 0;
        int longsword = 0;
        int silver = 0;
        int ruby = 0;
        int emerald = 0;
        int diamond = 0;
        int gem = 0;

    //declare functions in public
    public:


        //default constructor
        Player();

        //get player name
        string getPlayerName();

        //set name of player
        void setPlayerName(string a);

        //get player fullness
        int getFullness();

        //checks the current strength of weapon
        int getWeaponStrength();

        //checks for the current amount of armor
        int getArmorCount();
        
        //gets the number of gold
        int getGold();

        //sets the number of gold
        void setGold(int gold_);

        void changeGold(int gold_);

        //gets the number of ingredients
        int getIngredients();

        //sets the number of ingredients
        void setIngredients(int ingredients_);

        //change number of ingredients
        void changeIngredients(int ingredients_);

        //get the number of cookware
        int getCookware();

        //gets the number of pots
        int getPot();

        //gets the number of pans
        int getPan();

        //gets the number of cauldrons
        int getCauldron();

        //sets the number of pots
        void setPot(int pots_);
    
        //sets the number of pans
        void setPan(int pans_);

        //sets the number of cauldrons
        void setCauldron(int cauldrons_);

        //gets the number of stone clubs
        int getStone();

        //sets the number of stone clubs
        void setStone(int clubs_);

        //gets the number of iron spear
        int getIron();

        //sets the number of spears
        void setIron(int spears_);

        //gets the number of rapiers
        int getRapier();

        //sets the number of rapiers
        void setRapier(int rapiers_);

        //gets the number of axes
        int getAxe();

        //set the number of axes
        void setAxe(int axe_);

        //gets the number of longswords
        int getLongsword();

        //sets the number of longswords
        void setLongsword(int longsword_);

        //gets the number of armor
        int getArmor();

        //sets the number of armor 
        void setArmor(int armor_);

        //gets the number of silver rings
        int getSilver();

        //sets the number of silver rings
        void setSilver(int rings_);

        //gets the number of ruby necklaces
        int getRuby();

        //sets the number of necklaces
        void setRuby(int rubies_);

        //gets the number of emerald braclets
        int getEmerald();

        //sets the number of bracelets
        void setEmerald(int bracelets_);

        //gets the number of diamond circlets
        int getDiamond();

        //sets the number of circlets
        void setDiamond(int circlets_);

        //gets the number of gem-encrusted goblets
        int getGem();

        //sets the number of goblets
        void setGem(int gems_);

        //prints the player's inventory back to user
        void getInventory();

        //adds more armor given that the user purchased more
        void addArmor(int purchased_armor);

        //checks to see if player owns a weapon
        bool hasWeapon();

        //checks to see if player has an upgraded weapon
        bool hasUpgradedWeapon();
        
        //when users obtain more gold, add it to the current amount
        void addGold(int gold_bal);

        //add ingredients to the user's current amount
        void addIngredients(int num_ingredients);

        //removes ingredients from the player's inventory
        void removeIngredients(int num_ingredients);

        //updates weapons vector
        void updateWeapon();

        //get the weapons vector
        vector<int> getWeapon();

        //get the weapons count
        int getWeaponCount();

        //upgrades the player's current weapon based on cost
        bool upgradeWeapon(string weapon_name, int upgrade_cost);

        //checks to see if player is alive
        bool isAlive();

        //check to see if player is hungry
        bool isHungry();

        //lowers the player's hunger amount
        void decreaseFullness();

        //decreases player fullness by a set amount
        void increaseHunger(int hunger);

        //player dies
        void die();

        //player is slain by monster
        bool isSlain();
        void setSlain();

        //checks to see if user currently has armor
        bool hasArmor();

        //gives the player armor
        void setArmor(bool new_hasArmor);

        void setWeapon(bool new_hasWeapon);

        //get player or party members' weapons


        //resurrect the user (extra credit)
        void revive();


        void setGoblets(int gems_);
        
};

#endif