#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Player {
    public:
        string name = "Player";
        int gold = 0,
        silver = 0,
        copper = 10,
        health = 100,
        attack = 10,  
        defense = 5,
        luck = 1;

        string stats() {
            return "Your stats are:\nName: " + name + 
            "\nHealth: " + to_string(health) + 
            "\nAttack: " + to_string(attack) + 
            "\nDefense: " + to_string(defense) +
            "\nLuck: " + to_string(luck) + 
            "\n" + printmoney();

        }

        

        string printmoney() {
            moneyconversion();
            return "Money: " + to_string(gold) + " gold, " + to_string(silver) + " silver, " + to_string(copper) + " copper.";
        }

        int moneyconversion() {
            while (copper >= 100) {
                silver += 1;
                copper -= 100;
            }
            while (silver >= 100) {
                gold += 1;
                silver -= 100;
            }
            return gold, silver, copper;
        }

        int checkmoney(int cost) {
            moneyconversion();
            if (cost <= gold*10000 + silver*100 + copper) {
                return 1;
            }
            return 0;
        }

        int buyitem(int cost) {
            if (checkmoney(cost) == 1) {
                int tempMoney = gold*10000 + silver*100 + copper - cost;
                gold = 0;
                silver = 0;
                copper = tempMoney;
                moneyconversion();
                return 1;
            }
            return 0;
        }

};
class Enemy {
    public:
        unordered_map<string, int> zombie = {
            {"Health", 5},
            {"Attack", 1},
            {"Defense", 1},
        };

};
//{[name],[cost],[damage],[defense],[healthgen]]}
class Potion {
    public: 
        Player* player; 
        int Health_Potion[4] = {0,0,0,0};
        int Mana_Potion[4] = {0,0,0,0};
        int Strength_Potion[4] = {0,0,0,0};
        int Defense_Potion[4] = {0,0,0,0};
        int Speed_Potion[4] = {0,0,0,0};
        int Luck_Potion[4] = {0,0,0,0};

        int list_items() {
            cout << "Health Potion: \nCost: " << Health_Potion[0] << "\nDamage: " << Health_Potion[1] << "\nDefense: " << Health_Potion[2] << "\nHealth Gen: " << Health_Potion[3] << "\n";
            cout << "Mana Potion: \nCost: " << Mana_Potion[0] << "\nDamage: " << Mana_Potion[1] << "\nDefense: " << Mana_Potion[2] << "\nHealth Gen: " << Mana_Potion[3] << "\n";
            cout << "Strength Potion: \nCost: " << Strength_Potion[0] << "\nDamage: " << Strength_Potion[1] << "\nDefense: " << Strength_Potion[2] << "\nHealth Gen: " << Strength_Potion[3] << "\n";
            cout << "Defense Potion: \nCost: " << Defense_Potion[0] << "\nDamage: " << Defense_Potion[1] << "\nDefense: " << Defense_Potion[2] << "\nHealth Gen: " << Defense_Potion[3] << "\n";
            cout << "Speed Potion: \nCost: " << Speed_Potion[0] << "\nDamage: " << Speed_Potion[1] << "\nDefense: " << Speed_Potion[2] << "\nHealth Gen: " << Speed_Potion[3] << "\n";
            cout << "Luck Potion: \nCost: " << Luck_Potion[0] << "\nDamage: " << Luck_Potion[1] << "\nDefense: " << Luck_Potion[2] << "\nHealth Gen: " << Luck_Potion[3] << "\n";
            return 0;
        }

        int buy_item(int choice){
            if (choice == 1) {
                if (player->checkmoney(Health_Potion[0]) == 1) {
                    player->health += Health_Potion[3];
                    player->buyitem(Health_Potion[0]);
                    cout << "You bought a Health Potion!\n";
                }
                else {
                    cout << "You don't have enough money to buy this item.\n";
                }
            }
            return 0;
        };
};

class Weapon {
    public:
        int Sword[4] = {0,0,0,0};
        int Axe[4] = {0,0,0,0};
        int Bow[4] = {0,0,0,0};
        int Dagger[4] = {0,0,0,0};
        int Staff[4] = {0,0,0,0};
        int Mace[4] = {0,0,0,0};
    
        int list_items() {
            cout << "Sword: \nCost: " << Sword[0] << "\nDamage: " << Sword[1] << "\nDefense: " << Sword[2] << "\nHealth Gen: " << Sword[3] << "\n";
            cout << "Axe: \nCost: " << Axe[0] << "\nDamage: " << Axe[1] << "\nDefense: " << Axe[2] << "\nHealth Gen: " << Axe[3] << "\n";
            cout << "Bow: \nCost: " << Bow[0] << "\nDamage: " << Bow[1] << "\nDefense: " << Bow[2] << "\nHealth Gen: " << Bow[3] << "\n";
            cout << "Dagger: \nCost: " << Dagger[0] << "\nDamage: " << Dagger[1] << "\nDefense: " << Dagger[2] << "\nHealth Gen: " << Dagger[3] << "\n";
            cout << "Staff: \nCost: " << Staff[0] << "\nDamage: " << Staff[1] << "\nDefense: " << Staff[2] << "\nHealth Gen: " << Staff[3] << "\n";
            cout << "Mace: \nCost: " << Mace[0] << "\nDamage: " << Mace[1] << "\nDefense: " << Mace[2] << "\nHealth Gen: " << Mace[3] << "\n";
            return 0;
        }
};

class armour {
    public:
        int Helmet[4] = {0,0,0,0};
        int Chestplate[4] = {0,0,0,0};
        int Leggings[4] = {0,0,0,0};
        int Boots[4] = {0,0,0,0};
        int Shield[4] = {0,0,0,0};
        int Cloak[4] = {0,0,0,0};

        int list_items() {
            cout << "Helmet: \nCost: " << Helmet[0] << "\nDamage: " << Helmet[1] << "\nDefense: " << Helmet[2] << "\nHealth Gen: " << Helmet[3] << "\n";
            cout << "Chestplate: \nCost: " << Chestplate[0] << "\nDamage: " << Chestplate[1] << "\nDefense: " << Chestplate[2] << "\nHealth Gen: " << Chestplate[3] << "\n";
            cout << "Leggings: \nCost: " << Leggings[0] << "\nDamage: " << Leggings[1] << "\nDefense: " << Leggings[2] << "\nHealth Gen: " << Leggings[3] << "\n";
            cout << "Boots: \nCost: " << Boots[0] << "\nDamage: " << Boots[1] << "\nDefense: " << Boots[2] << "\nHealth Gen: " << Boots[3] << "\n";
            cout << "Shield: \nCost: " << Shield[0] << "\nDamage: " << Shield[1] << "\nDefense: " << Shield[2] << "\nHealth Gen: " << Shield[3] << "\n";
            cout << "Cloak: \nCost: " << Cloak[0] << "\nDamage: " << Cloak[1] << "\nDefense: " << Cloak[2] << "\nHealth Gen: " << Cloak[3] << "\n";
            return 0;
        }
};

class Accessories {
    public:
        int Ring[4] = {0,0,0,0};
        int Necklace[4] = {0,0,0,0};
        int Bracelet[4] = {0,0,0,0};
        int Amulet[4] = {0,0,0,0};
        int Earring[4] = {0,0,0,0};
        int Belt[4] = {0,0,0,0};

        int list_items() {
            cout << "Ring: \nCost: " << Ring[0] << "\nDamage: " << Ring[1] << "\nDefense: " << Ring[2] << "\nHealth Gen: " << Ring[3] << "\n";
            cout << "Necklace: \nCost: " << Necklace[0] << "\nDamage: " << Necklace[1] << "\nDefense: " << Necklace[2] << "\nHealth Gen: " << Necklace[3] << "\n";
            cout << "Bracelet: \nCost: " << Bracelet[0] << "\nDamage: " << Bracelet[1] << "\nDefense: " << Bracelet[2] << "\nHealth Gen: " << Bracelet[3] << "\n";
            cout << "Amulet: \nCost: " << Amulet[0] << "\nDamage: " << Amulet[1] << "\nDefense: " << Amulet[2] << "\nHealth Gen: " << Amulet[3] << "\n";
            cout << "Earring: \nCost: " << Earring[0] << "\nDamage: " << Earring[1] << "\nDefense: " << Earring[2] << "\nHealth Gen: " << Earring[3] << "\n";
            cout << "Belt: \nCost: " << Belt[0] << "\nDamage: " << Belt[1] << "\nDefense: " << Belt[2] << "\nHealth Gen: " << Belt[3] << "\n";
            return 0;
        }
};

int store() {
    cout << "Welcome to the store! What part of the store would you like to go to?\n";
    cout << 
    "1. Potions\
    2. Weapons\
    3. Armour\
    4. Accessories\
    6. Exit Store\n";
    int choice;
    cin >> choice;
    

    if (choice == 1) {
        cout << "Welcome to the potion store! What potion would you like to buy?\n";
        Potion potions;
        potions.list_items();
    }
    else if (choice == 2) {
        cout << "Welcome to the weapon store! What weapon would you like to buy?\n";
        Weapon weapons;
        weapons.list_items();
    }
    else if (choice == 3) {
        cout << "Welcome to the armour store! What piece of armour would you like to buy?\n";
        armour armours;
        armours.list_items();
    }
    else if (choice == 4) {
        cout << "Welcome to the accessories store! What accessory would you like to buy?\n";
        Accessories accessories;
        accessories.list_items();
    }
    return 0;
}

int main() {
    cout << __cplusplus << "\n" << _MSVC_LANG << "\n";
    Player* player = new Player();
    cout << "Welcome to T.B.A.G. C++!! We welcome you player.\n";
    cout << "What is your name player?\n";
    cin >> player->name;
    cout << "Welcome, " << player->name << ", to T.B.A.G. C++!!\n";
    cout << player->stats() << endl;




    delete player;
    return 0;
}