#include "game.h"
//sarah smells
game::game(string filePath) {
    ifstream file(filePath);  // Ensure the correct file path
    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    string line;
    getline(file, line);


    // Read file line by line and push into data table
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

// Parse through single row of data and separate values
vector<string> game::parseLine(string line) {
    vector<string> row;
    string value;
    bool insideQuotes = false;

    // Separate based on comma but ignore commas within quotes
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

// Go through data table and
void game::parseData() {
    for(int i = 0; i < this->data.size(); i++) {
        vector<string> row = this->data[i];
        for(int j = 0; j < row.size(); j++) {

            // Classify games based on console
            if(j == 0) {
                consoleTable[this->data[i][0]].push_back(this->data[i][1]);
            }

            // Classify games based on number of players
            if(j == 29) {
                if(row[j] == "1") {
                    multiplayerTable["Single Player"].push_back(this->data[i][1]);
                }else {
                    multiplayerTable["Multiplayer"].push_back(this->data[i][1]);
                }
            }

            // Classify games based on maturity rating
            if(j == 24 || j == 25 || j == 26) {
                if(j == 24 && row[j] == "1") {
                    maturityTable["Rated E"].push_back(this->data[i][1]);
                }else if(j == 25 && row[j] == "1") {
                    maturityTable["Rated T"].push_back(this->data[i][1]);
                }else if(j == 26 && row[j] == "1") {
                    maturityTable["Rated M"].push_back(this->data[i][1]);
                }
            }

            // Classify games based on review score
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

            // Classify games based on genre
            if(j == 17) {
                string genres = row[j];
                stringstream ss(genres);
                string genre;

                // Separate based on comma for multi-genre games
                while(getline(ss, genre, ',')) {
                    string space;
                    getline(ss, space, ' '); // Skip space after comma
                    genreTable[genre].push_back(this->data[i][1]);
                }
            }
        }
    }

    // for(const auto k : genreTable) {
    //     cout << k.first << ": ";
    //     for(const auto v : k.second) {
    //         cout << v << ", ";
    //     }
    //     cout << endl;
    //     cout << endl;
    // }
    // cout << genreTable.size() << endl;

}

void game::heapify_down(vector<string>& gamesList, int size, int root){
    int max = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if(left < size && gamesList[left] > gamesList[max]){
        max = left;
    }
    if(right < size && gamesList[right] > gamesList[max]){
        max = right;
    }
    if(max != root){
        swap(gamesList[root], gamesList[max]);
        heapify_down(gamesList, size, max);
    }
}

void game::heapSort(vector<string>& gamesList){
    int n = gamesList.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify_down(gamesList, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(gamesList[0], gamesList[i]);
        heapify_down(gamesList, i, 0);
    }
}

int game::partition(vector<string>& gamesList, int low, int high){
    string pivot = gamesList[low];
    int up = low, down = high;

    while(up < down){
        for(int i = up; i < high; i++){
            if(gamesList[up] > pivot){
                break;
            }
            up++;
        }
        for(int j = high; j > low; j--){
            if(gamesList[down] < pivot){
                break;
            }
            down--;
        }
        if(up < down){
            swap(gamesList[up], gamesList[down]);
        }
    }
    swap(gamesList[low], gamesList[down]);
    return down;
}

void game::quickSort(vector<string>& gamesList, int low, int high){
    if(low < high){
        int pivot = partition(gamesList, low, high);
        quickSort(gamesList, low, pivot - 1);
        quickSort(gamesList, pivot + 1, high);
    }
}

vector<string> game::getGenre(string genre) {
    vector<string> genreList = genreTable[genre];
    heapSort(genreList);
    cout << genre << " Games: "  << endl;
    for(const auto n : genreList){
        cout << n << endl;
    }
    return genreList;
}

vector<string> game::getMaturity(string maturity) {
    vector<string> maturityList = maturityTable[maturity];
    quickSort(maturityList, 0, maturityList.size() - 1);
    cout << maturity << " Games: "  << endl;
    for(const auto n : maturityList){
        cout << n << endl;
    }
    return maturityList;
}

vector<string> game::getConsole(string console) {
}

vector<string> game::getMultiplayer(string multiplayer) {
}

vector<string> game::getScore(string score) {
}
