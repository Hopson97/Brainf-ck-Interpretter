#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <map>
#include <sstream>
#include <stack>

/*                  Brainf*ck command list
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  Command     Desciption
 *
 *      >       Increment the data pointer (to point to the next cell to the right).
 *      <       Decrement the data pointer (to point to the next cell to the left).
 *
 *      +       Increment (increase by one) the byte at the data pointer.
 *      -       decrement (decrease by one) the byte at the data pointer.
 *
 *      .       Print out the character
 *      ,       Get one char/ byte of input
 *
 *      [       Begin while(the value in memory at the mem ptr is not 0)
 *      ]       end while
 */

void run (const std::string& program)
{
    std::stack<int> scopeInstruction;


    char    memory[50000] = {0};

    auto    memoryPointer = 0;
    auto    instructionPointer = 0;

    while((unsigned)instructionPointer <= program.length() - 1)
    {
        auto command = program[instructionPointer++];

        switch(command)
        {
            case '>':
                memoryPointer++;
                break;

            case '<':
                memoryPointer--;
                break;

            case '+':
                memory[memoryPointer]++;
                break;

            case '-':
                memory[memoryPointer]--;
                break;

            case '.':
                std::cout << memory[memoryPointer] << std::endl;
                break;

            case ',':
                std::cin >> memory[memoryPointer];
                break;

            case '[':
                if (!memory[memoryPointer])
                {
                    while (program[instructionPointer++] != ']');
                }
                else
                {
                    scopeInstruction.push(instructionPointer);

                }
                break;

            case ']':
                if (memory[memoryPointer])
                {
                    instructionPointer = scopeInstruction.top();
                }
                else
                {
                    scopeInstruction.pop();
                }
                break;
        }

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

    std::cin.ignore();

    return 0;
}
