#include <Arduino.h>
#include "Tokenizer.h"
#include "memoryfree.h"

void setup() {
    Serial.begin(9600);
}

Tokenizer tokenizer;

void loop() {

    Serial.println(freeMemory());

    String string = "";

    while (string.length() == 0) {
        string = Serial.readString();
    }

    tokenizer.parse(string);

    Serial.println("Tokens:");
    for (int i = 0; i < tokenizer.length(); i++) {
        Serial.print(*((String *) tokenizer[i]));
        Serial.print("` `");
    }

    Serial.print("You write: `");
    Serial.print(string);
    Serial.println("`");

    tokenizer.clear();
}