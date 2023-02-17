//
// Created by belicfr on 17/02/2023.
//

#ifndef INC_8BITS_ASM_PROMPT_H
#define INC_8BITS_ASM_PROMPT_H

#include <iostream>
#include "Assembly.h"
using namespace std;

class Prompt {
public:
    static void begin() {
        string line;

        do {
            cout << "$ > ";
            cin >> line;

            Assembly asmInstance = *new Assembly(line);

            asmInstance.understand();
        } while (line != "EXIT");
    };
};

#endif //INC_8BITS_ASM_PROMPT_H
