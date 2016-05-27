//
// Created by cj on 5/27/16.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H


template<class type>
class ArrayList {
private:
    type *items;
    int size;
public:
    ~ArrayList() {
        delete[] items;
    }

    ArrayList() {
        size = 0;
    }

    type *operator[](int index) {
        return items + index;
    }

    type *at(int index) const {
        return items + index;
    }

    int getSize() const {
        return size;
    }

    type *front() {
        return items;
    }

    type *back() {
        return items + (getSize() - 1);
    }

    bool isEmpty() {
        return size == 0;
    }

    bool pop_back() {
        return remove(size - 1);
    }

    void clear() {
        delete[] items;
        size = 0;
    }

    void insert(int index, type &item) {
        if (index > size) {
            int oldsize = size;
            size = index + 1;
            int insertPos = 0;
            type *newItems = new type[size];
            for (int i = 0; i < size; i++) {
                if (i == index) {
                    newItems[i] = item;
                    insertPos++;
                    continue;
                }
                if(i-insertPos < oldsize) {
                    newItems[i] = items[i - insertPos];
                }
            }
            if (size - 1 > 0)
                delete[] items;                    //destroy everything in here
            items = new type[size];            //reset with new size
            for (int i = 0; i < size; i++)
                items[i] = newItems[i];
            delete[] newItems;

        }
        else if (index == size) {
            push_back(item);
            return;
        }else {
            int insertPos = 0;
            size++;
            type *newItems = new type[size];
            for (int i = 0; i < size; i++) {
                if (i == index) {
                    newItems[i] = item;
                    insertPos++;
                    continue;
                }
                newItems[i] = items[i - insertPos];
            }
            if (size - 1 > 0)
                delete[] items;                    //destroy everything in here
            items = new type[size];            //reset with new size
            for (int i = 0; i < size; i++)
                items[i] = newItems[i];
            delete[] newItems;
        }
    }


    bool remove(int index) {
        if (0 < index < size) {
            int skipped = 0;
            type *newItems = new type[size - 1];
            for (int i = 0; i < size; i++) {
                if (i == index) {
                    skipped++;
                    continue;
                }
                newItems[i - skipped] = items[i];
            }
            if (size - 1 > 0)
                delete[] items;
            items = new type[size - 1];
            for (int i = 0; i < size - 1; i++)
                items[i] = newItems[i];
            delete[] newItems;
            size--;
            return true;
        } else {
            return false;
        }
    }

    void push_back(type &item) {
        size++;
        type *newItems = new type[size];
        for (int i = 0; i < size - 1; i++)    //old backpack size
            newItems[i] = items[i];
        newItems[size - 1] = item;
        if (size - 1 > 0)
            delete[] items;                    //destroy everything in here
        items = new type[size];            //reset with new size
        for (int i = 0; i < size; i++)
            items[i] = newItems[i];
        delete[] newItems;
    }
};

#endif //ARRAYLIST_SVEC_H
