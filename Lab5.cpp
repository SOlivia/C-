#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int wordIndex(string);      //Protoype a function to check if the vector contains the word
void processWord(string);   //Prototype a function to handle each word found

vector<string> wordList;    //The dynamic word list
vector<int> wordCount;      //The dynamic word count

int main() {
    ifstream file("/Users/Som/Documents/ITU/C++/Lab5/Quote.txt");
    if (!file) {
        cout << "Error: Failed to read file" << endl;
    } else {
        //Read each word into the 'word' variable
        string word;
        while (!file.eof()) {
            file >> word;
            //Algorithm to remove punctuation here
            processWord(word);
        }
    }

    //Write the output to the console
    cout << "Word Frequency Analysis" << endl;
    cout << "Word Frequency" << endl;
    for (int i = 0, j = wordList.size(); i < j; i++) {
        cout << wordList[i] << ": " << wordCount[i] << endl;
    }

    system("pause");
    return 0;
}

void processWord(string word) {
    int index = wordIndex(word);    //Get the index of the word in the vector - if the word isn't in the vector yet, the function returns -1.
                                    //This serves a double purpose: Check if the word exsists in the vector, and if it does, what it's index is.
    if (index > -1) {
        wordCount[index]++;         //If the word exists, increment it's word count in the parallel vector.
    } else {
        wordList.push_back(word);   //If not, add a new entry
        wordCount.push_back(1);     //in both vectors.
    }
}

int wordIndex(string word) {
    //Iterate through the word list vector
    for (int i = 0, j = wordList.size(); i < j; i++) {
        if (wordList[i] == word) {
            return i;               //The word has been found. return it's index.
        }
    }
    return -1;                      //The word is not in the vector. Return -1 to tell the program that the word hasn't been added yet.
}
