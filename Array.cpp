//
// Created by ktulhy on 02.01.16.
//

#include "Array.h"
Array::Array() {
    _length = 0;
    dataLength = CHUNK_SIZE;
    data = (void **) malloc(dataLength * sizeof(void *));
}

void Array::append(void *ptr) {
    if (_length == dataLength) {
        rebuild();
    }

    data[_length] = ptr;
    _length++;
}

void Array::rebuild() {
    dataLength += CHUNK_SIZE;
    data = (void **) realloc(data, dataLength * sizeof(void *));
}

void Array::squeeze() {
    Serial.print("New dataLength:");
    dataLength = (_length / CHUNK_SIZE) * CHUNK_SIZE; // + CHUNK_SIZE
    Serial.println(dataLength);
    rebuild(); // Этот лишний чанк реализуется здесь
}

void *Array::operator[](unsigned int index) {
    if (index < _length) {
        return data[index];
    } else {
        return NULL;
    }
}

void Array::clear() {
    for (int i = 0; i < _length; i++) {
        delete data[i];
    }
    _length = 0;
}

void *Array::pop() {
    if (0 == _length)
        return NULL;

    _length--;
    return data[_length];
}

unsigned int Array::length() {
    return _length;
}

Array::~Array() {
    clear();
    free(data);
}