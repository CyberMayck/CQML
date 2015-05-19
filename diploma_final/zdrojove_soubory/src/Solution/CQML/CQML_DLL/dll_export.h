#ifdef CQML_DLL_EXPORTS
#define CQML_API __declspec(dllexport) 
#else
#define CQML_API __declspec(dllimport) 
#endif