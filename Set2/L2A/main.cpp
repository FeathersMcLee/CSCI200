/* CSCI 200: Lab 2 A: L2A - The Secret Moosage
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // ZYbooks
 *
 * Decodes a message sent by aliens.
 * Post decipher analysis: The aliens do not seem to have a strong understanding of cows.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // Input Paradigms - header record
    ifstream fileIn("secretMessage.txt");
    ofstream fileOut("decipheredMessage.txt");
    // Validate files
    if ( !fileIn ) {
        cerr << "Error opening input file" << endl;
        return -1;
    }
    if ( !fileOut ) {
        cerr << "Error opening output file" << endl;
        return -1;
    }

    // Extract, decode and write characters
    char ch;
    int count = 0;
    while ( !fileIn.eof()) {
        ch = fileIn.get();
        // Remove cout << ch; after debugging
        //cout << ch;
        // Replace "~" with " "
        if (ch == '~') {
            fileOut << ' ';
        }
        //shift letters up by
        else if (isalpha(ch)) {
            if (ch == 'z') {
                fileOut << 'a';
            }
             if (ch == 'Z') {
                fileOut << 'A';
            }
            else {
                fileOut << static_cast<char>(ch + 1);
            }
        }
        else if (isspace(ch)) {
            fileOut << endl;
        }
        else if (isdigit(ch)) {
            fileOut << static_cast<char>(ch + 1);
        }
        else {
            fileOut << ch;
        }
    }

    // Close files
    fileOut.close();
    fileIn.close();
    return 0;
}