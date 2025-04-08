//CSCI1300 Spring 2023
//Author: Evy Ng, Andrew Rho
//Recitation 107 TA: Tanmay Desai
//Recitation 105 TA: Morgan Byers
//Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

//default constructor
Player::Player()
{
    name = "";
    alive = true;
    fullness = 50;
    armor_count = 0;
    weapon_strength = 0;
}

//get player name
string Player::getPlayerName()
{
    return name;
}

//set player name
void Player::setPlayerName(string a)
{
    name = a;
}

//get player fullness
int Player::getFullness()
{
    return fullness;
}

//get player weapon
//int Player::

//gets the number of gold
int Player::getGold()
{
    return gold;
}

//sets the number of gold
void Player::setGold(int gold_)
{
    gold = gold_;
}

void Player::changeGold(int gold_)
{
    gold += gold_;
}


//gets the number of ingredients
int Player::getIngredients()
{
    return ingredients;
}

//change the number of ingredients
void Player::changeIngredients(int ingredients_)
{
    ingredients += ingredients_;
}

//sets the number of ingredients
void Player::setIngredients(int ingredients_)
{
    ingredients = ingredients_;
}

//gets the number of cookware
int Player::getCookware()
{
    return cauldron + pot + pan;
}

//gets the number of pots
int Player::getPot()
{
    return pot;
}

//gets the number of pans
int Player::getPan()
{
    return pan;
}

//gets the number of cauldrons
int Player::getCauldron()
{
    return cauldron;
}

//sets the number of pots
void Player::setPot(int pots_)
{
    pot += pots_;
}

//sets the number of pans
void Player::setPan(int pans_)
{
    pan += pans_;
}

//sets the number of cauldrons
void Player::setCauldron(int cauldrons_)
{
    cauldron += cauldrons_;
}

//gets the number of stone clubs
int Player::getStone()
{
    return stone;
}

//sets the number of stone clubs
void Player::setStone(int clubs_)
{
    stone = clubs_;
}

//gets the number of iron spear
int Player::getIron()
{
    return iron;
}

//sets the number of spears
void Player::setIron(int spears_)
{
    iron = spears_;
}

//gets the number of rapiers
int Player::getRapier()
{
    return rapier;
}

//sets the number of rapiers
void Player::setRapier(int rapiers_)
{
    rapier = rapiers_;
}

//gets the number of axes
int Player::getAxe()
{
    return axe;
}

//set the number of axes
void Player::setAxe(int axe_)
{
    axe = axe_;
}

//gets the number of longswords
int Player::getLongsword()
{
    return longsword;
}

//sets the number of longswords
void Player::setLongsword(int longsword_)
{
    longsword = longsword_;
}

//gets the number of armor
int Player::getArmor()
{
    return armor;
}

//sets the number of armor 
void Player::setArmor(int armor_)
{
    armor += armor_; 
}

//gets the number of silver rings
int Player::getSilver()
{
    return silver;
}

//sets the number of silver rings
void Player::setSilver(int rings_)
{
    silver = rings_;
}

//gets the number of ruby necklaces
int Player::getRuby()
{
    return ruby;
}

//sets the number of necklaces
void Player::setRuby(int rubies_)
{
    ruby = rubies_;
}

//gets the number of emerald bracelets
int Player::getEmerald()
{
    return emerald;
}

//sets the number of bracelets
void Player::setEmerald(int bracelets_)
{
    emerald = bracelets_;
}

//gets the number of diamond circlets
int Player::getDiamond()
{
    return diamond;
}

//sets the number of circlets
void Player::setDiamond(int circlets_)
{
    diamond = circlets_;
}

//gets the number of gem-encrusted goblets
int Player::getGem()
{
    return gem;
}

//sets the number of goblets
void Player::setGem(int gems_)
{
    gem = gems_;
}

//checks the current strength of weapon
int Player::getWeaponStrength()
{
    return weapon_strength;
}

//checks for the current amount of armor
int Player::getArmorCount()
{
    return armor_count;
}

//prints the player's inventory back to user
void Player::getInventory()
{
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold << endl;
    cout << "| Ingredients | " << ingredients << " kg" << endl;
    cout << "| Cookware    | P: | F: 0 | C: " << endl; //will modify to include objects
    cout << "| Weapons     | C: 0 | S: 0 | R: 2 | B: 0 | L: 0" << endl; //will modify to include objects
    cout << "| Armor       | " << armor_count << endl;
    cout << "| Treasures   | R: 0 | N: 0 | B: 0 | C: 0 | G: 0" << endl; //will modify to include objects
}

//adds more armor given that the user purchased more
void Player::addArmor(int purchased_armor)
{
    armor_count = armor_count + purchased_armor;
}

//checks to see if player owns a weapon
bool Player::hasWeapon()
{
    return has_weapon;
}

//checks to see if player has an upgraded weapon
bool Player::hasUpgradedWeapon()
{
    return has_upgraded_weapon;
}

//when users obtain more gold, add it to the current amount
void Player::addGold(int gold_bal)
{
    gold += gold_bal;
    cout << gold << endl;
}

//add ingredients to the user's current amount
void Player::addIngredients(int num_ingredients)
{
    ingredients += num_ingredients;
    //cout << ingredients << endl;
}

//removes ingredients from the player's inventory
void Player::removeIngredients(int num_ingredients)
{
    ingredients -= num_ingredients;
    //cout << ingredients << endl;
}

// //add weapon into player's inventory
void Player::updateWeapon()
{
    weapons.at(0) = stone;
    weapons.at(1) = iron;
    weapons.at(2) = rapier;
    weapons.at(3) = axe;
    weapons.at(4) = longsword;

}

vector<int> Player::getWeapon()
{
    return weapons;
}

int Player::getWeaponCount()
{
    return stone + iron + rapier + axe + longsword;
}

//checks to see if player is alive
bool Player::isAlive()
{
    return alive;
}

//check to see if player is hungry
bool Player::isHungry()
{
    if (fullness != 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//lowers the player's hunger amount
void Player::decreaseFullness()
{
    fullness -= 1;
}

//decreases player fullness by a set amount
void Player::increaseHunger(int hunger)
{
    fullness -= hunger;
}

//player dies
void Player::die()
{
    alive = false;

    if (fullness == 0)
    {
        cout << "OH NO !! " << name << " has died of hunger! :(" << endl;
    }
}

//to deduce when a member got slain
void Player::setSlain()
{
    //will check based on boss/monster fight
    //if player depleted all health, they have died
    cout << "You died :(" << endl;
}

//player is slain by monster
bool Player::isSlain()
{
    //sets death status
    alive = false;
    return true;
}

//checks to see if user currently has armor
bool Player::hasArmor()
{
    if (armor_count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//gives the player armor
void Player::setArmor(bool new_hasArmor)
{
    has_armor = new_hasArmor;
}

//resurrect the user (extra credit)
void Player::revive()
{
    //will implement a specific challenge or requirement in order to revive character
    alive = true;
}