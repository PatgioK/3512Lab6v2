//
// Created by patgi on 2018-11-02.
//

#ifndef INC_3512LAB6_DICTIONARY_HPP
#define INC_3512LAB6_DICTIONARY_HPP

#include <map>
#include <iterator>
#include <fstream>
using namespace std;

class dictionary {
private:
    map<string,string> dict;
public:
    dictionary();
    void print();
    string findWord(string word);
    void newWord(string word);
    map<string,string> getDict();

};


#endif //INC_3512LAB6_DICTIONARY_HPP
