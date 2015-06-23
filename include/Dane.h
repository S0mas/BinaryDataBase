#ifndef DANE_H
#define DANE_H

#include <fstream>

class Member;

class Dane
{
    public:
        Dane();
        virtual ~Dane();
        void addMember();
        void addMember(Member &rOsoba);
        void editMember();
        void deleteMember();
        void showMembers();
        void error();
        void saveFile();
        void openFile();
    protected:
    private:
    Member** table;
    int numberOfSlots;//number of max records(10)
    int iSlot;//Position pointer
};

#endif // DANE_H
