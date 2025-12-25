#ifndef WUMPUS_FUNCTIONS_H
#define WUMPUS_FUNCTIONS_H

#include <string>
using namespace std;

string enter_wumpus_file();
string enter_game_log_file();
bool open_files(ifstream& wumpusFileIn, ofstream& gameLogOut, string WUMPUS_FILE_NAME, string GAME_LOG_FILE_NAME);
int read_world_header(ifstream& wumpusFileIn, int& caveWidth, int& caveHeight);
bool read_object_header(ifstream& wumpusFileIn, int& wumpusX, int& wumpusY, int& heroX, int& heroY, int& pitX, int& pitY);
void read_number_moves(ifstream& wumpusFileIn, int& numMoves);
bool choose_player();
void play_game(ifstream& wumpusFileIn, ofstream& gameLogOut, int& caveWidth, int& caveHeight, int& numMoves, int& wumpusX, int& wumpusY, int& heroX, int& heroY, int& pitX, int& pitY, bool PLAY_AS_HERO);

#endif //ADD_FUNCTIONS_H