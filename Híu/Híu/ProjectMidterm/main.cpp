#include"HIstory.h"

int main()
{
    cout << "Enter the number of users: "; 
    int n; 
    cin >> n;

    User* user = new User[n];

    for (int i = 0; i < n; ++i) {
        cout << "#" << i + 1 << endl;
        user[i].input();
        
    }
        
    cout << endl << endl << "Output" << endl << endl;

    for (int i = 0; i < n; ++i)
    {
        user[i].output();
        cout << endl << "------------------" << endl << endl;
    }
    History p;
    p.print();
    //p.getName();
   //p.print();

    return 0;
}