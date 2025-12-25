/* CSCI 200: Lab 1B (Generate & Classify a Random Value): Solves simple math equations
 *
 * Author: Isaac March
 *
 * For this lab I am computing two of the given mechanical engineering equations after asking for a user input.
 */

#include <iostream> 
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  //seed random number generator
  srand(time(0));
  //use constants for debuging, delete = number;
  double Max;
  double Min;
  //ask fo user inputs (not in use while debuging)
  cout << "Enter the minimum value: " << endl;
  std::cin >> Max;
  int max = int(Max);
  cout << "Enter the maximum value: "<< endl;
  std::cin >> Min;
  int min = int(Min);
  //establish while conditions
  string ask ="Y";

  while (ask == "Y")
  {
    //generate random double
    int Random = (rand() % (max - min + 1)) + min;
    double random = (rand()/(double)RAND_MAX)*(max-min)+min;
    cout << "A random value is: " << random << endl;
    //find the threshold of each quartile from use inputs
    double firstquart = ((Max - Min)/4)*1.0 + Min;
    double secondquart = ((Max - Min)/4)*2.0 + Min;
    double thirdquart = ((Max - Min)/4)*3.0 + Min;
    if (random <= firstquart)
    {
      cout << "Number is in the first quartile" << endl;
    }
    else if ((random > firstquart) && (random <= secondquart))
    {
      cout << "Number is in the second quartile" << endl;
    }
    else if ((random > secondquart) && (random <= thirdquart))
    {
      cout << "Number is in the third quartile" << endl;
    }
    else
    {
      cout << "Number is in the fourth quartile" << endl;
    }
    //ask user input
    cout << "Do you want another random value? (Y/N) ";
    std::cin >> ask;
  }

  return 0; // signals the operating system that our1 program ended OK.
}

