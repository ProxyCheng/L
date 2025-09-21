
#include <array>
#include <iostream>
#include <string>

#include "L/LEngine.h"
#include "L/LDiagnostic.h"

using namespace L;

int main(int argc, char* argv[])
{
    std::unique_ptr<LEngine> engine = std::make_unique<LEngine>();
    LDiagnosticPtr diagnostic = engine->Init();
    if (diagnostic)
    {
        std::cerr << diagnostic->ToString() << std::endl;
        return -1;
    }
    while (true)
    {
        std::string expression;
        std::array<char, 128> buffer;
        std::cin.getline(buffer.data(), buffer.size(), '\n');
        expression = buffer.data();
        if (expression.empty())
            break;
        std::string result;
        diagnostic = engine->Evaluate(expression, result);
        if (diagnostic)
        {
            std::cerr << diagnostic->ToString() << std::endl;
            continue;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
