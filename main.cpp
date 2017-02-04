#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <map>

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

int main(int argc, char** argv)
{
    if (argc == 0)
        return EXIT_FAILURE;

    std::ifstream inFile(argv[1]);

    std::vector<char>   data;
    int                 dataPointer = 0;

    std::string program;

    auto programBuf = inFile.rdbuf();


    return 0;
}
