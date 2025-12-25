/* CSCI 200: Lab 1A (Math Equation Solver): Solves simple math equations
 *
 * Author: Isaac March
 *
 * For this lab I am computing two of the given mechanical engineering equations after asking for a user input.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/

  cout << "Deflection Equation" << endl; // print Hello world! to the screen
  double W;
  double L;
  double E;
  double I;
  cout << "Enter width: ";
  cin >> W;
  cout << "Enter length: ";
  cin >> L;
  cout << "Enter elastic modulus: ";
  cin >> E;
  cout << "Enter moment of inertia: ";
  cin >> I;
  double defl = (W*pow(L,3))/(3*E*I);
  cout << "Deflection = " << defl << endl;

  cout << "Heat Transfer Equation" << endl; // print Hello world! to the screen
  double h;
  double A;
  double dt;
  cout << "Enter conductivity: ";
  cin >> h;
  cout << "Enter area: ";
  cin >> A;
  cout << "Enter temperture change: ";
  cin >> dt;
  double Q = h*A*dt;
  cout << "Q = " << Q << endl;
  /******** INSERT YOUR CODE ABOVE HERE *********/

  return 0; // signals the operating system that our program ended OK.
}