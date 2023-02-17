//
// Created by Jonathan on 17/02/2023.
//

#ifndef INC_8BITS_ASM_PROCESSOR_H
#define INC_8BITS_ASM_PROCESSOR_H

#include <vector>
#include <string>
using namespace std;

class Processor {
public:
    const int BITS_COUNT = 8;  /// Bits max count in 1 unit. (default: 8).
    const int REGISTER_NAME_MAX_LENGTH = 1;  /// Register name max length (default: 1).
    const int MEMORY_ADDRESSES_MIN_VALUE = 1;  /// Memory addresses min value (default: 1).
    const int MEMORY_ADDRESSES_MAX_VALUE = 127; /// Memory addresses max value (default: 127).

    const string REGISTER_A_NAME = "A";  /// "A" register name.
    const string REGISTER_B_NAME = "B";  /// "B" register name.
    const string REGISTER_C_NAME = "C";  /// "C" register name.

    // REGISTERS ////////////////////////////////

    int reg_A[8];  /// "A" 8 bits register.
    int reg_B[8];  /// "B" 8 bits register.
    int reg_C[8];  /// "C" 8 bits register.

    // MEMORIES /////////////////////////////////
    // There are 128 memories, each one has 8 bits to store
    // information.

    int memories[128][8];  /// 8 bits Memory sets (there are 128 sets).

    // METHODS //////////////////////////////////

    /**
     * Stores 8 bits encoded information in a register.
     * @param destination register name
     * @param bits encoded information to store
     * @return action state
     */
    bool storeInRegister(char destination, vector<int> bits) {
        for (int bitPosition = 0; bitPosition < BITS_COUNT; bitPosition++) {
            switch (destination) {
                case 'A':
                    reg_A[bitPosition] = bits[bitPosition];
                    break;

                case 'B':
                    reg_B[bitPosition] = bits[bitPosition];
                    break;

                case 'C':
                    reg_C[bitPosition] = bits[bitPosition];
                    break;

                default:
                    return false;
            }
        }

        return true;
    };

    /**
     * Stores 8 bits encoded information in a memory allocation.
     * @param memoryIndex memory allocation index (0 to 127)
     * @param origin register name
     * @return action state
     */
    bool storeInMemory(int memoryIndex, char origin) {
        for (int bitPosition = 0; bitPosition < BITS_COUNT; bitPosition++) {
            switch (origin) {
                case 'A':
                    memories[memoryIndex][bitPosition] = reg_A[bitPosition];
                    break;

                case 'B':
                    memories[memoryIndex][bitPosition] = reg_B[bitPosition];
                    break;

                case 'C':
                    memories[memoryIndex][bitPosition] = reg_C[bitPosition];
                    break;

                default:
                    return false;
            }
        }

        return true;
    };

    /**
     * Returns if given string is a register name or not.
     * @param value given string to test
     * @return if given string is a register name or not
     */
    bool isRegisterName(const string& value) {
        return value.length() == REGISTER_NAME_MAX_LENGTH
            && (value == REGISTER_A_NAME
                || value == REGISTER_B_NAME
                || value == REGISTER_C_NAME);
    };

    /**
     * Returns if given string is a memory address or not.
     * @param value given string to test
     * @return if given string is a memory address or not
     */
    bool isMemoryAddress(const string& value) {
        bool state;

        int convertedValue;

        state = true;
        convertedValue = 0;

        try {
            convertedValue = (int) value; // FIXME: fix string to integer conversion.
        } catch (...) {
            state = false;
        }

        return state
            && convertedValue >= MEMORY_ADDRESSES_MIN_VALUE
            && convertedValue <= MEMORY_ADDRESSES_MAX_VALUE;
    };
};

#endif //INC_8BITS_ASM_PROCESSOR_H

// TODO: unit test for class methods.