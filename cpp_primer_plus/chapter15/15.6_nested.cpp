#include <iostream>
#include <string>
#include "15.5_queuetp.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::string;
    QueueTP<string> cs(5);
    string temp;
    while (!cs.isfull())
    {
        cout << "Please enter your name. You will be "
                "served in the order of arrival.\n"
                "name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing begins!\n";
    while (!cs.isempty())
    {
        cs.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
    return 0;
}