#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <string>
#include <vector>

using namespace std;

class DataAccess {
public:
    static pair<vector<string>, vector<bool>> load(const string& filename);
    static void save(const string& filename, const vector<string>& lines, const vector<bool>& checks);
};

#endif