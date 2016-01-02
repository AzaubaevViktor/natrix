//
// Created by ktulhy on 02.01.16.
//

#ifndef NATRIX_ARRAY_H
#define NATRIX_ARRAY_H

#define CHUNK_SIZE (4)

#include "Arduino.h"

class Array {
public:
    Array();
    ~Array();
    void append(void *ptr);
    void clear();
    void *pop();
    void squeeze();

    unsigned int length();
    void *operator[](unsigned int index);
private:
    void rebuild();

    unsigned int _length;
    unsigned int dataLength;
    void **data;
};


#endif //NATRIX_ARRAY_H
