
#include <array>
#include <iostream>
#include <string>

#include "L/LEngine.h"
#include "L/LDiagnostic.h"

using namespace L;

int main(int argc, char* argv[])
{
    LEngine engine;
    while (true)
    {
        std::string expression;
        std::array<char, 128> buffer;
        std::cin.getline(buffer.data(), buffer.size(), '\n');
        expression = buffer.data();
        if (expression.empty())
            break;
        std::string result;
        LDiagnosticPtr diagnostic = engine.Evaluate(expression, result);
        if (diagnostic)
        {
            std::cerr << diagnostic->ToString() << std::endl;
            continue;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
