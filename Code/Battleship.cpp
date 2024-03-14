#include <iostream>
#include <ctime>
using namespace std;

//Main Function
int main() {
    int x = 0, y = 0;
    //Randomize based on time
    srand(time(NULL));
    //Randomize the amount of ships
    int amount = 1 + (rand() % 6);
    int amount2 = amount;
    int chance = 0;
    //Create a 4x4 grid
    bool Grid[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    //Go across all points on the grid continuosly until all ships are placed
    while (x == y) {
        for (int rows = 0; rows < 4; rows++) {
            for (int cols = 0; cols < 4; cols++) {
                //If spot is empty, continue
                if (Grid[rows][cols] == 0) {
                    //Decide if a ship will be placed and lower ship count if one is placed
                    chance = 1 + (rand() % 100);
                    if (chance > 85) {
                        Grid[rows][cols] = 1;
                        amount2--;
                        cout << "Set ship\n";
                    }
                }
                //Exit loop when ships are done being placed
                if (amount2 == 0) {
                    goto Game;
                }
            }
        }
    }
    //Come here when done setting ships
    Game:
    //Announce the amount of ships
    if (amount == 1) {
        cout << "There is 1 battleship\n";
    }
    else {
        cout << "There are " << amount << " battleships\n";
    }
    //Ask user for input
    for (int i = amount + 3; i >= 0; i--) {
        cout << "Please select your grid square x value (4x4): ";
        cin >> x;
        cout << "Please select your grid square y value (4x4): ";
        cin >> y;
        //If a ship is where the user specified, get rid of the ship and lower ship count
        if (Grid[y-1][x-1] == 1) {
            cout << "You sank my battleship\n";
            Grid[y-1][x-1] = 0;
            amount--;
            if (amount > 1) {
                cout << "There are " << amount << " ships remaining\n";
            }
            else if (amount == 1) {
                cout << "There is 1 ship remaining\n";
            }
        }
        //Announce when the user misses and how many shots they have
        else if (i > 1) {
            cout << "You missed! You have " << i << " shots left\n";
        }
        else {
            cout << "You missed! You have 1 shot left\n";
        }
        //When ship count is zero, end the game
        if (amount == 0) {
            cout << "You won!\n";
            break;
        }
        //When the user loses, announce the loss and say how many ships were left
        if (i == 0 && amount > 1) {
            cout << "You lost! There were " << amount << " ships remaining. Try again\n";
            break;
        }
        else if (i == 0) {
            cout << "You lost! There was 1 ship remaining\n";
            break;
        }
    }
    return 0;
}
