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
    // Data Structures
    vector<vector<string>> data;
    unordered_map<string, vector<string>> genreTable; // key: genre, value: list of games
    unordered_map<string, vector<string>> maturityTable; // key: maturity rating, value: list of games
    unordered_map<string, vector<string>> consoleTable; // key: console, value: list of games
    unordered_map<string, vector<string>> multiplayerTable; // key: single/multi, value: list of games
    unordered_map<string, vector<string>> scoreTable; // key: score range, value: list of games
    // Helper Functions
    void heapify_down(vector<string>& gamesList, int size, int root);
    int partition(vector<string>& gamesList, int low, int high);
public:
    // Data Parsing
    game(string filePath);
    vector<string> parseLine(string line);
    void parseData();
    // Getters
    vector<string> getGenre(string genre);
    vector<string> getMaturity(string maturity);
    vector<string> getConsole(string console);
    vector<string> getMultiplayer(string multiplayer);
    vector<string> getScore(string score);
    // Sorting Algorithms
    void heapSort(vector<string>& gamesList);
    void quickSort(vector<string>& gamesList, int low, int high);
    // Menu
    void mainMenu();
};


#endif //DSAPROJECT3_GAME_H
