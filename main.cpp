#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <map>
#include <sstream>

enum class Command
{
    Increment_DP,   // >    Increment the data pointer (to point to the next cell to the right).
    Decrement_DP,   // <    Decrement the data pointer (to point to the next cell to the left).

    Increment_VAL,  // +    Increment (increase by one) the byte at the data pointer.
    Decrement_VAL,  // -    decrement (decrease by one) the byte at the data pointer.

    Put_Char,        // .    Print out the character
    Get_Char,        // ,    Get one char/ byte of input

    Begin_While,     // [
    End_While,       // ]
};

std::map<char, Command> charToCommand
{
    { '>', Command::Increment_DP },
    { '<', Command::Decrement_DP },

    { '+', Command::Decrement_DP },
    { '-', Command::Decrement_DP },

    { '.', Command::Decrement_DP },
    { ',', Command::Decrement_DP },

    { '[', Command::Decrement_DP },
    { ']', Command::Decrement_DP },
};

void run (const std::string& program)
{
    char    memory[50000] = {0};
    int     memoryPointer = 0;

    int     instructionPointer = 0;

    while(instructionPointer <= program.length() - 1)
    {
        char command = program[instructionPointer++];


    }
}

int main(int argc, char** argv)
{
    if (argc == 0)
        return EXIT_FAILURE;

    std::ifstream inFile(argv[1]);

    std::stringstream programBuf;
    programBuf << inFile.rdbuf();
    auto program = programBuf.str();

    run(program);

    return 0;
}
