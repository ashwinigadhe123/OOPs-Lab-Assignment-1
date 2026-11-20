#include <iostream>
using namespace std;
 
class Shape
{
public:
    virtual void show()
    {
        cout << "This is a Shape." << endl;
    }
 
    virtual ~Shape()
    {
    }
};
 
class Circle : public Shape
{
public:
    void show()
    {
        cout << "This is a Circle." << endl;
    }
 
    void circleOnly()
    {
        cout << "Circle-only function called." << endl;
    }
};
 
class Square : public Shape
{
public:
    void show()
    {
        cout << "This is a Square." << endl;
    }
};
 
// A function that takes a non-const pointer but only reads the value
void showValue(int *p)
{
    cout << "Value read after const_cast: " << *p << endl;
}
 
int main()
{
    int num;
    double value;
 
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Enter a decimal number: ";
    cin >> value;
 
    cout << "\n--- Implicit Type Casting ---" << endl;
    double d = num;
    cout << "Integer num = " << num << endl;
    cout << "After conversion to double: d = " << d << endl;
    cout << "d / 2 = " << d / 2 << endl;
    cout << "num + value = " << num + value << endl;
 
    cout << "\n--- Explicit Type Casting ---" << endl;
    int a = (int)value;
    int b = static_cast<int>(value);
    cout << "C-style cast: (int)value = " << a << endl;
    cout << "static_cast: static_cast<int>(value) = " << b << endl;
    cout << "Without cast: num / 2 = " << num / 2 << endl;
    cout << "With static_cast: static_cast<double>(num) / 2 = "
         << static_cast<double>(num) / 2 << endl;
 
    cout << "\n--- dynamic_cast ---" << endl;
    Circle circle;
    Shape *ptr = &circle;
 
    Circle *c = dynamic_cast<Circle *>(ptr);
    if (c != NULL)
    {
        cout << "Cast to Circle* successful." << endl;
        c->circleOnly();
    }
 
    Square *s = dynamic_cast<Square *>(ptr);
    if (s == NULL)
    {
        cout << "Cast to Square* failed. ptr does not point to a Square." << endl;
    }
 
    cout << "\n--- const_cast ---" << endl;
    int x = num;
    const int *cp = &x;
    showValue(const_cast<int *>(cp));
    int *p = const_cast<int *>(cp);
    *p = *p + 10;
    cout << "Value of x after change through the non-const pointer: " << x << endl;
 
    cout << "\n--- reinterpret_cast ---" << endl;
    int n = num;
    int *ip = &n;
    char *chp = reinterpret_cast<char *>(ip);
    int *back = reinterpret_cast<int *>(chp);
    cout << "Pointer converted to char* and back to int*." << endl;
    cout << "Value: " << *back << endl;
    if (back == ip)
    {
        cout << "Both pointers hold the same address: Yes" << endl;
    }
    else
    {
        cout << "Both pointers hold the same address: No" << endl;
    }
 
    return 0;
}
