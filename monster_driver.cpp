#include <iostream>
#include <fstream>
#include <vector>
#include "monster.h"

using namespace std;

int main()
{
    // Tests default constructor
    Monster monster;

    cout << "Monster name: " << monster.getMonsterName() << endl;
    cout << "Monster diff: " << monster.getMonsterDiff() << endl;
}