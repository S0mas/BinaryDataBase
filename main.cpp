#include <iostream>
#include "Member.h"
#include "Dane.h"

using namespace std;

void menu()
{
    cout<<"1 - Add member\n2 - Edit record\n3 - Delete recorde\n4 - Show members\n";
    cout<<"5 - Save to file(BIN)\n6 - Open from file(BIN)\n7 - Exit\n";
    return;
}

int main()
{
    int i;
    bool exit = false;
    Dane dMy;
/////////////////////////////////////////////////////////////////////////////
    while(exit == false)
    {
        menu();
        cin>>i;
        switch (i)
        {
            case 1:
                dMy.addMember();
                break;
            case 2:
                dMy.editMember();
                break;
            case 3:
                dMy.deleteMember();
                break;
            case 4:
                dMy.showMembers();
                break;
            case 5:
                dMy.saveFile();
                break;
            case 6:
                dMy.openFile();
                break;
            case 7:
                exit = true;
                break;
            default:
                cout<<"Error\n";
                break;
        }
    }
    return 0;
}
