#include "game.h"

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
}

// Parse through single row of data and separate values
vector<string> game::parseLine(string line) {
    vector<string> row;
    string value;
    bool insideQuotes = false;

    // Separate based on comma but ignore commas within quotes
    // Code based on https://stackoverflow.com/questions/48085842/how-do-i-parse-a-csv-with-commas-embedded-in-quoted-fields
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

// Go through data table and organize into tables and specific categories
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
                    vector<string> m = multiplayerTable["Single Player"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        multiplayerTable["Single Player"].push_back(row[1]);
                    }
                }else {
                    vector<string> m2 = multiplayerTable["Multiplayer"];
                    auto it = find(m2.begin(), m2.end(), row[1]);
                    if(it == m2.end()) {
                        multiplayerTable["Multiplayer"].push_back(row[1]);
                    }
                }
            }

            // Classify games based on maturity rating
            if(j == 24 || j == 25 || j == 26) {
                if(j == 24 && row[j] == "1") {
                    vector<string> m = maturityTable["Rated E"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        maturityTable["Rated E"].push_back(row[1]);
                    }
                }else if(j == 25 && row[j] == "1") {
                    vector<string> m = maturityTable["Rated T"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        maturityTable["Rated T"].push_back(row[1]);
                    }
                }else if(j == 26 && row[j] == "1") {
                    vector<string> m = maturityTable["Rated M"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        maturityTable["Rated M"].push_back(row[1]);
                    }
                }
            }

            // Classify games based on review score
            if(j == 22) {
                int score = stoi(row[j]);
                if(score > 90) {
                    vector<string> m = scoreTable["91-100"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["91-100"].push_back(row[1]);
                    }
                }else if(score > 80) {
                    vector<string> m = scoreTable["81-90"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["81-90"].push_back(row[1]);
                    }
                }else if(score > 70) {
                    vector<string> m = scoreTable["71-80"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["71-80"].push_back(row[1]);
                    }
                }else if(score > 60) {
                    vector<string> m = scoreTable["61-70"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["61-70"].push_back(this->data[i][1]);
                    }
                }else if(score > 50) {
                    vector<string> m = scoreTable["51-60"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["51-60"].push_back(this->data[i][1]);
                    }
                }else if(score > 40) {
                    vector<string> m = scoreTable["41-50"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["41-50"].push_back(this->data[i][1]);
                    }
                }else if(score > 30) {
                    vector<string> m = scoreTable["31-40"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["31-40"].push_back(this->data[i][1]);
                    }
                }else if(score > 20) {
                    vector<string> m = scoreTable["21-30"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["21-30"].push_back(this->data[i][1]);
                    }
                }else if(score > 10) {
                    vector<string> m = scoreTable["11-20"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["11-20"].push_back(this->data[i][1]);
                    }
                }else {
                    vector<string> m = scoreTable["00-10"];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        scoreTable["00-10"].push_back(this->data[i][1]);
                    }
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
                    vector<string> m = genreTable[genre];
                    auto it = find(m.begin(), m.end(), row[1]);
                    if(it == m.end()) {
                        genreTable[genre].push_back(this->data[i][1]);
                    }
                }
            }
        }
    }


}

// Helper function for heapSort function
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

// Code based on video solution to Edugator questions in Module 8
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

// Helper function for quickSort function
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

// Code based on video solution to Edugator questions in Module 8
void game::quickSort(vector<string>& gamesList, int low, int high){

    if(low < high){
        int pivot = partition(gamesList, low, high);
        quickSort(gamesList, low, pivot - 1);
        quickSort(gamesList, pivot + 1, high);
    }
}

// Return list of games for specified genre
vector<string> game::getGenre(string genre) {
    vector<string> genreList = genreTable[genre];
    vector<string> genreList2 = genreTable[genre];

    // Timer while calling heapSort
    auto startHeap = chrono::steady_clock::now();
    heapSort(genreList);
    auto endHeap = chrono::steady_clock::now();
    auto durationHeap = chrono::duration_cast<chrono::microseconds>(endHeap - startHeap);

    // Timer while calling quickSort
    auto startQuick = chrono::steady_clock::now();
    quickSort(genreList2, 0, genreList2.size() - 1);
    auto endQuick = chrono::steady_clock::now();
    auto durationQuick = chrono::duration_cast<chrono::microseconds>(endQuick - startQuick);

    // Print out sorted list
    cout << genre << " Games: "  << endl;
    for(const auto n : genreList){
        cout << n << endl;
    }
    cout << endl;
    cout << "Heap Sort time: " << durationHeap.count() << " microseconds" << endl;
    cout << "Quick sort time: " << durationQuick.count() << " microseconds" << endl;
    return genreList;
}

// Return list of games for specified maturity
vector<string> game::getMaturity(string maturity) {
    vector<string> maturityList = maturityTable[maturity];
    vector<string> maturityList2 = maturityTable[maturity];

    // Timer while calling heapSort
    auto startHeap = chrono::steady_clock::now();
    heapSort(maturityList);
    auto endHeap = chrono::steady_clock::now();
    auto durationHeap = chrono::duration_cast<chrono::microseconds>(endHeap - startHeap);

    // Timer while calling quickSort
    auto startQuick = chrono::steady_clock::now();
    quickSort(maturityList2, 0, maturityList2.size() - 1);
    auto endQuick = chrono::steady_clock::now();
    auto durationQuick = chrono::duration_cast<chrono::microseconds>(endQuick - startQuick);

    // Print out sorted list
    cout << maturity << " Games: "  << endl;
    for(const auto n : maturityList){
        cout << n << endl;
    }

    cout << endl;
    cout << "Heap Sort time: " << durationHeap.count() << " microseconds" << endl;
    cout << "Quick sort time: " << durationQuick.count() << " microseconds" << endl;

    return maturityList;
}

// Return list of games for specified console
vector<string> game::getConsole(string console) {
    vector<string> consoleList = consoleTable[console];
    vector<string> consoleList2 = consoleTable[console];

    // Timer while calling heapSort
    auto startHeap = chrono::steady_clock::now();
    heapSort(consoleList);
    auto endHeap = chrono::steady_clock::now();
    auto durationHeap = chrono::duration_cast<chrono::microseconds>(endHeap - startHeap);

    // Timer while calling quickSort
    auto startQuick = chrono::steady_clock::now();
    quickSort(consoleList2, 0, consoleList2.size() - 1);
    auto endQuick = chrono::steady_clock::now();
    auto durationQuick = chrono::duration_cast<chrono::microseconds>(endQuick - startQuick);

    // Print out sorted list
    cout << console << " Games: "  << endl;
    for(const auto n : consoleList){
        cout << n << endl;
    }
    cout << endl;
    cout << "Heap Sort time: " << durationHeap.count() << " microseconds" << endl;
    cout << "Quick sort time: " << durationQuick.count() << " microseconds" << endl;

    return consoleList;

}

// Return list of games for specified player mode
vector<string> game::getMultiplayer(string multiplayer) {
    vector<string> multiplayerList = multiplayerTable[multiplayer];
    vector<string> multiplayerList2 = multiplayerTable[multiplayer];

    // Timer while calling heapSort
    auto startHeap = chrono::steady_clock::now();
    heapSort(multiplayerList);
    auto endHeap = chrono::steady_clock::now();
    auto durationHeap = chrono::duration_cast<chrono::microseconds>(endHeap - startHeap);

    // Timer while calling quickSort
    auto startQuick = chrono::steady_clock::now();
    quickSort(multiplayerList2, 0, multiplayerList2.size() - 1);
    auto endQuick = chrono::steady_clock::now();
    auto durationQuick = chrono::duration_cast<chrono::microseconds>(endQuick - startQuick);

    // Print out sorted list
    cout << multiplayer << " Games: "  << endl;
    for(const auto n : multiplayerList){
        cout << n << endl;
    }
    cout << endl;
    cout << "Heap Sort time: " << durationHeap.count() << " microseconds" << endl;
    cout << "Quick sort time: " << durationQuick.count() << " microseconds" << endl;

    return multiplayerList;
}

// Return list of games for specified review score
vector<string> game::getScore(string score) {
    vector<string> scoreList = scoreTable[score];
    vector<string> scoreList2 = scoreTable[score];

    // Timer while calling heapSort
    auto startHeap = chrono::steady_clock::now();
    heapSort(scoreList);
    auto endHeap = chrono::steady_clock::now();
    auto durationHeap = chrono::duration_cast<chrono::microseconds>(endHeap - startHeap);

    // Timer while calling quickSort
    auto startQuick = chrono::steady_clock::now();
    quickSort(scoreList2, 0, scoreList2.size() - 1);
    auto endQuick = chrono::steady_clock::now();
    auto durationQuick = chrono::duration_cast<chrono::microseconds>(endQuick - startQuick);

    // Print out sorted list
    cout << score << " Games: "  << endl;
    for(const auto n : scoreList){
        cout << n << endl;
    }
    cout << endl;
    cout << "Heap Sort time: " << durationHeap.count() << " microseconds" << endl;
    cout << "Quick sort time: " << durationQuick.count() << " microseconds" << endl;

    return scoreList;
}

void game::mainMenu() {
    cout << "Please select the category you want to search:\n";
    cout << "1. Genre\n";
    cout << "2. Maturity Rating\n";
    cout << "3. Gaming Console\n";
    cout << "4. Multiplayer\n";
    cout << "5. Review Score\n";
    cout << "6. Exit\n";
    cout << "Input:  ";
}