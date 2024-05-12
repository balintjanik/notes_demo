#include <iostream>
#include <fstream>
#include "DataAccess.hh"

pair<vector<string>, vector<bool>> DataAccess::load(const string& filename) {
    vector<string> lines;
    vector<bool> checks;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No notes found" << endl;
        return {lines, checks};
    }

    string line;
    while (getline(file, line)) {
        if (line.length() < 5) continue;
        char done = line[1];
        if (done == 'X'){
            checks.push_back(true);
        } else {
            checks.push_back(false);
        }
        lines.push_back(line.substr(4));
    }

    file.close();

    return {lines, checks};
}

void DataAccess::save(const string& filename, const vector<string>& lines, const vector<bool>& checks) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error saving notes" << endl;
        return;
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        if (checks[i]) {
            file << "[X] " << lines[i] << endl;
        } else {
            file << "[ ] " << lines[i] << endl;
        }
    }

    file.close();
}