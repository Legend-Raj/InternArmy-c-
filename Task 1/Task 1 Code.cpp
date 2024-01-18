#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void setColor(int colorCode) {
    cout << "\033[" << colorCode << "m";
}


void resetColor() {
    cout << "\033[0m";
}

int main() {
    int a;
    srand(time(0)); 

    do {
        setColor(36); 
        cout << "***** WELCOME TO THE NUMBER GUESSING GAME *****" << endl;
        cout << "1. Number between 1-10\n2. Number between 1-50\n3. Number between 1-100\n";
        cout << "Kindly choose one of the options: ";
        resetColor(); 

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int check = 0;
                cout << "You have Three(3) chances to guess the Number!!" << endl;
                int num = 1 + (rand() % 10);
                bool won = false;
                cout << "The number has been decided, try to guess" << endl;

                while (check != 3 && !won) {
                    setColor(33); 
                    cout << "Enter your number: ";
                    resetColor(); 
                    check++;
                    int guess;
                    cin >> guess;

                    if (guess == num) {
                        setColor(32); 
                        cout << "Congratulations!!! You won!" << endl;
                        cout << "The number was " << guess << endl;
                        won = true;
                        resetColor(); 
                    } else {
                        setColor(31); 
                        cout << "Wrong Guess!! Number of Guesses: " << check << endl;
                        resetColor(); 
                    }
                }

                if (!won) {
                    setColor(31); 
                    cout << "Sorry, You Lost. The Number Was: " << num << endl;
                    resetColor(); 
                }

                break;
            }

            case 2: {
                int check = 0;
                cout << "You have Five(5) chances to guess the Number!!" << endl;
                int num = 1 + (rand() % 50);
                bool won = false;
                cout << "The number has been decided, try to guess" << endl;

                while (check != 5 && !won) {
                    setColor(33); 
                    cout << "Enter your number: ";
                    resetColor(); 
                    check++;
                    int guess;
                    cin >> guess;

                    if (guess == num) {
                        setColor(32); 
                        cout << "Congratulations!!! You won!" << endl;
                        cout << "The number was " << guess << endl;
                        won = true;
                        resetColor();
                    } else {
                        setColor(31); 
                        cout << "Wrong Guess!! Number of Guesses: " << check << endl;
                        resetColor(); 
                    }
                }

                if (!won) {
                    setColor(31); 
                    cout << "Sorry, You Lost. The Number Was: " << num << endl;
                    resetColor(); 
                }

                break;
            }

            case 3: {
                int check = 0;
                cout << "You have Ten(10) chances to guess the Number!!" << endl;
                int num = 1 + (rand() % 100);
                bool won = false;
                cout << "The number has been decided, try to guess" << endl;

                while (check != 10 && !won) {
                    setColor(33); 
                    cout << "Enter your number: ";
                    resetColor(); 
                    check++;
                    int guess;
                    cin >> guess;

                    if (guess == num) {
                        setColor(32); 
                        cout << "Congratulations!!! You won!" << endl;
                        cout << "The number was " << guess << endl;
                        won = true;
                        resetColor(); 
                    } else {
                        setColor(31); 
                        cout << "Wrong Guess!! Number of Guesses: " << check << endl;
                        resetColor(); 
                    }
                }

                if (!won) {
                    setColor(31); 
                    cout << "Sorry, You Lost. The Number Was: " << num << endl;
                    resetColor(); 
                }

                break;
            }
        }

        cout << "Do you want to play more? Press 1: ";
        cin >> a;

    } while (a == 1);

    return 0;
}
