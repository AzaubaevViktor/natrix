//
// Created by ktulhy on 02.01.16.
//

#include "Tokenizer.h"

String addableSymbols = "()[]+-/*%=,;";
String hideSymbols = " ";

Tokenizer::Tokenizer() {
    tokens = new Array();
}

Tokenizer::~Tokenizer() {
    clear();
    delete tokens;
}

void* Tokenizer::operator[](unsigned int index) {
    return (*tokens)[index];
}

unsigned int Tokenizer::length() {
    return tokens->length();
}

void Tokenizer::clear() {
    String *string = NULL;
    while (NULL != (string = (String *) tokens->pop())) {
        Serial.print("Detele `");
        Serial.print(*string);
        Serial.println("`");
        delete string;
    }

    tokens->squeeze();
}

void Tokenizer::parse(String &s) {
    size_t start = 0;
    size_t end = 0;

    for (end = 0; end < s.length(); end++) {
        char ch = s[end];
        Serial.print(start);
        Serial.print(", ");
        Serial.println(end);
        Serial.print(">");
        Serial.print(s.substring(start, end));
        Serial.println("<");

        int asIndex = addableSymbols.indexOf(ch);
        Serial.println(asIndex);
        if (-1 != asIndex) {
            if (start != end) {
                String *string = new String();
                *string = s.substring(start, end);
                Serial.println(*string);
                tokens->append(string);
            }
            start = end + 1;
            String *token = new String(addableSymbols[asIndex]);
            tokens->append(token);
            continue;
        }

        int hsIndex = hideSymbols.indexOf(ch);
        Serial.println(hsIndex);
        if (-1 != hsIndex) {
            if (start != end) {
                String *string = new String;
                *string = s.substring(start, end);
                Serial.println(*string);
                tokens->append(string);
            }
            start = end + 1;
            continue;
        }
    }

    if (end >= start) {
        String *string = new String(s.substring(start, end));
        Serial.println(*string);
        tokens->append(string);
    }
}