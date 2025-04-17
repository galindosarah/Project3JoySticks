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


    return 0;
}