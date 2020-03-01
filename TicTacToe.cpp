#include <iostream>
#include <stdlib.h>

using namespace std;

void WelcomeScreen();
void ReadingAndWriting();

bool CheckingForAnyXSeries();
bool CheckingForAnyOSeries();

void StartGame();

///global var;

char board[3][3] = { {'a','a','a',},     // |1|2|3|
                     {'a','a','a',},     // |4|5|6|
                     {'a','a','a',} };   // |7|8|9|

// dont change the values;
int hLine1X[3] = { 0,0,0 };
int hLine2X[3] = { 0,0,0 };
int hLine3X[3] = { 0,0,0 };

const int forX = 120; //for x;
const int forO = 111; // for o;

int x = 2;
int o = 1;

bool findXval = false;
bool findOval = false;

int playerInput = 0;
char userInputForYesOrNo = '\0';

bool elementAdded[3][3] = { {false,false,false},
                            {false,false,false},
                            {false,false,false} };

int main() {

    restart:
    WelcomeScreen();
    StartGame();

    cout << "do you want to play again ('y'|'n'): ";
    cin >> userInputForYesOrNo;
    if (userInputForYesOrNo == 121 || userInputForYesOrNo == 89) {
        system("CLS");
        WelcomeScreen();
        /// changing the elementadded array back to default;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                elementAdded[i][j] = false;
            }

        }
        /// changing the board array back to default;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                board[i][j] = 'a';
            }

        }
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

void WelcomeScreen() {
    cout << "---TIC TAC TOE---\n";
    cout << "\nPlayer 1 = 'o'\n";
    cout << "Player 2 = 'x'\n\n";
}

void StartGame() {

    for ( int m = 1; m <= 10; m++) {
        if (m >= 10) {
            cout << "No one win\n";
            ///forced to play one more time...;
            system("CLS");
            WelcomeScreen();
        }

        if (m % 2 == 0) {
        notvaliedX:
            cout << "player 2: "; cin >> playerInput;

            /// first row;
            if (playerInput <= 3) {

                if (elementAdded[0][playerInput - 1] == false) {
                    board[0][playerInput - 1] = 'x';
                    elementAdded[0][playerInput - 1] = true;
                }
                else {
                    cout << playerInput << " is taken, retry: \n";
                    goto notvaliedX;
                }

            }
            // second row;
            else if (playerInput >= 4 && playerInput <= 6) {

                if (elementAdded[1][playerInput - 3 - 1] == false) {
                    board[1][playerInput - 3 - 1] = 'x';
                    elementAdded[1][playerInput - 3 - 1] = true;
                }
                else {
                    cout << playerInput << " is taken, retry: \n";
                    goto notvaliedX;
                }

            }
            //third row;
            else if (playerInput >= 7 && playerInput <= 9) {

                if (elementAdded[2][playerInput - 3 - 3 - 1] == false) {
                    board[2][playerInput - 3 - 3 - 1] = 'x';
                    elementAdded[2][playerInput - 3 - 3 - 1] = true;
                }
                else {
                    cout << playerInput << " is taken, retry: \n\n";
                    goto notvaliedX;
                }
            }
            /// !first !second !third: 
            else {
                cout << "\nInput Valid Value:\n";
                goto notvaliedX;
            }

            ReadingAndWriting();

            findXval = CheckingForAnyXSeries();
            findOval = CheckingForAnyOSeries();

            if (findXval == true) {
                cout << "player 2 Win!\n";
                break;
            }
        }
        else {

            /// assinging values of 'o' relate to playerInput;
        notvaliedO:
            cout << "player 1: "; cin >> playerInput;

            // first row
            if (playerInput <= 3 && playerInput >= 0) {

                if (elementAdded[0][playerInput - 1] == false) {
                    board[0][playerInput - 1] = 'o';
                    elementAdded[0][playerInput - 1] = true;
                }
                else {
                    cout << playerInput << " is taken, retry: \n";
                    goto notvaliedO;
                }

            }

            //second row
            else if (playerInput >= 4 && playerInput <= 6) {

                if (elementAdded[1][playerInput - 3 - 1] == false) {
                    board[1][playerInput - 3 - 1] = 'o';
                    elementAdded[1][playerInput - 3 - 1] = true;

                }
                else {
                    cout << playerInput << " is taken, retry: \n";
                    goto notvaliedO;
                }
            }

            //third row
            else if (playerInput >= 7 && playerInput <= 9) {


                if (elementAdded[2][playerInput - 3 - 3 - 1] == false) {
                    board[2][playerInput - 3 - 3 - 1] = 'o';
                    elementAdded[2][playerInput - 3 - 3 - 1] = true;
                }
                else {
                    cout << playerInput << " is taken, retry: \n";
                    goto notvaliedO;
                }
            }
            // !first !second !third :
            else {
                cout << "\nInput Valid Value:\n";
                goto notvaliedO;
            }

            ReadingAndWriting();

            findXval = CheckingForAnyXSeries();
            findOval = CheckingForAnyOSeries();

            if (findOval == true) {
                cout << "Player 1 Win!\n";
                break;
            }

        }
    }
}

void ReadingAndWriting() {

    /*  check each time the elementAdded arry change values 0/1
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            cout << elementAdded[i][j] << " ";
        }cout << endl;
    }
    cout <<endl;
    */

    system("CLS");
    WelcomeScreen();

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            ///checking && assign for (0,0) , (0,1) , (0,2)
            if (j < 3 && i == 0) {
                if (board[i][j] == forO) {
                    cout << " o ";
                    hLine1X[j] = 1;
                    continue;
                }
                else if (board[i][j] == forX) {
                    cout << " x ";
                    hLine1X[j] = 2;
                }
                else {
                    hLine1X[j] = 0;
                    cout << "   ";
                }
            }
            ///cheking  && assign  for (1,0), (1,1), (1,2);
            if (j < 3 && i == 1) {
                if (board[i][j] == forO) {
                    cout << " o ";
                    hLine2X[j] = 1;
                    continue;
                }
                else if (board[i][j] == forX) {
                    cout << " x ";
                    hLine2X[j] = 2;
                }
                else {
                    hLine2X[j] = 0;//no vales;
                    cout << "   ";
                }
            }
            ///checking && assign for (2,0), (2,1) ,(2,2);
            if (j < 3 && i == 2) {
                if (board[i][j] == forO) {
                    cout << " o ";
                    hLine3X[j] = 1;
                    continue;
                }
                else if (board[i][j] == forX) {
                    cout << " x ";
                    hLine3X[j] = 2;
                }
                else {
                    hLine3X[j] = 0;//no values;
                    cout << "   ";
                }
            }
        }
        std::cout << "\n";
    }
    cout << "\n";
};

bool CheckingForAnyXSeries() {
    if (hLine1X[0] == x && hLine1X[1] == x && hLine1X[2] == x) { return true; }
    else if (hLine2X[0] == x && hLine2X[1] == x && hLine2X[2] == x) { return true; }
    else if (hLine3X[0] == x && hLine3X[1] == x && hLine3X[2] == x) { return true; }
    else if (hLine1X[0] == x && hLine2X[0] == x && hLine3X[0] == x) { return true; }
    else if (hLine1X[1] == x && hLine2X[1] == x && hLine3X[1] == x) { return true; }
    else if (hLine1X[1] == x && hLine2X[1] == x && hLine3X[1] == x) { return true; }
    else if (hLine1X[2] == x && hLine2X[2] == x && hLine3X[2] == x) { return true; }
    else if (hLine1X[0] == x && hLine2X[1] == x && hLine3X[2] == x) { return true; }
    else if (hLine1X[2] == x && hLine2X[1] == x && hLine3X[0] == x) { return true; }
    else { return false; }
};
bool CheckingForAnyOSeries() {
    if (hLine1X[0] == o && hLine1X[1] == o && hLine1X[2] == o) { return true; }
    else if (hLine2X[0] == o && hLine2X[1] == o && hLine2X[2] == o) { return true; }
    else if (hLine3X[0] == o && hLine3X[1] == o && hLine3X[2] == o) { return true; }
    else if (hLine1X[0] == o && hLine2X[0] == o && hLine3X[0] == o) { return true; }
    else if (hLine1X[1] == o && hLine2X[1] == o && hLine3X[1] == o) { return true; }
    else if (hLine1X[1] == o && hLine2X[1] == o && hLine3X[1] == o) { return true; }
    else if (hLine1X[2] == o && hLine2X[2] == o && hLine3X[2] == o) { return true; }
    else if (hLine1X[0] == o && hLine2X[1] == o && hLine3X[2] == o) { return true; }
    else if (hLine1X[2] == o && hLine2X[1] == o && hLine3X[0] == o) { return true; }
    else { return false; }
};
