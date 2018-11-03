//
// Created by patgi on 2018-11-02.
//

#include "dictionary.hpp"
#include <iostream>
#include <sstream>

/*dictionary::dictionary() {
    fstream fstr;
    string str, key, value;
    fstr.open("../dictionary.txt");
    while(fstr.good()){
        getline(fstr, str);
        stringstream ss(str);
        while(ss.good()){
            getline(ss, key, ';');
            getline(ss, value);
        }
    }
}*/

dictionary::dictionary() {
    string key, value;
    fstream fstream1;
    fstream1.open("../dictionary.txt");
    stringstream ss;

    while(getline(getline(fstream1, key, ';') >> std::ws, value))
        dict.insert(pair<string,string>(key, value));

}


void dictionary::print(){
    map<string,string>::iterator iterator1;
    for(iterator1 = dict.begin(); iterator1 != dict.end(); ++iterator1) {
        cout << iterator1->first << ": " << iterator1->second << "\n";
    }
}

string dictionary::findWord(string word) {
    if(dict.find(word) == dict.end()) {
        return "word not found";
    }
    string def = dict.find(word)->second;
    return def;
}

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
