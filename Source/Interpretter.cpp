#include "Interpretter.h"

#include <iostream>

Interpretter::Interpretter(const std::string& programString)
:   m_programString (programString)
{
    m_memory.push_back(0); //Init the first cell...
}

void Interpretter::increment()
{
    m_memoryPointer++;
    if ((unsigned)m_memoryPointer >= m_memory.size() - 1)
    {
        m_memory.push_back(0);
    }
}


void Interpretter::run()
{
    while((unsigned)m_instructionPointer <= m_programString.length() - 1)
    {
        switch(m_programString[m_instructionPointer++])
        {
            case '>':
                increment();
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
