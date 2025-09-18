#pragma once

#ifdef L_EXPORTS
#define L_API __declspec(dllexport)
#else
#define L_API __declspec(dllimport)
#endif

#define RETURN_IF_PANIC(EXPRESSION) \
if (LDiagnosticPtr diagnostic = (EXPRESSION)) \
return diagnostic;