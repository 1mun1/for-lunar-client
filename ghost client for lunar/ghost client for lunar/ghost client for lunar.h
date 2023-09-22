// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GHOSTCLIENTFORLUNAR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GHOSTCLIENTFORLUNAR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GHOSTCLIENTFORLUNAR_EXPORTS
#define GHOSTCLIENTFORLUNAR_API __declspec(dllexport)
#else
#define GHOSTCLIENTFORLUNAR_API __declspec(dllimport)
#endif

// This class is exported from the dll
class GHOSTCLIENTFORLUNAR_API Cghostclientforlunar {
public:
	Cghostclientforlunar(void);
	// TODO: add your methods here.
};

extern GHOSTCLIENTFORLUNAR_API int nghostclientforlunar;

GHOSTCLIENTFORLUNAR_API int fnghostclientforlunar(void);
