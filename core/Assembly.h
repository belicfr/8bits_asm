//
// Created by belicfr on 17/02/2023.
//

#ifndef INC_8BITS_ASM_ASSEMBLY_H
#define INC_8BITS_ASM_ASSEMBLY_H

#include <string>
#include <iostream>
#include <vector>
#include "Processor.h"
using namespace std;

class Assembly {
public:
    explicit Assembly(string line)
        : understandingLine(line)
    {};

    void understand() {
        Processor processorInstance = *new Processor();

        cout << processorInstance.isRegisterName(understandingLine);
    }

private:
    string understandingLine;
};

#endif //INC_8BITS_ASM_ASSEMBLY_H
