#include <iostream>
#include <vector>
#include "Book.h"
#include "Library.h"

using namespace std;

int main() {
    const int NUM_ROWS = 5;
    const int NUM_COLS = 6;
    char pWordle[NUM_ROWS][NUM_COLS];

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            pWordle[i][j] = '.';
            cout << pWordle[i][j] << endl;
        }
    }

    int numShelves, booksPerShelf;

    std::cin >> numShelves >> booksPerShelf;

    Book** pBookCase = new Book*[numShelves];

    std::string title, author;
    std::cin.ignore(); // Ignore the newline character after reading numShelves and booksPerShelf

    for (int shelf = 0; shelf < numShelves; shelf++) {
        pBookCase[shelf] = new Book[booksPerShelf];

        for (int book = 0; book < booksPerShelf; book++) {
            std::getline(std::cin, title);
            pBookCase[shelf][book].setTitle(title);

            std::getline(std::cin, author);
            pBookCase[shelf][book].setAuthor(author);
        }

        // Sort books on this shelf based on titles
        for (int i = 0; i < booksPerShelf - 1; i++) {
            for (int j = i + 1; j < booksPerShelf; j++) {
                if (pBookCase[shelf][i].getTitle() > pBookCase[shelf][j].getTitle()) {
                    std::swap(pBookCase[shelf][i], pBookCase[shelf][j]);
                }
            }
        }
    }

}