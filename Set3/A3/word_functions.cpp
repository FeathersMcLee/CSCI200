/* CSCI 200: Assignment 3: A3 - Green Eggs and Ham
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // ZYBooks
 *     // StackOverflow
 *     // CPlusPlus.com
 *
 * This file contains the functions that count the number of words and letters used in a given text file. There is also a function to report the most and least frequently used words and letters.
 */

#include "word_functions.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <exception>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstddef>

using namespace std;

// Run program using ./A3 input/greeneggsandham.txt

bool open_file(ifstream& fileIn, const string filename) {
    // Open files
    fileIn.open(filename);

    // Validate files
    if ( !fileIn ) {
        cerr << "Error opening input file" << endl;
        return false;
    }
    cout << flush;
    return true;
}

vector<string> read_words_from_file(ifstream& fileIn ) {
    // Read each word from given file and add to a vector that can be referenced in the future.
    string word;
    vector<string> fileVect;
    while ( !fileIn.eof()) {
        fileIn >> word;
        fileVect.push_back(word);
    }
    return fileVect;
}

void remove_punctuation(vector<string>& allWords, string PUNCTUATION_TO_REMOVE) {
    // Removes punctuation from all words one at a time
    int wordCount = allWords.size();
    vector<string> cleanWords(wordCount);
    for (int i = 0; i < wordCount; i++) {
        string word = allWords[i];
        size_t found = word.find_first_of(PUNCTUATION_TO_REMOVE);
        while (found!=string::npos) {
            word.erase(found,1);
            found=word.find_first_of(PUNCTUATION_TO_REMOVE,found);
        }
        cleanWords[i] = word;
    }
    allWords = cleanWords;
}

void capitalize_words(vector<string>& allWords) {
    // Changes all letters to capps
    int wordCount = allWords.size();
    vector<string> capWords(wordCount);
    for (int i = 0; i < wordCount; i++) {
        string word = allWords[i];
        int strLen = word.length();
        for (int i = 0; i < strLen; i++ ) {
            char current = word.at(i);
            if (islower(current)) {
                word.at(i) = word.at(i) - 32;
            }
        }
        capWords[i] = word;
    }
    allWords = capWords;
}

vector<string> filter_unique_words(const vector<string> allWords) { 
    vector<string> uniqueWordList;
    int wordCount = allWords.size();
    for (int i = 0; i < wordCount; i++) {
        string word = allWords[i];
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (word == allWords[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueWordList.push_back(word);
        }
    }
    return uniqueWordList;
}

vector<unsigned int> count_unique_words(const vector<string> allWords, vector<string> uniqueWords) {
    vector<unsigned int> countVect;
    int wordCount = allWords.size();
    int uniqueCount = uniqueWords.size();
    for (int i = 0; i < uniqueCount; i++) {
        unsigned int count = 0;
        string word = allWords[i];
        for (int j = 0; j < wordCount; j++) {
            if (word == allWords[j]) {
                count++;
            }
        }
        countVect.push_back(count);
    }
    return countVect;
}

void print_unique_word_counts(vector<string> uniqueWords, vector<unsigned int> uniqueWordCounts) {
    int uniqueCount = uniqueWords.size();
    for (int i = 0; i < uniqueCount; i++) {
        cout << left << setw(17) << uniqueWords[i] << ": " << right << setw(3) << uniqueWordCounts[i] << endl;
    }
}

void count_letters(const vector<string> allWords, unsigned int *letters) {
    for (int i = 0; i < 26; i++) {
        int count = 0;
        char letter = char(65 + i);
        int wordCount = allWords.size();
        for (int j = 0; j < wordCount; j++) {
            string word = allWords[j];
            int strLen = word.length();
            for (int k = 0; k < strLen; k++ ) {
                char current = word.at(k);
                if (current == letter) {
                    count++;
                }
            }
        }
        letters[i] = count;
    }
    
}

void print_letter_counts(unsigned int* letters) {
    for (int i = 0; i < 26; i++) {
        char letter = char(65 + i);
        cout << letter << ": " << setw(5) << letters[i] << " " << endl;
    }

}

void print_max_min_letter(unsigned int* letters) {
    int totalLetters = 0;
    int Max = letters[0];
    int Min = letters[0];
    char maxLetter;
    char minLetter;
    for (int i = 0; i < 26; i++) {
        int value = letters[i];
        if (value > Max) {
            Max = value;
            maxLetter = char(65 + i);
        }
        if (value < Min) {
            Min = value;
            minLetter = char(65 + i);
        }
        totalLetters = totalLetters + value;
    }
    double maxStat = static_cast<double>(Max) / totalLetters * 100;
    double minStat = static_cast<double>(Min) / totalLetters * 100;
    int maxCount = 0;
    int numb = Max;
    while(numb != 0) {
        numb = numb / 10;
        maxCount++;
    }
    cout << fixed << setprecision(3);
    cout << "Least Frequent Letter: " << minLetter << " " << setw(maxCount) << Min << " (" << setw(6) << minStat << "%)" << endl;
    cout << " Most Frequent Letter: " << maxLetter << " " << setw(maxCount) << Max << " (" << setw(6) << maxStat << "%)" << endl;
}