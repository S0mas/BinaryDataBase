#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

using namespace std;

struct Profile
{
    char name[30];
    char surname[30];
    char birthdate[30];
    char maritalStatus[30];
};

class Member
{
    friend class Dane;
    private:
        Profile pProfile{"","","",""};
    public:
        Member();
        Member(string sName, string sSurname, string sBirthdate, string sMaritalStatus);
        virtual ~Member();
        void showMe();
        void setName(string sName);
        void setSurname(string sSurname);
        void setBirthdate(string sBirthdate);
        void setMaritalStatus(string sMaritalStatus);
        Profile getProfile();
};

#endif // MEMBER_H
