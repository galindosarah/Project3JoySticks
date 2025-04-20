#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "game.h"
using namespace std;

int main() {
    int choice;
    game table("../resources/Managerial_and_Decision_Economics_2013_Video_Games_Dataset.csv");
    table.parseData();

    table.mainMenu();
    cin >> choice;

    switch (choice){
        case 3:
            int consoleChoice;
            string consoleName;
            cout << "==Please Enter a Console Name==\n";
            cout << "1. Nintendo DS\n";
            cout << "2. Sony PSP\n";
            cout << "3. Xbox 360\n";
            cout << "4. Nintendo Wii\n";
            cout << "5. PlayStation 3\n";
            cin >> consoleChoice;
            if (consoleChoice == 1){
                consoleName = "Nintendo DS";
            }
            else if (consoleChoice == 2){
                consoleName = "Sony PSP";
            }
            else if (consoleChoice == 3){
                consoleName = "X360";
            }
            else if (consoleChoice == 4){
                consoleName = "Nintendo Wii";
            }
            else if (consoleChoice == 5){
                consoleName = "PlayStation 3";
            }

            table.getConsole(consoleName);
    }


    return 0;
}