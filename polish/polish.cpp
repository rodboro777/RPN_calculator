#include <iostream>
#include <stack>
#include "RPNCalculator.h"
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;


class Shell {
private:
    // boolenan method to check if user input is numeric 
    // returns true only if there are no logical errors in I/O operation and end of file errors
    bool is_numeric(std::string const& str)
    {
        auto result = double();
        auto i = std::istringstream(str);

        i >> result;

        return !i.fail() && i.eof();
    }
public:
    void start() {

        // output stream
        ofstream out;
        out.open("RPN.log");


        //Calculator isntance
        RPNCalculator<double> calc;


        while (true) {
            if (calc.isEmpty()) {
                cout << "X > ";
            }
            else {
                cout << calc.value() << " > ";
            }
            string s;
            cin >> s;
            if (s == "c") {
                out << "clear ";
                calc.clear();
            }
            else if (s == "s") {
                out << "square ";
                calc.square();
            }
            else if (s == "n") {
                out << "negate ";
                calc.negate();
            }
            else if (s == "p") {
                out << "pop ";
                calc.pop();
            }
            else if (s == "q") {
                out << "quit ";
                break;
            }
            else if (s == "+") {
                out << "+ ";
                calc.add();
            }
            else if (s == "-") {
                out << "- ";
                calc.subtract();
            }
            else if (s == "*") {
                out << "* ";
                calc.multiply();
            }
            else if (s == "/") {
                out << "/ ";
                calc.divide();
            }
            else if (is_numeric(s)) {
                double num = atof(s.c_str());
                out << num << " ";
                calc.push(num);
            }
            else {
                cout << "invalid input\n";
            }
            //flush the log to a file
            out.flush();
        }
        out.close();
    }
};

int main()
{
    cout << "Enter c to clear the stack\n";
    cout << "s to square\n";
    cout << "n to negate\n";
    cout << "p to pop current value\n";
    cout << "q to quit\n";

    cout << endl;

    
    Shell shell;
    shell.start();
    return 0;
}
