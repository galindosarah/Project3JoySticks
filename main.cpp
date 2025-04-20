#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "game.h"
using namespace std;

int main() {

    game table("../resources/Managerial_and_Decision_Economics_2013_Video_Games_Dataset.csv");
    table.parseData();

    table.getGenre("Strategy");
    cout << endl << endl;
    table.getMaturity("Rated E");
    cout << endl << endl;
    table.getConsole("Sony PSP");
    cout << endl << endl;
    table.getMultiplayer("Single Player");
    cout << endl << endl;
    table.getScore("81-90");

    return 0;
}