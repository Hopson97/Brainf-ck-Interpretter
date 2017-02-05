#include "Interpretter.h"

#include <iostream>

Interpretter::Interpretter(const std::string& programString)
:   m_programString (programString)
{ }

void Interpretter::run()
{
    while((unsigned)m_instructionPointer <= m_programString.length() - 1)
    {
        auto command = m_programString[m_instructionPointer++];

        switch(command)
        {
            case '>':
                m_memoryPointer++;
                break;

            case '<':
                m_memoryPointer--;
                break;

            case '+':
                m_memory[m_memoryPointer]++;
                break;

            case '-':
                m_memory[m_memoryPointer]--;
                break;

            case '.':
                std::cout << m_memory[m_memoryPointer];
                break;

            case ',':
                std::cin >> m_memory[m_memoryPointer];
                break;

            case '[':
                if (!m_memory[m_memoryPointer])
                {
                    while (m_programString[m_instructionPointer++] != ']');
                }
                else
                {
                    m_scopeInstructions.push(m_instructionPointer);
                }
                break;

            case ']':
                if (m_memory[m_memoryPointer])
                {
                    m_instructionPointer = m_scopeInstructions.top();
                }
                else
                {
                    m_scopeInstructions.pop();
                }
                break;
            default:
                break;
        }

    }
}
