#ifndef DSAPROJECT3_GAME_H
#define DSAPROJECT3_GAME_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class game {
private:
    vector<vector<string>> data;
    unordered_map<string, vector<string>> genreTable; //key: genre, value: list of games
    unordered_map<string, vector<string>> maturityTable; //key: maturity rating, value: list of games
    unordered_map<string, vector<string>> consoleTable; //key: console, value: list of games
    unordered_map<string, vector<string>> multiplayerTable; //key: single/multi, value: list of games
    unordered_map<string, vector<string>> scoreTable; //key: score range, value: list of games
    void heapify_down(vector<string>& gamesList, int size, int root);
    int partition(vector<string>& gamesList, int low, int high);
public:
    game(string filePath);
    vector<string> parseLine(string line);
    void parseData();
    vector<string> getGenre(string genre); //input is key for genreTable
    vector<string> getMaturity(string maturity); //input is key for maturityTable
    vector<string> getConsole(string console);
    vector<string> getMultiplayer(string multiplayer);
    vector<string> getScore(string score);
    void heapSort(vector<string>& gamesList);
    void quickSort(vector<string>& gamesList, int low, int high);
    //Menu
    void mainMenu();
};


#endif //DSAPROJECT3_GAME_H
