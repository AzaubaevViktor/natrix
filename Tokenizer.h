//
// Created by ktulhy on 02.01.16.
//

#ifndef NATRIX_TOKENIZER_H
#define NATRIX_TOKENIZER_H

#include "Array.h"
#include "WString.h"

class Tokenizer {
public:
    Tokenizer();
    ~Tokenizer();
    void parse(String &s);
    void clear();
    void *operator[](unsigned int index);
    unsigned int length();
private:
    Array *tokens;
};


#endif //NATRIX_TOKENIZER_H
