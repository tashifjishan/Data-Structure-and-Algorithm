#include<iostream>
#include<sstream>
using namespace std;

// Helper: check operator precedence
int precedence(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

int main() {
    string expression = "( ( 2 * 4 ) / 2 ) + 4";
    stringstream ss(expression);
    string token;

    string output;
    string arr[100]; // stack for operators
    int stackPos = 0;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop operators with >= precedence
            while (stackPos > 0 &&
                   arr[stackPos - 1] != "(" &&
                   precedence(arr[stackPos - 1]) >= precedence(token)) {
                output.append(arr[--stackPos] + " ");
            }
            arr[stackPos++] = token;
        }
        else if (token == "(") {
            arr[stackPos++] = token;
        }
        else if (token == ")") {
            // Pop until "("
            while (stackPos > 0 && arr[stackPos - 1] != "(") {
                output.append(arr[--stackPos] + " ");
            }
            if (stackPos > 0 && arr[stackPos - 1] == "(") {
                stackPos--; // Discard "("
            }
        }
        else {
            // Operand
            output.append(token + " ");
        }
    }

    // Pop remaining operators
    while (stackPos > 0) {
        output.append(arr[--stackPos] + " ");
    }

    cout << "Postfix: " << output << endl;
    return 0;
}
