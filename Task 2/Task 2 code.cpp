#include <iostream>
#include <iomanip> 
using namespace std;


void setColor(int colorCode) {
    cout << "\033[" << colorCode << "m";
}


void resetColor() {
    cout << "\033[0m";
}

int main() {
    int a;
    do {
        setColor(36); 
        cout << "******* Simple Calculator *******" << endl;
        resetColor(); 

        float num1, num2;
        cout << "Enter the First number: ";
        cin >> num1;
        cout << "Enter the Second number: ";
        cin >> num2;

        setColor(33); 
        cout << "Enter Operation:" << endl;
        resetColor();

        cout << "  1. Addition (+)\n";
        cout << "  2. Subtraction (-)\n";
        cout << "  3. Multiplication (*)\n";
        cout << "  4. Division (/)" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                setColor(32); 
                cout << "The Solution is: " << fixed << setprecision(2) << (num1 + num2) << endl;
                resetColor();
                break;
            }
            case 2: {
                setColor(32); 
                cout << "The Solution is: " << fixed << setprecision(2) << (num1 - num2) << endl;
                resetColor(); 
                break;
            }
            case 3: {
                setColor(32); 
                cout << "The Solution is: " << fixed << setprecision(2) << (num1 * num2) << endl;
                resetColor(); 
                break;
            }
            case 4: {
                if (num2 != 0) {
                    setColor(32); 
                    cout << "The Solution is: " << fixed << setprecision(2) << (num1 / num2) << endl;
                    resetColor(); 
                } else {
                    setColor(31);
                    cout << "Error! Division by zero is not allowed." << endl;
                    resetColor();
                }
                break;
            }
            default: {
                setColor(31); 
                cout << "Error! Enter a valid operation." << endl;
                resetColor(); 
            }
        }

        setColor(36);
        cout << "Do you want to calculate more? Press 1: ";
        resetColor(); 
        cin >> a;

    } while (a == 1);

    return 0;
}
