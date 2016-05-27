#include <iostream>
#include "utils/ArrayList.hpp"
using namespace std;

struct Person
{
    int id;
    string name;
    int age;
};const Person EMPTY = {NULL,"EMPTY",NULL};

int main(){
    Person Tobj = {1,"Jon Snow",24};
    Person Tobj2 = {6,"Aria Stark",16};
    Person Tobj3 = {9,"Daenerys Targaryen",24};
    ArrayList<Person> item;
    if(!item.pop_back()) cout<<"Unable to pop back. Size is empty" << endl;
    item.push_back(Tobj);
    item.push_back(Tobj2);
    item.push_back(Tobj3);
    cout << "size: " << item.getSize() << endl;
    for(int i = 0; i < item.getSize(); i++){
        cout << item.at(i)->id << "\t"  << item[i]->name << endl;
    }
    cout << endl;
    item.remove(1);
    for(int i = 0; i < item.getSize(); i++){
        cout << item[i]->id << "\t"  << item[i]->name << endl;
    }
    cout <<endl;
    item.insert(1, Tobj2);
    for(int i = 0; i < item.getSize(); i++){
        cout << item.at(i)->id << "\t"  << item.at(i)->name << endl;
    }
    cout <<endl;
    item.pop_back();
    for(int i = 0; i < item.getSize(); i++){
        cout << item.at(i)->id << "\t"  << item.at(i)->name << endl;
    }
    cout <<endl;
    item.insert(3, Tobj3);
    for(int i = 0; i < item.getSize(); i++){
        cout << "I: " << i << " - ";
        cout << item.at(i)->id << "\t"  << item.at(i)->name << endl;
    }
    return 0;
}




