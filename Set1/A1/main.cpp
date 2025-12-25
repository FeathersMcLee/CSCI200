/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // ZYbooks
 *
 * Rock Paper Scissors mini game that can be played as many times as user desires all while counting wins, losses and draws.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.
string choice;
string ask;
int win;
int loss;
int playerchoice;
int computerchoice;
int draws;
// Must have a function named "main", which is the starting point of a C++ program.
int main() {
  srand(time(0));

  //introduce game
  cout << "Welcom one and all to a round of Rock, Paper, Scissors!" << endl;
  ask = "Y";
  //recive player choice
  while ((ask == "Y") || (ask == "y"))
  {
    cout << "(Enter: P, R or S)" << endl << "Player one: " << endl ;
    std::cin >> choice;
    if ((choice == "R") || (choice == "r"))
    {
      cout << endl << "Player choose Rock" << endl;
      playerchoice = 0;
    }
    else if ((choice == "P") || (choice == "p"))
    {
      cout << endl << "Player choose Paper" << endl;
      playerchoice = 1;
    }
    else if ((choice == "S") || (choice == "s"))
    {
      cout << endl << "Player choose Scissors" << endl;
      playerchoice = 2;
    }
    else
    {
      cout << endl << "Invalid choice, player defaults to Rock" << endl;
      playerchoice = 0;
    }
    
    //coputer generated choice
    computerchoice = rand() % 3;
    if (computerchoice == 0)
    {
      cout << "Computer choose Rock" << endl;
    }
    else if (computerchoice == 1)
    {
      cout << "Computer choose Paper" << endl;
    }
    else
    {
      cout << "Computer chose Scissors" << endl;
    }
    
    cout << endl;
    //declare winner
    if (playerchoice == 0)
    {
      if (computerchoice == 0)
      {
          cout << "Draw" << endl;
          draws++;
      }
      else if (computerchoice == 1)
      {
          cout << "Paper beats Rock." << endl << "Computer Wins" << endl;
          loss++;
      }
      else
      {
          cout << "Rock beats Scissors." << endl << "Player Wins" << endl;
          win++;
      }
    }
    if (playerchoice == 1)
    {
      if (computerchoice == 1)
      {
          cout << "Draw" << endl;
          draws++;
      }
      else if (computerchoice == 0)
      {
          cout << "Paper beats Rock." << endl << "Player Wins" << endl;
          win++;
      }
      else
      {
          cout << "Rock beats Scissors." << endl << "Cpmputer Wins" << endl;
          loss++;
      }
    }
    if (playerchoice == 2)
    {
      if (computerchoice == 2)
      {
          cout << "Draw" << endl;
          draws++;
      }
      else if (computerchoice == 1)
      {
          cout << "Scissors beats Paper." << endl << "Player Wins" << endl;
          win++;
      }
      else
      {
          cout << "Rock beats Scissors." << endl << "Computer Wins" << endl;
          loss++;
      }
    }
    cout << endl << "Do you want to play again? (Y/N) ";
    std::cin >> ask;
  }

  cout << "Thanks for playing!" << endl << "You won " << win << " game(s), lost " << loss << " game(s), and tied " << draws << " game(s)." << endl;
    
  return 0; // signals the operating system that our program ended OK.
}