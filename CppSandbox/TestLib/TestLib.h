// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TEST2_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TEST2_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTLIB_EXPORTS
#define TESTLIB_API __declspec(dllexport)
#else
#define TESTLIB_API __declspec(dllimport)
#endif

// This class is exported from the Test2.dll
class TESTLIB_API MathsUtils {
public:
	
    /// <summary>
    /// Initializes a new instance of the <see cref="MathsUtils"/> class.
    /// </summary>
    MathsUtils(void);

    template <typename T>
    static const T& Max(const T& a, const T& b)
    {
        return a > b ? a : b;
    }

    template <typename T>
    static const T& Min(const T& a, const T& b)
    {
        return a < b ? a : b;
    }

};