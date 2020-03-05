#include <iostream>
#include <stdlib.h>
#include"functions.h"
using namespace std;


char userInputForYesOrNo = '\0';

int main() {

restart:
    ResetElementsAndBoard();
    WelcomeScreen();
    StartGame();

    cout << "do you want to play again ('y'|'n'): ";
    cin >> userInputForYesOrNo;
    if (userInputForYesOrNo == 121 || userInputForYesOrNo == 89) {
        system("CLS");
        WelcomeScreen();

        cout << "\n";
        system("CLS");
        goto restart;
    }
    else {
        cout << "quiting...";
        return 0;
    }

    return 0;
}
