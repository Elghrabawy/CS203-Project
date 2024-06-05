//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_GLOBAL_H
#define OOP_PROJECT_GLOBAL_H

#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>
#include <cmath>

using namespace std;


class Colors{
public:
    static string red;
    static string green;
    static string yellow;
    static string blue;
    static string magenta;
    static string cyan;
    static string white;
    static string reset;
    static string bold;
    static string underline;
    static string blink;
    static string reverse;
    static string invisible;

};

/**
 * Function to get an integer within a specified range.
 * If the input is not within the range, the function will recursively ask for input until a valid one is provided.
 * @param low - The lower bound of the range.
 * @param high - The upper bound of the range.
 * @return - The valid input integer.
 */
int getIntRange(int low, int high);

/**
 * Function to read a menu and return the selected option.
 * @param menu - The vector of strings representing the menu options.
 * @param s - The string to be printed in the header.
 * @param color - The color of the header.
 * @return - The selected option.
 */
int readMenu(vector <string> menu, string text, string color = "\033[1;36m");
int readMenu2(vector <string> menu, string text);

/**
 * Function to print a header with a specified string and color.
 * @param s - The string to be printed in the header.
 * @param color - The color of the header.
 */
void header(string s, string color = "\033[1;36m");

/**
 * Function to print a string with a specified color.
 * @param s - The string to be printed.
 * @param color - The color of the string.
 * @return - The colored string.
 */
string colored(string s, string color);

/**
 * Function to convert a string to lowercase.
 * @param s - The string to be converted.
 */
void to_lower(string& s);

/**
 * Function to convert a string to uppercase.
 * @param s - The string to be converted.
 */
void to_upper(string& s);

/**
 * Function to ask the user if they want to continue.
 * @return - True if the user wants to continue, false otherwise.
 */
bool isContinue();

/**
 * Function to pause the screen.
 */
void pauseScreen();

enum Position {LEFT, CENTER, RIGHT};
/**
 * Function to print a string aligned in a specified position within a specified width.
 * @param input - The string to be printed.
 * @param pos - The position of the string (LEFT, CENTER, RIGHT).
 * @param width - The width of the space in which the string will be printed.
 * @return - The string with the appropriate spaces before and after it.
 */
string printAlign(string input, Position pos, int width);

/**
 * Function to print a table header.
 * @param headers - The vector of strings representing the headers.
 * @param width - The width of each column.
 * @param startSpaces - The number of spaces before the table.
 */
void tableHeader(vector<string> headers, int width = 15, int startSpaces = 20);
void tableHeader(vector<pair<string, int>> headers, int startSpaces = 20);
/**
 * Function to print a row of table data.
 * @param content - The vector of strings representing the content of the row.
 * @param width - The width of each column.
 * @param startSpaces - The number of spaces before the table.
 */
void tableData(vector<string> content, int width = 15, int startSpaces = 20);
void tableData(vector<pair<string, int>> content, int startSpaces = 20);
/**
 * Function to print a table footer.
 * @param colNumbers - The number of columns in the table.
 * @param width - The width of each column.
 * @param startSpaces - The number of spaces before the table.
 */
void tableFooter(int colNumbers, int width = 15, int startSpaces = 20);
void tableFooter(vector<int> colsSize, int startSpaces = 20);

/**
 * Function to clear the screen.
 */
void clearScreen();


#endif //OOP_PROJECT_GLOBAL_H