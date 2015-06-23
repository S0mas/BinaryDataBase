#include "Member.h"

Member::Member(string sName, string sSurname, string sBirthdate, string sMaritalStatus)
{
    setName(sName);
    setSurname(sSurname);
    setBirthdate(sBirthdate);
    setMaritalStatus(sMaritalStatus);
}//ctor

Member::Member()
{

}//ctor
Member::~Member()
{

}//dtor
void Member::showMe()
{
    for(int i = 0; i < 30; i++)
    {
        if(pProfile.name[i] == ' ')
        {
            cout<<"\t";
            break;
        }
        cout<<pProfile.name[i];
    }//Show attribute

    for(int i = 0; i < 30; i++)
    {
        if(pProfile.surname[i] == ' ')
        {
            cout<<"\t";
            break;
        }
        cout<<pProfile.surname[i];
    }

    for(int i = 0; i < 30; i++)
    {
        if(pProfile.birthdate[i] == ' ')
        {
            cout<<"\t";
            break;
        }
        cout<<pProfile.birthdate[i];
    }

    for(int i = 0; i < 30; i++)
    {
        if(pProfile.maritalStatus[i] == ' ')
        {
            cout<<"\t";
            break;
        }
        cout<<pProfile.maritalStatus[i];
    }
    cout<<endl;
    return;
}

void Member::setName(string sName)
{
    for(int i = 0; i < sName.length(); i++)
    {
        if(i>29)
        {
            cout<<"Error! Max characters limit is 30"<<endl;
            break;
        }//Checking char tabel limit
        pProfile.name[i] = sName[i];
    }//String to char table
    if(sName.length()<30)
    {
        for(int i = sName.length(); i < 30; i++)
        {
            pProfile.name[i] = ' ';
        }
    }//Fill rest of space with spaces
    return;
}//Edit attribute

void Member::setSurname(string sSurname)
{
    for(int i = 0; i < sSurname.length(); i++)
    {
        if(i>29)
        {
            cout<<"Error! Max characters limit is 30"<<endl;
            break;
        }
        pProfile.surname[i] = sSurname[i];
    }
    if(sSurname.length()<30)
    {
        for(int i = sSurname.length(); i < 30; i++)
        {
            pProfile.surname[i] = ' ';
        }
    }
    return;
}

void Member::setBirthdate(string sBirthdate)
{
    for(int i = 0; i < sBirthdate.length(); i++)
    {
        if(i>29)
        {
            cout<<"Error! Max characters limit is 30"<<endl;
            break;
        }
        pProfile.birthdate[i] = sBirthdate[i];
    }
    if(sBirthdate.length()<30)
    {
        for(int i = sBirthdate.length(); i < 30; i++)
        {
            pProfile.birthdate[i] = ' ';
        }
    }
    return;
}

void Member::setMaritalStatus(string sMaritalStatus)
{
    for(int i = 0; i < sMaritalStatus.length(); i++)
    {
        if(i>29)
        {
            cout<<"Error! Max characters limit is 30"<<endl;
            break;
        }
        pProfile.maritalStatus[i] = sMaritalStatus[i];
    }
    if(sMaritalStatus.length()<30)
    {
        for(int i = sMaritalStatus.length(); i < 30; i++)
        {
            pProfile.maritalStatus[i] = ' ';
        }
    }
    return;
}

Profile Member::getProfile()
{
    return pProfile;
}
