#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <map>
#include <sstream>
#include <stack>

#include "Interpretter.h"

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
namespace
{
     std::string getProgramString(const std::string& fileName)
     {
        std::ifstream inFile(fileName);

        std::stringstream programBuf;
        programBuf << inFile.rdbuf();

        return programBuf.str();
     }
 }

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "This programs requires a FILE NAME INPUT. Exiting." << std::endl;
        return EXIT_FAILURE;

    }

    Interpretter interpretter(getProgramString(argv[1]));
    interpretter.run();

    std::cout << "Success. Press any ket to exit." << std::endl;
    std::cin.ignore();

    return EXIT_SUCCESS;
}
