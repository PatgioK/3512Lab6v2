#include <iostream>
#include "dictionary.hpp";

int main() {
    std::cout << "Hello, World!" << std::endl;
    dictionary dict1;
    int choice;
    string word;
    string def;
    while(choice != 4) {
        cout << "\n 1- Print dictionary \n 2- find word definition \n 3- enter new word and definition \n 4- exit \n";
        cin >> choice;

        switch(choice) {
            case 1:
                dict1.print();
                break;
            case 2:
                cout << "enter word";
                cin >> word;
                cout << dict1.findWord(word) << "\n";
                break;
            case 3:
                cout << "enter word";
                cin >> word;
                dict1.newWord(word);

        }
    }

    return 0;
}