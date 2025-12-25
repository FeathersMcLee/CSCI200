int main() {
    const string WUMPUS_FILE_NAME = enter_wumpus_file();
    const string GAME_LOG_FILE_NAME = enter_game_log_file();

    ifstream wumpusFileIn(WUMPUS_FILE_NAME);
    ofstream gameLogOut;
    
    if( !open_files(wumpusFileIn, gameLogOut, WUMPUS_FILE_NAME, GAME_LOG_FILE_NAME) ) {
        cerr << "Error opening files" << endl;
        return -1;
    }

    int caveWidth, caveHeight; 
    read_world_header(wumpusFileIn, caveWidth, caveHeight);
    //cout << read_world_header(wumpusFileIn, caveWidth, caveHeight) << endl;
    cout << caveWidth << " " << caveHeight << endl;

    int wumpusX = -1, wumpusY = -1;
    int heroX = -1, heroY = -1;
    int pitX = -1, pitY = -1;

    if( !read_object_header(wumpusFileIn,
                            wumpusX, wumpusY,
                            heroX, heroY,
                            pitX, pitY) ) {
        cerr << "Not all objects placed in world" << endl;
        return -2;
    }
    cout << wumpusX << " " << wumpusY << endl << heroX << " " << heroY << endl << pitX << " " << pitY << endl;

    int numMoves;
    read_number_moves(wumpusFileIn, numMoves);
    cout << numMoves << endl;
    
    wumpusFileIn.close();
    gameLogOut.close();
    return 0;
}