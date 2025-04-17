#include "game.h"

game::game(string filePath) {
    ifstream file(filePath);  // Ensure the correct file path
    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    string line;
    getline(file, line);


    // Read file line by line
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row = parseLine(line);
        this->data.push_back(row);
    }

    file.close();
    for (size_t i = 1; i < min(data.size(), size_t(6)); i++) {
        for (const auto &val : data[i]) {
            cout << val << " | ";
        }
        cout << endl;
    }
}

vector<string> game::parseLine(string line) {
    vector<string> row;
    string value;
    bool insideQuotes = false;

    for(const auto c : line) {
        if (c == '"') {
            insideQuotes = !insideQuotes;
        }else if (c == ',' && !insideQuotes) {
            row.push_back(value);
            value.clear();
        }else {
            value += c;
        }
    }
    row.push_back(value);
    return row;
}

void game::parseData() {
    for(int i = 0; i < this->data.size(); i++) {
        vector<string> row = this->data[i];
        for(int j = 0; j < row.size(); j++) {
            //Sorting based on console
            if(j == 0) {
                consoleTable[this->data[i][0]].push_back(this->data[i][1]);
            }
            //Sorting based on number of players
            if(j == 29) {
                if(row[j] == "1") {
                    multiplayerTable["Single Player"].push_back(this->data[i][1]);
                }else {
                    multiplayerTable["Multiplayer"].push_back(this->data[i][1]);
                }
            }
            //Sorting based on maturity rating
            if(j == 24 || j == 25 || j == 26) {
                if(j == 24 && row[j] == "1") {
                    maturityTable["Rated E"].push_back(this->data[i][1]);
                }else if(j == 25 && row[j] == "1") {
                    maturityTable["Rated T"].push_back(this->data[i][1]);
                }else if(j == 26 && row[j] == "1") {
                    maturityTable["Rated M"].push_back(this->data[i][1]);
                }
            }
            //Sorting based on review score
            if(j == 22) {
                int score = stoi(row[j]);
                if(score > 90) {
                    scoreTable["91-100"].push_back(this->data[i][1]);
                }else if(score > 80) {
                    scoreTable["81-90"].push_back(this->data[i][1]);
                }else if(score > 70) {
                    scoreTable["71-80"].push_back(this->data[i][1]);
                }else if(score > 60) {
                    scoreTable["61-70"].push_back(this->data[i][1]);
                }else if(score > 50) {
                    scoreTable["51-60"].push_back(this->data[i][1]);
                }else if(score > 40) {
                    scoreTable["41-50"].push_back(this->data[i][1]);
                }else if(score > 30) {
                    scoreTable["31-40"].push_back(this->data[i][1]);
                }else if(score > 20) {
                    scoreTable["21-30"].push_back(this->data[i][1]);
                }else if(score > 10) {
                    scoreTable["11-20"].push_back(this->data[i][1]);
                }else {
                    scoreTable["00-10"].push_back(this->data[i][1]);
                }
            }
            if(j == 17) {
                string genres = row[j];
                string genre;

                // for(const auto c : genres) {
                //     if()
                // }
            }
        }
    }
    for(const auto k : scoreTable) {
        cout << k.first << ": ";
        for(const auto v : k.second) {
            cout << v << ", ";
        }
        cout << endl;
        cout << endl;
    }
    cout << scoreTable.size() << endl;

}

vector<string> game::getGenre(string genre) {
}

vector<string> game::getMaturity(string maturity) {
}

vector<string> game::getConsole(string console) {
}

vector<string> game::getMultiplayer(string multiplayer) {
}

vector<string> game::getScore(string score) {
}
