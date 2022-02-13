
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "asciiArt.cpp"
using namespace std;


typedef enum { defend, quack, peck} attack_type;

int DUCK_HEALTH = 20;
int CHICKEN_HEALTH = 20;
int DUCK_ATTACK = 4;
int CHICKEN_ATTACK = 4;
double ARMOUR_REDUCTION = (1-0.5);
int ARMOUR_GAIN = 1;

class Unit{
    public:
        int health;
        int armour;
        int attackDamage;
        int ammoCount;

        void attacked(int attackAmount){
			//cout << "Duck attacked() called"; // but what if this attack is being called on chicken
            if(armour>0){ // ok
                health -= (double)attackAmount * ARMOUR_REDUCTION; // not sure if (double) was necessory
                armour--;
            }
            else{
                health -= attackAmount;
            }
        }
        int getAmmoCount() const {return ammoCount;}
        bool hasArmour() const {return (armour>0);}
        int getAttack() const {return attackDamage;}
        int getHealth() const {return health;}
};

class Duck : public Unit {
    public:
        Duck(){
            health = DUCK_HEALTH;
            attackDamage = DUCK_ATTACK;
            armour = 0;
            ammoCount = 1;
        }
        // Description: all turn types, first parameter is the type of attack, either peck, defend or quack,
        // second parameter is the chicken you are attacking
        Duck * attack(attack_type type, Unit& other){
            switch(type){
                case peck:
                    if (ammoCount>0){
                        other.attacked(attackDamage);
                        ammoCount--;
                        printDuckPeck();
                    }
                    break;
                case defend:
                    armour += ARMOUR_GAIN;
                    printDuckDefend();
                    break;
                case quack:
                    ammoCount++;
                    printDuckQuack();
                    break;
                /*
                case lay:

                */
           }
		return nullptr;
        }
};

class Chicken : public Unit{
    public:
       // int health; // should we remove this?
        // int attack;
        Chicken(){
            health = CHICKEN_HEALTH;
            attackDamage = CHICKEN_ATTACK;
            armour = 0;
            ammoCount = 1;
        }

        void attack(Duck*& ducks, int numberOfDucks){
            if(numberOfDucks>0){
                int attackType;
                int leastHealthDuck = 0;
                int leastHealth = CHICKEN_HEALTH;
                int attackingPower = 0;
                int targetDuck = 0;

                for(int i = 0; i < numberOfDucks; i++){
                    int trueHealth = ducks[i].getHealth() + ducks[i].armour * ARMOUR_REDUCTION;
                    if(trueHealth <= leastHealth){
                        leastHealth = trueHealth;
                        leastHealthDuck = i;
                    }
                    attackingPower += ducks[i].getAttack();
                }

                if(ammoCount>0 && leastHealth <= attackDamage){
                    attackType = peck;
                    targetDuck = leastHealthDuck;
                }

                else if(armour>=3){
                    attackType = rand() % 2 + 1;
                    if(ammoCount < 1){
                        attackType = quack;
                    }
                    if(ammoCount >= 3)
                        attackType = peck;
                }

                else if(ammoCount >=3){
                    if((rand()%2)==1)
                        attackType = defend;
                    else
                        attackType = peck;
                }

                else{
                    attackType = rand() % 6;
                    if(ammoCount < 1){
                        attackType %= 2;
                    }
                    else{
                        attackType %= 3;
                        }
                    }
                if (attackType == defend){
                    armour += ARMOUR_GAIN;
                    printChickenDefend();
                }
                else if (attackType == quack){
                    ammoCount++;
                    printChickenCoot();
                    }
                else{
                    ducks[targetDuck].attacked(attackDamage);
                    ammoCount--;
                    printChickenPeck();
                }
            }
        }
        int getHealth(){return health;}
        bool canPeck(){return ammoCount>0;}
};

void printInfo(Duck& duck, Chicken& chicken){ // We can also print Info with the ascii board
    int maxDuckHealth = DUCK_HEALTH;
    int maxChickHealth = CHICKEN_HEALTH;
    int duckHealth = duck.health;
    int chickHealth = chicken.health;
    int duckArmour = duck.armour;
    int chickArmour = chicken.armour;
    int duckAmmo = duck.ammoCount;
    int chickAmmo = chicken.ammoCount;
    cout << "[";
    for(int i = 0; i < duckHealth; i+=4){
        cout << "|";
    }
    for(int i = 0; i < maxDuckHealth - duckHealth; i+=4){
        cout << " ";
    }
    cout << "]   Ø : " << duckArmour << " >--|> : " << duckAmmo;
    cout << "                   [";
    for(int i = 0; i < chickHealth; i+=4){
        cout << "|";
    }
    for(int i = 0; i < maxChickHealth - chickHealth; i+=4){
        cout << " ";
    }

    cout << "]   Ø : " << chickArmour << " >--|> : " << chickAmmo << endl;
}

void printWelcomePage(){
    cout << "Welcome to <PECK TO DEATH>!\n\n";
    cout << "We need your help to crush the chickens. The chickens have been our enemies for the longest time.\n";
    cout << "\"wHat cAmE fiRsT, tHe cHiCken oR tHe eGG?\" I'll tell you, IT WAS DUCKS! DUCKS CAME FIRST!\n";
    cout << "How dare they copy our whole vibe.\n";
    cout << "Us ducks didn't care at first. You see, we aren't the type to get jealous. We have it so much better.\n";
    cout << "We can fly better, go on water, we're prettier, and best of all we have the superior eggs!\n";
    cout << "The problems started when the chickens claimed they had tastier eggs than us?!?!\n";
    cout << "This was definetly not true, and they knew it. So what did they do? Start attacking us and trying to KILL US!\n";
    cout << "That's why we called you. We need to you to go undercover and duck up the chickens! Below we'll teach you how to do it.\n\n";
}

void printInstructions(){
    string ready = "start";

    cout << "In order to ruin the chickens you're going to battle them.\n";
    cout << "Both you and the chicken have 20 HP to start. Taking a peck from the enemy will decrease it by 4 HP, but if you have armour it will only decrease by 2 HP.\n";
    cout << "In order to peck, you must have quacked before. Quacking will give you the power to peck. In turn, the chicken will coot to peck.\n";
    cout << "To take less damage from an enemies peck, defend youself!\n";
    cout << "Have fun and please, show these chicken who the real birds are!\n";
    cout << "Below are the controls,\n\n";

    cout << "Use the [1], [2], [3] keys on your keyboard to control your duck.\n";
    cout << "[1] - Use this key to Peck! A peck will bring down the health of the chicken as long as it's not defending.\n";
    cout << "[2] - Use this key to Quack! A quack will give you the ability to peck. Think of it as reloading. If you want, you can quack multiple times and save your pecks.\n";
    cout << "[3] - Use this key to Defend! A defend will give you 2 armour's which will reduce the chicken's peck by 50% each.\n\n";
    cout << "The Ø symbolizes how much armour you have and the >--|> symbolizes your ammo.\n";

    while (ready != "ready"){
        if(ready != "start") cout << "\nCome on! You got this! Now ready up!"; // WHY? this is if the person doesnt input ready. its just a way to start the game
        cout << "\nType and enter ready, to start : ";                       //it gives the user more control so the games doesnt just start
        cin >> ready;
    }
    cout << "\n Okay, LET'S DUCK THEM UP!\n\n";
}

void duckTurn(Duck*& ducks, Chicken& chicken){
    int playerMove = 0;

    while (playerMove > 3 || playerMove < 1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
        }
         cout << "It's your turn! Enter [1], [2], or [3] to make a move";
        if (ducks[0].getAmmoCount() < 1){
            while(playerMove > 3 || playerMove <= 1){
                if(cin.fail()){
                     cin.clear();
                     cin.ignore(10000, '\n');
                }
                cout << "\nYou have no ammo so you must quack[2] or defend[3] :";
                cin >> playerMove;
            }
        }
        else{
            cout << " : ";
            cin >> playerMove;
        }
    }
    cin.ignore(10000, '\n');
    cout << endl << endl;
    if (playerMove == 1){
         ducks[0].attack(peck, chicken);
        cout << endl;
    }
    if (playerMove == 2){
        ducks[0].attack(quack, chicken);
        cout << endl;
    }
    if (playerMove == 3){
        ducks[0].attack(defend, chicken);
        cout << endl;
    }
}

void chickenTurn(Duck*& ducks, Chicken& chicken, int& numDucks){
    cout << "It is now the chicken's turn!\n";
    chicken.attack(ducks, numDucks);
    cout << endl;
}


void printGameOver(){
    cout << "\nThank you for playing! Until next time!\n";
    cout << "and always remember... DUCKS ARE BETTER THAN CHICKENS!";
}

/*void removeDeadDuck(Duck*& ducks, int& numDucks){
    for (int i = 0; i < numDucks; i++){
        if (ducks[i].getHealth() <= 0){
            Duck* d = new Duck[numDucks - 1];

            for(int j, k = 0; j < numDucks - 1 && k < numDucks; j++, k++){
                if (j != i)d[j] = ducks[k]; // I am tying again
                if (j == i) j--;        //i see let me think
            }

            delete[] ducks;
            ducks = d;
            numDucks--;
            cout << "\nOH NO! A duck has died :(\n";
            return;
        }
    }
}*/

void checkForDeadAnimal(Duck*& ducks, Chicken& chicken, int& numDucks, int& i){
    if(ducks[0].getHealth() <= 0){
        numDucks--;
        cout << "\nOH NO! A duck has died :(\n";
        i = -1;
    }
    if(chicken.getHealth() <= 0){
        cout << "\nThe Chicken has been killed!!\n";
        i = -1;
    }

}

void gameplay(Duck*& ducks, Chicken& chicken, int& numDucks){

    string filler;
    int i = 0;
    while (numDucks > 0 && chicken.getHealth() > 0 && i >= 0){
        printFeild(0, numDucks, 1, 0);
        printInfo(ducks[0], chicken);
        if(i % 2 == 0) duckTurn(ducks, chicken);
        else chickenTurn(ducks, chicken, numDucks);
        cout << "\nEnter any character to continue : ";
        cin >> filler;
        i++;
        checkForDeadAnimal(ducks, chicken, numDucks, i);
    }
}


int main(){
    srand(time(0));
    int numDucks = 1;
    char playAgain = 'y';

    printWelcomePage();
    printInstructions();
    while (playAgain == 'y'){
		Duck* d = new Duck[numDucks];
    	Chicken chicken;
		gameplay(d, chicken, numDucks);
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;

		delete[] d;
    }
    printGameOver();
}
