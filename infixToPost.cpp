#include<iostream>
#include<sstream>
using namespace std;

int main() {
    string expression = "( ( 2 * 4 ) / 2 ) + 4";
    stringstream ss(expression);
    string token;

    string output;
    string arr[100]; // stack for operators
    int stackPos = 0;

    while (ss >> token) {
        if (token == "+" || token == "-") {
            for (int i = stackPos - 1; i >= 0 && arr[i] != "("; i--) {
                output.append(arr[--stackPos] + " ");
            }
            arr[stackPos++] = token;

        } else if (token == "*" || token == "/") {
            for (int i = stackPos - 1;
                 i >= 0 && arr[i] != "(" && arr[i] != "-" && arr[i] != "+";
                 i--) {
                output.append(arr[--stackPos] + " ");
            }
            arr[stackPos++] = token;

        } else if (token == "(") {
            arr[stackPos++] = token;

        } else if (token == ")") {
            // Pop until you find "("
            while (stackPos > 0 && arr[stackPos - 1] != "(") {
                output.append(arr[--stackPos] + " ");
            }
            if (stackPos > 0 && arr[stackPos - 1] == "(") {
                stackPos--; // discard "("
            }

        } else {
            // Operand
            output.append(token + " ");
        }
    }

    // Pop any remaining operators
    while (stackPos > 0) {
        output.append(arr[--stackPos] + " ");
    }

    cout << "Postfix: " << output << endl;
    return 0;
}
