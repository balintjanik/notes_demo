#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Model {
public:
    static void listNotes(const vector<string>& lines, const vector<bool>& checks);
    static void addNote(vector<string>& lines, vector<bool>& checks);
    static void modifyNote(vector<string>& lines);
    static void markDone(vector<bool>& checks);
    static void deleteNote(vector<string>& lines, vector<bool>& checks);
private:
    static bool isValid(const int length, const int idx);
    static int getIdx();
};

#endif