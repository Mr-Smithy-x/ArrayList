#include <iostream>
#include <string>
#include "utils/ArrayList.hpp"
using namespace std;

struct Obj
{
    int id;
    string desc;
    int effect;
};const Obj EMPTY = {NULL,"EMPTY",NULL};

int main(){
    Obj Tobj = {1,"Yes",35};
    Obj Tobj2 = {6,"Hot",35};
    Obj Tobj3 = {9,"Noob",35};
    ArrayList<Obj> item;
    if(!item.pop_back()) cout<<"Unable to pop back. Size is empty" << endl;
    item.push_back(Tobj);
    item.push_back(Tobj2);
    item.push_back(Tobj3);

    cout << "size: " << item.getSize() << endl;
    for(int i = 0; i < item.getSize(); i++){
        cout << item.at(i)->id << "\t"  << item[i]->desc << endl;
    }
    cout << endl;
    item.remove(1);
    for(int i = 0; i < item.getSize(); i++){
        cout << item[i]->id << "\t"  << item[i]->desc << endl;
    }
    cout <<endl;
    item.insert(1, Tobj2);
    for(int i = 0; i < item.getSize(); i++){
        cout << item.at(i)->id << "\t"  << item.at(i)->desc << endl;
    }

    cout <<endl;
    item.pop_back();

    for(int i = 0; i < item.getSize(); i++){
        cout << item.at(i)->id << "\t"  << item.at(i)->desc << endl;
    }


    cout <<endl;
    item.insert(3, Tobj3);
    for(int i = 0; i < item.getSize(); i++){
        
        cout << "I: " << i << " - ";
        cout << item.at(i)->id << "\t"  << item.at(i)->desc << endl;

    }


    return 0;
}




