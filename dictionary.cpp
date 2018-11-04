//
// Created by patgi on 2018-11-02.
//

#include "dictionary.hpp"
#include <iostream>
#include <sstream>

/* dictionary constructor,
 * opens a file called dictionary.txt in the root folder, parses the text
 * and adds it to the dictionary map
 * */
dictionary::dictionary() {
    string key, value;
    fstream fstream1;
    fstream1.open("../dictionary.txt");
    stringstream ss;

    while(getline(getline(fstream1, key, ';') >> std::ws, value))
        dict.insert(pair<string,string>(key, value));
    fstream1.close();
}

/*This function iterates through the dictionary map and prints out key
 * and definitions
*@param - no param
*@return - void
*/
void dictionary::print(){
    map<string,string>::iterator iterator1;
    for(iterator1 = dict.begin(); iterator1 != dict.end(); ++iterator1) {
        cout << iterator1->first << ": " << iterator1->second << "\n";
    }
}

/*This function takes a string and searches the map to find a match
*@param - word - a string to be searched for in the map
*@return - returns a string of either the definition or not found.
*/
string dictionary::findWord(string word) {
    if(dict.find(word) == dict.end()) {
        return "word not found";
    }
    string def = dict.find(word)->second;
    return def;
}

/*This function takes a word, checks if its in the map, and asks
 * for a definition if not already in the map
*@param - word - string word to find and/or add a definition for
*@return - void
*/
void dictionary::newWord(string word) {
    string def, input;
    if(dict.find(word) != dict.end()) {
        cout << "word already exists";
        return;
    }
    cout << "enter new definition";
    cin.clear();
    cin.ignore();
    getline(cin, def);
    dict.insert(pair<string, string>(word, def));
    ofstream out("../dictionary.txt", std::ios_base::app);
    out << "\n" << word << "; " << def;
    out.close();
}
