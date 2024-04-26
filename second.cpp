#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("test_input-7.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file!\n";
        return 1;
    }

    int no_computers, no_connections;
    inputFile >> no_computers >> no_connections;

    vector<vector<int>> connections;

    for (int i = 0; i < no_connections; i++) {
        int x, y;
        inputFile >> x >> y;
        connections.push_back({x, y});
    }

    inputFile.close();

    // Output to the terminal
    for (const auto& connection : connections) {
        for (int value : connection) {
            cout << value << " ";
        }
        cout << "\n";
    }

    cout << no_computers << " " << no_connections << "\n";

    return 0;
}
