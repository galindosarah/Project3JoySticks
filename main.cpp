#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "game.h"
using namespace std;

int main() {
    int choice = -1;
    game table("../resources/Managerial_and_Decision_Economics_2013_Video_Games_Dataset.csv");
    table.parseData();
    while (choice != 0) {
        table.mainMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int genreChoice;
                string genreName;
                cout << "==Please Enter a Genre==\n";
                cout << "1. Role-Playing\n";
                cout << "2. Strategy\n";
                cout << "3. Action\n";
                cout << "4. Educational\n";
                cout << "5. Racing/Driving\n";
                cout << "6. Simulation\n";
                cout << "7. Sports\n";
                cout << "8. Adventure\n";
                cout << "Input:" << " ";
                cin >> genreChoice;
                if (genreChoice == 1){
                    genreName = "Role-Playing (RPG)";
                } else if (genreChoice == 2){
                    genreName = "Strategy";
                } else if (genreChoice == 3){
                    genreName = "Action";
                } else if (genreChoice == 4){
                    genreName = "Educational";
                } else if (genreChoice == 5){
                    genreName = "Racing / Driving";
                } else if (genreChoice == 6){
                    genreName = "Simulation";
                } else if (genreChoice == 7){
                    genreName = "Sports";
                } else if (genreChoice == 8){
                    genreName = "Adventure";
                }
                else{
                    break;
                }
                table.getGenre(genreName);
                continue;
            }
            case 2: {
                int maturityChoice;
                string mRating;
                cout << "==Please Enter a Maturity Rating==\n";
                cout << "1. Everyone\n";
                cout << "2. Teen\n";
                cout << "3. Mature\n";
                cout << "Input: ";
                cin >> maturityChoice;
                if (maturityChoice == 1){
                    mRating = "Rated E";
                } else if (maturityChoice == 2){
                    mRating = "Rated T";
                } else if (maturityChoice == 3){
                    mRating = "Rated M";
                }
                else{
                    break;
                }
                table.getMaturity(mRating);
                continue;
            }
            case 3: {
                int consoleChoice;
                string consoleName;
                cout << "==Please Enter a Console Name==\n";
                cout << "1. Nintendo DS\n";
                cout << "2. Sony PSP\n";
                cout << "3. Xbox 360\n";
                cout << "4. Nintendo Wii\n";
                cout << "5. PlayStation 3\n";
                cout << "Input:" << " ";
                cin >> consoleChoice;
                if (consoleChoice == 1) {
                    consoleName = "Nintendo DS";
                } else if (consoleChoice == 2) {
                    consoleName = "Sony PSP";
                } else if (consoleChoice == 3) {
                    consoleName = "X360";
                } else if (consoleChoice == 4) {
                    consoleName = "Nintendo Wii";
                } else if (consoleChoice == 5) {
                    consoleName = "PlayStation 3";
                }

                table.getConsole(consoleName);
                break;
            }
            case 4: {
                int onlineChoice;
                string online;
                cout << "==Single Player or Multiplayer Games?==\n";
                cout << "1. Single Player\n";
                cout << "2. Multiplayer\n";
                cout << "Input: ";
                cin >> onlineChoice;
                if (onlineChoice == 1){
                    online = "Single Player";
                }
                else if (onlineChoice == 2){
                    online = "Multiplayer";
                }
                table.getMultiplayer(online);
                continue;
            }
            case 5: {
                int Range;
                string scoreRange;
                cout << "== Please Select a Score Range ==\n";
                cout << "1. 0 - 10\n";
                cout << "2. 11 - 20\n";
                cout << "3. 21 - 30\n";
                cout << "4. 31 - 40\n";
                cout << "5. 41 - 50\n";
                cout << "6. 51 - 60\n";
                cout << "7. 61 - 70\n";
                cout << "8. 71 - 80\n";
                cout << "9. 81 - 90\n";
                cout << "10. 91 - 100\n";
                cout << "Input: ";
                cin >> Range;
                if (Range == 1) {
                    scoreRange = "00-10";
                }
                else if (Range == 2) {
                    scoreRange = "11-20";
                }
                else if (Range == 3) {
                    scoreRange = "21-30";
                }
                else if (Range == 4) {
                    scoreRange = "31-40";
                }
                else if (Range == 5) {
                    scoreRange = "41-50";
                }
                else if (Range == 6) {
                    scoreRange = "51-60";
                }
                else if (Range == 7) {
                    scoreRange = "61-70";
                }
                else if (Range == 8) {
                    scoreRange = "71-80";
                }
                else if (Range == 9) {
                    scoreRange = "81-90";
                }
                else if (Range == 10) {
                    scoreRange = "91-100";
                }
                table.getScore(scoreRange);
                continue;
            }

        }
    }





    return 0;
}