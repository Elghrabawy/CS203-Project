//
// Created by hima1 on 5/16/2024.
//

#include "Global.h"

int getIntRange(int low, int high)
{
    int value;
    cin >> value;

    if (value >= low && value <= high) {
        return value;
    }
    else {
        cout << ">> Invalid Input..\n\n";
        return -1;
//        return getIntRange(low, high);
    }
    return 0;
}

void header(string s, string color){
    cout << endl;
    cout << color;
    to_upper(s);
    cout << "                 ";
    cout << "+" << string(42, '-') << "+" << endl;
    cout << "                 ";
    cout << "|" << printAlign(s, CENTER, 42) << "|" << endl;
    cout << "                 ";
    cout << "+" << string(42, '-') << "+" << endl;
    cout << endl << endl;
    cout << "\033[0m";

}

int readMenu(vector<string> menu, string s, string color)
{
    cout << color;
    to_upper(s);
    cout << "                 ";
    cout << "+" << string(42, '-') << "+" << endl;

    cout << "                 ";
    cout << "|" << printAlign(s, CENTER, 42) << "|" << endl;

    cout << "                 ";
    cout << "+" << string(42, '-') << "+" << endl;

    for (int ch = 0; ch < (int)menu.size(); ch++) {
        string p = to_string(ch + 1)  + " : " + menu[ch];
        cout << "                 ";
        cout << "|" << printAlign(p, LEFT, 42) << "|" << endl;
    }

    cout << "                 ";
    if(menu.size() > 0)
        cout << "+" << string(42, '-') << "+" << endl;
    cout << "\033[0m";
    cout << endl;

    cout << "choose option : ";
    return getIntRange(1, (int)menu.size());
}
int readMenu2(vector<string> menu, string text) {
    cout << text << endl;
    for (int ch = 0; ch < (int)menu.size(); ch++) {
        cout << ch + 1 << ". " << menu[ch] << endl;
    }
    cout << endl;

    cout << ": ";
    return getIntRange(1, (int)menu.size());
}

void to_lower(string& s)
{
    for (auto& c : s)
        c = tolower(c);
}
void to_upper(string& s)
{
    for (auto& c : s)
        c = toupper(c);
}

bool isContinue()
{
    cout << "Do you want continue? (y/n) : ";

    string inp;
    cin >> inp;

    to_lower(inp);

    if (inp == "y" || inp == "yes") {
        return true;
    }
    else if (inp == "n" || inp == "no") {
        return false;
    }
    else {
        cout << ">> Invalid Input.. please try again!\n\n";
        return isContinue();
    }
}

string printAlign(string input, Position pos, int width) {
    int spaces = 0; // left
    int spaces_aft = 0; // right
    switch (pos) {
        case CENTER:
            spaces = (width - input.length()) / 2;
            spaces_aft = spaces;
            if (input.size() + spaces + spaces_aft < width) spaces_aft++;
            break;
        case RIGHT:
            spaces = (width - input.length());
            break;
        case LEFT:
            spaces_aft = (width - input.length());
            break;
    }
    return string(spaces, ' ') + input + string(spaces_aft, ' ');
}

string colored(string s, string color) {
    return (color + s + "\033[0m");
}

void tableHeader(vector<string> headers, int width, int startSpaces) {
    cout << string(startSpaces, ' ');
    for(int i = 0; i < headers.size(); i++)
        cout << "+" << string(width, '-');
    cout << "+" << endl;

    cout << string(startSpaces, ' ');
    for(int i = 0; i < headers.size(); i++)
        cout << "|" << printAlign(headers[i], CENTER, width);
    cout << "|" << endl;

    cout << string(startSpaces, ' ');
    for(int i = 0; i < headers.size(); i++)
        cout << "+" << string(width, '-');
    cout << "+" << endl;
}

void tableData(vector<string> content, int width, int startSpaces) {
    cout << string(startSpaces, ' ');
    for(int i = 0; i < content.size(); i++)
        cout << "|" << printAlign(content[i], CENTER, width);
    cout << "|" << endl;
}

void tableFooter(int colNumbers, int width, int startSpaces) {
    cout << string(startSpaces, ' ');
    for(int i = 0; i < colNumbers; i++)
        cout << "+" << string(width, '-');
    cout << "+" << endl;
}

void _exit() {
    cout << colored("Exit", "\033[1;31m") << endl;
    for(int i = 0; i < 3; i++) {
        usleep(100 * 1000);;
        cout << colored(".", "\033[1;31m");
    }
    usleep(100 * 1000);
}



