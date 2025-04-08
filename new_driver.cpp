#include <iostream>
#include <vector>
#include <fstream>
#include "Player.h"
#include "dungeon.h"
#include "monster.h"
#include "npc.h"
#include "game.h"
#include "roomSpace.h"

using namespace std;

int main()
{
    // Testing for the dungeon class
    // int num_rooms_cleared;
    // Dungeon dungeon;
    // Monster defeated_monster;
    // Monster encountered_monster;
    // Monster monster;
    // Player player;

    // Dungeon();
    // Dungeon("monsters.txt");
    // dungeon.getMonsterList(); // Works!
    // dungeon.getRandomMonster(num_rooms_cleared);
    // dungeon.defeatMonster(defeated_monster); // Works!
    // cout << dungeon.isMonsterDefeated(monster) << endl; // works!
    // dungeon.handleBattle(player, dungeon, encountered_monster); // Works!
    // dungeon.playerTurn(player, dungeon); // Works!

    // Testing for the monster class
    string name_ = "Baxter";
    int difficulty_ = 50;
    int monster_diff = 70;
    int num_weapons = 5;
    int weapon_bonus = 5;
    int num_armor_sets = 3;
    bool win = true;
    Monster defeated_monster;
    Monster encountered_monster;
    bool party_surrender = true;
    int num_party_members = 5;
    Player team[5];
    Player player;
    int weapons[5];
    NPC npc;
    Game game;
    RoomSpace roomspace;

    Monster monster(name_, difficulty_); // Works!
    cout << "Monster name: " << monster.getMonsterName() << endl; // Works!
    cout << "Monster diff: " << monster.getMonsterDiff() << endl; // Works!
    monster.setMonsterDiff(monster_diff);
    cout << "Win?? " << monster.battleOutcome(num_weapons, num_armor_sets, team, player, weapons, npc, roomspace, game) << endl;
    monster.printBattleOutcome(win, defeated_monster); // Works!
    monster.printEncounterMessage(encountered_monster); // Works!
    monster.playGame(); // Works!
    cout << "Party members: " << monster.partySurrender(party_surrender, team, num_party_members, game) << endl; // Works!

    return 0;
}


// cout << "Testing for dungeon header:" << endl;
    // Dungeon();

    // string filename;
    // cout << "Enter a file" << endl;
    // ifstream in_file(filename);

    // string copy;
    // vector<string> monsters;

    // while (getline(in_file, copy))
    // {
    //     vector<string> result = split(copy, ",");
    //     monsters.push_back(result.at(0));
    // }

    // int rooms_cleared;
    // cout << "How many rooms are cleared?" << endl;
    // cin >> rooms_cleared;

    // Dungeon monster;
    // Monster defeated_monster;
    // Monster monster_parameter;

    // monster.getMonsterList();
    // monster.getRandomMonster(rooms_cleared);
    // monster.defeatMonster(defeated_monster);
    // monster.isMonsterDefeated(monster_parameter);

    // char in;
    // bool move;
    // cout << "Move on? (Y/N)" << endl;
    // cin >> in;

    // if (in == 'y')
    // {
    //     move = true;
    // }
    // else
    // {
    //     move = false;
    // }

    // if (move == true)
    // {
    //     cout << "Testing for game.h" << endl;
        
    //     Game();
    //     Game game;
        
    //     game.main_menu();
    //     game.merchant_menu();
    //     game.action_menu();
    //     game.start();
    //     game.final_boss();

    //     move = false;
    // }
    // else
    // {
    //     return 0;
    // }

    // char in1;
    // cout << "Move on? (Y/N)" << endl;
    // cin >> in1;

    // if (in1 == 'y')
    // {
    //     move = true;
    // }
    // else
    // {
    //     move = false;
    // }

    // if (move == true)
    // {
    //     cout << "Testing for menu.h" << endl;

    //     Menu menu;
    //     int options;

    //     Menu();
    //     Menu(options);

    //     move = false;
    // }
    // else
    // {
    //     return 0;
    // }

    // char in2;
    // cout << "Move on? (Y/N)" << endl;
    // cin >> in2;

    // if (in2 == 'y')
    // {
    //     move = true;
    // }
    // else
    // {
    //     move = false;
    // }

    // if (move == true)
    // {
    //     cout << "Testing for monster.h" << endl;

    //     Monster();

    //     string name;
    //     int difficulty;

    //     cout << "Enter name" << endl;
    //     cin >> name;

    //     cout << "Enter difficulty" << endl;
    //     cin >> difficulty;

    //     Monster(name, difficulty);

    //     Monster monster;

    //     monster.getRating();
    //     monster.getName();

    //     int num_weapons;
    //     int weapon_bonus;
    //     int num_armor_sets;
    //     int difficulty;

    //     Monster defeated_monster;
    //     Monster encountered_monster;
    //     bool win;

    //     Player player;
    //     Dungeon dungeon;
    //     Monster encountered_monster;

    //     int num_party_members;

    //     monster.battleOutcome(num_weapons, weapon_bonus, num_armor_sets, difficulty);
    //     monster.printBattleOutcome(win, defeated_monster);
    //     monster.printEncounterMessage(encountered_monster);
    //     monster.handleBattle(player, dungeon, encountered_monster);
    //     monster.playerTurn(player, dungeon);
    //     monster.playGame();
    //     monster.partySurrender(num_party_members);

    //     move = false;
    // }
    // else
    // {
    //     return 0;
    // }

    // char in3;
    // cout << "Move on? (Y/N)" << endl;
    // cin >> in3;

    // if (in3 == 'y')
    // {
    //     move = true;
    // }
    // else
    // {
    //     move = false;
    // }

    // if (move == true)
    // {
    //     cout << "Testing for roomSpace.h" << endl;

    //     RoomSpace();

    //     RoomSpace roomspace;

    //     bool room = true;
    //     bool npc = true;
    //     int num_rooms;

    //     roomspace.getIsRoom();
    //     roomspace.setIsRoom(true);
    //     roomspace.getHasKey();
    //     roomspace.getHasNPC();
    //     roomspace.setHasNPC(true);
    //     roomspace.getClearedRooms();
    //     roomspace.setClearedRooms(100);

    //     move = false;
    // }
    // else
    // {
    //     return 0;
    // }

    // char in4;
    // cout << "Move on? (Y/N)" << endl;
    // cin >> in4;

    // if (in4 == 'y')
    // {
    //     move = true;
    // }
    // else
    // {
    //     move = false;
    // }

    // if (move == true)
    // {
    //     cout << "Testing for NPC.h" << endl;

    //     NPC();

    //     NPC npc;

    //     string name_;
    //     int steps_;
    //     bool hasNPC = true;
    //     bool displace = true;
    //     bool solve = true;
    //     int cleared_rooms;
    //     bool hostile = true;

    //     cout << "Please enter name:" << endl;
    //     cin >> name_;

    //     cout << "Please enter steps:" << endl;
    //     cin >> steps_;

    //     NPC(name_, steps_);

    //     npc.revealNPCSpace(hasNPC);
    //     npc.moveParty(displace);
    //     npc.decreaseFullness(displace);
    //     npc.solveRiddle(solve);
    //     npc.adjustPrices(cleared_rooms);
    //     npc.summonMonster(hostile);
    //     npc.speakNPC(cleared_rooms);
    //     npc.giveUp();

    //     move = false;
    // }
    // else
    // {
    //     return 0;
    // }

    // char in5;
    // cout << "Move on? (Y/N)" << endl;
    // cin >> in5;

    // if (in5 == 'y')
    // {
    //     move = true;
    // }
    // else
    // {
    //     move = false;
    // }

    // if (move == true)
    // {
    //     cout << "Testing for player.h" << endl;

    //     Player player;

    //     Player();

    //     int purchased_armor;
    //     bool gold_bal = true;
    //     int num_ingredients;
    //     string weapon_name;
    //     int upgrade_cost;
    //     bool armor = true;

    //     player.getWeaponStrength();
    //     player.getArmorCount();
    //     player.getInventory();
    //     player.addArmor(purchased_armor);
    //     player.hasWeapon();
    //     player.hasUpgradedWeapon();
    //     player.addGold(gold_bal);
    //     player.addIngredients(num_ingredients);
    //     player.removeIngredients(num_ingredients);
    //     player.addWeapon(weapon_name);
    //     player.upgradeWeapon(weapon_name, upgrade_cost);
    //     player.isAlive();
    //     player.isHungry();
    //     player.decreaseFullness();
    //     player.die();
    //     player.setSlain();
    //     player.isSlain();
    //     player.hasArmor();
    //     player.setArmor(armor);

    //     move = false;
    // }
