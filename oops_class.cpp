#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    string name;
    int age;
    char gender;
    student()
    {
        cout << "Default Constructor" << endl;
        ;
    }
    student(string c, int a, char g)
    {
        cout << "Parameterised Constructor" << endl;
        ;
    }
    student(student &a)
    {
        cout << "Copy Constructor" << endl;
        ;
    }
    ~student()
    {
        cout << "Destructor Called" << endl;
    }
    void printInfo()
    {
        cout << "Name is: " << name << endl;
        cout << "Age is: " << age << endl;
        cout << "Gender is: " << gender << endl;
    }
    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    student arr[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Name: ";
        cin >> arr[i].name;
        cout << "Age: ";
        cin >> arr[i].age;
        cout << "Gender: ";
        cin >> arr[i].gender;
    }
    for (int i = 0; i <= 3; i++)
    {
        arr[i].printInfo();
    }
    student a("Anirudh", 18, 'M');
    student b;
    student c(a);
    if (c == a)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }
    return 0;
}