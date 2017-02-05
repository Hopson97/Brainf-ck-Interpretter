#ifndef INTERPRETTER_H_INCLUDED
#define INTERPRETTER_H_INCLUDED

#include <string>
#include <vector>
#include <stack>

class Interpretter
{
    public:
        Interpretter(const std::string& programString);

        void run();


    private:
        const std::string m_programString;

        int m_instructionPointer    = 0;
        int m_memoryPointer         = 0;

        char m_memory[50'000];

        std::stack<int> m_scopeInstructions;
};

#endif // INTERPRETTER_H_INCLUDED
