#include <iostream>
#include <string>
#include <vector>
#include "Persistence/DataAccess.hh"
#include "Model/Model.hh"
using namespace std;

const string FILENAME = "notes.txt";

pair<vector<string>, vector<bool>> readTextFile(const string& filename);
void writeTextFile(const string& filename, const vector<string>& lines, const vector<bool>& checks);


int main(){
    auto [lines, checks] = DataAccess::load(FILENAME);

    int choice = -1;
    string input;
    while(choice != 6){
        cout << "========================" << endl;
        cout << "1. List notes" << endl;
        cout << "2. Add note" << endl;
        cout << "3. Modify note" << endl;
        cout << "4. Tick/untick note" << endl;
        cout << "5. Delete note" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter command: ";

        try {
            getline(cin, input);
            choice = stoi(input);

        } catch (invalid_argument const &e) {
            cerr << "Invalid input" << endl;
            continue;
        }
        cout << "========================" << endl;

        switch (choice)
        {
            case 1:
                cout << "List notes\n-----"  << endl;
                Model::listNotes(lines, checks);
                break;
            case 2:
                cout << "Add note\n-----"  << endl;
                Model::addNote(lines, checks);
                break;
            case 3:
                cout << "Modify note\n-----"  << endl;
                Model::modifyNote(lines);
                break;
            case 4:
                cout << "Tick/untick note\n-----"  << endl;
                Model::markDone(checks);
                break;
            case 5:
                cout << "Delete note\n-----"  << endl;
                Model::deleteNote(lines, checks);
                break;
            case 6:
                cout << "Exit"  << endl;
                break;
            default:
                cout << "Unknown command!" << endl;
                break;
        }
    }
    DataAccess::save(FILENAME, lines, checks);
    return 0;
}