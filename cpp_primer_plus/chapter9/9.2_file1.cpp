/*
 * @Date: 2021-03-13 21:11:37
 * @LastEditors: lby
 */
#include <iostream>
#include "9.1_coordin.h"

using namespace std;
int main()
{
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}