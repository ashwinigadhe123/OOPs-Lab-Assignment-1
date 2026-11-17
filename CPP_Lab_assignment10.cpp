#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
    string source;
    string destination = "Old Text";

    cout << "Enter a message: ";
    getline(cin, source);

    cout << "\nBefore Move:" << endl;
    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;

    destination = std::move(source);

    cout << "\nAfter Move:" << endl;
    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;

    source = "New Value";

    cout << "\nSource after assigning new value: ";
    cout << source << endl;

    return 0;
}
