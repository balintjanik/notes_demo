#include <iostream>
#include <string>
#include <vector>
#include "Model.hh"
using namespace std;


bool Model::isValid(const int length, const int idx){
    if (length <= 0){
        cout << "There are no notes stored" << endl;
        return false;
    }
    if (idx < 0 || idx >= length){
        cout << "Index must be between 1 and " << length << endl;
        return false;
    }
    return true;
}

int Model::getIdx(){
    cout << "Index of note: ";
    int idx;
    string input;
    getline(cin, input);
    try {
        idx = stoi(input);
        idx--;
    } catch (invalid_argument const &e) {
        cerr << "Invalid input" << endl;
        return -2;
    }
    return idx;
}

void Model::listNotes(const vector<string>& lines, const vector<bool>& checks)
{
    if (lines.size() <= 0){
        cout << "There are no notes stored!" << endl;
    }
    for (size_t i = 0; i < lines.size(); ++i) {
        if (checks[i]) {
            cout << (i+1) << ". [X] " << lines[i] << endl;
        } else {
            cout << (i+1) << ". [ ] " << lines[i] << endl;
        }
    }
}

void Model::addNote(vector<string>& lines, vector<bool>& checks)
{
    string input;
    getline(cin, input);
    lines.push_back(input);
    checks.push_back(false);
    cout << "Note successfully added!" << endl;
}

void Model::modifyNote(vector<string>& lines)
{
    int idx = getIdx();
    if (idx == -2) return;
    if (!isValid(lines.size(), idx)) return;

    cout << "Enter modified version of " << idx+1 << ". note: ";
    string input;
    getline(cin, input);
    lines[idx] = input;
    cout << "Note modified successfully!" << endl;
}

void Model::markDone(vector<bool>& checks)
{
    int idx = getIdx();
    if (idx == -2) return;
    if (!isValid(checks.size(), idx)) return;

    if (checks[idx] == true){
        checks[idx] = false;
        cout << "Note marked as not done successfully!" << endl;
    } else {
        checks[idx] = true;
        cout << "Note marked as done successfully!" << endl;
    }
}

void Model::deleteNote(vector<string>& lines, vector<bool>& checks){
    int idx = getIdx();
    if (idx == -2) return;
    if (!isValid(lines.size(), idx)) return;

    lines.erase(lines.begin() + idx);
    checks.erase(checks.begin() + idx);
    cout << "Note deleted successfully!" << endl;
}