#include "Dane.h"
#include "Member.h"

Dane::Dane()
{
    iSlot = 0;
    numberOfSlots = 10;
    table = new Member* [numberOfSlots];
    for(int i = 0; i<10; i++)
    {
        table[i] = new Member;
    }
    //ctor
}

Dane::~Dane()
{
    //dtor
}

void Dane::addMember()
{
        string sTemp;
        cout<<"Input name: \n";
        while(!(cin>>sTemp))
        {
            error();
        }
        table[iSlot%10]->setName(sTemp);

        cout<<"Input surname: \n";
        while(!(cin>>sTemp))
        {
            error();
        }
        table[iSlot%10]->setSurname(sTemp);

        cout<<"Input birthdate: \n";
        while(!(cin>>sTemp))
        {
            error();
        }
        table[iSlot%10]->setBirthdate(sTemp);

        cout<<"Input marital status: \n";
        while(!(cin>>sTemp))
        {
            error();
        }
        table[iSlot%10]->setMaritalStatus(sTemp);
        iSlot++;
        return;
}//Add record(via console)

void Dane::addMember(Member &rOsoba)
{
    if(iSlot>=10)
    {
        delete table[iSlot%10];
        table[iSlot%10] = 0;
    }
    table[iSlot%10] = &rOsoba;
    iSlot++;
    return;
}//Add record (not in console)

void Dane::editMember()
{
    int i, j;
    string sTemp;
    cout<<"Select record(0 - 9)"<<endl;
    while(!(cin>>i)||i>9||i<0)
    {
        error();
    }
    cout<<"Select attribute:\n 1 - Name\n 2 - Surname\n 3 - Birthdate\n 4 - Marital status\n 5 - Main menu\n";
    while(!(cin>>j)||j>5||j<1)
    {
        error();
    }
    if(j==1||j==2||j==3||j==4)
    {
        cout<<"Input new value: \n";
        while(!(cin>>sTemp))
        {
            error();
        }
    }
    switch (j)
    {
        case 1:
            table[i]->setName(sTemp);
            break;
        case 2:
            table[i]->setSurname(sTemp);
            break;
        case 3:
            table[i]->setBirthdate(sTemp);
            break;
        case 4:
            table[i]->setMaritalStatus(sTemp);
            break;
        default:
            break;
    }
    return;
}//Edit attribute

void Dane::error()
{
    cout<<"Error! Wrong value.\n";
}


void Dane::deleteMember()
{
    int i;
    cout<<"Select record to delete(0 - 9)"<<endl;
    while(!(cin>>i)||i>9||i<0)
    {
        error();
    }
    delete table[i];
    table[i] = new Member;
    return;
}//Delete choosen record

void Dane::showMembers()
{
    for(int i = 0; i < 10; i++)
    {
        cout<<i<<". ";
        table[i]->showMe();
    }
    return;
}//Show date

void Dane::saveFile()
{
    int i;
    fstream file;
    file.open("directory", ios::out | ios::in | ios::binary);
    if (file.good() == false)
    {
        cout<<"Error! Check file directory.\n";
        return;
    }
    cout<<"Succes\n";
    for(int i = 0; i < 10; i++)
    {
        file.write((char*)&table[i]->pProfile, sizeof(table[i]->getProfile()));
    }//Save date from table to bin. file.
    file.close();
    return;
}

void Dane::openFile()
{
    fstream file;
    file.open("directory",ios::in | ios::out | ios::binary);
    if (file.good() == false)
    {
        cout<<"Error! Check file directory.\n";
        return;
    }
    cout<<"Succes\n";
    for(int i = 0; i < 10; i++)
    {
        file.read((char*)&table[i]->pProfile, sizeof(table[i]->getProfile()));
    }//Load date from bin. file.
    file.close();
    return;
}
