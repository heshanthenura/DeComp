#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    while (true)
    {
        int randomNum = rand() % 10;
        int guess;
        cout << "Random Number: " << randomNum << endl;

        cout << "Guess the number (0-9): ";
        cin >> guess;

        if (guess == randomNum)
            cout << "Correct!\n";
        else
            cout << "Wrong! The correct answer was " << randomNum << ".\n";

        cout << endl;
    }
    return 0;
}
