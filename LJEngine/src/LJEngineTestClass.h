#ifndef LFENGINETESTHEADER_H_
#define LFENGINETESTHEADER_H_

//TODO: Put this in a header.  Something like globalHEader.h
#ifdef LJENGINE_EXPORTS
    #define LJENGINE_API __declspec(dllexport)
#else
    #define LJENGINE_API __declspec(dllimport)
#endif

LJENGINE_API class EngineTestClass
{
public:
	LJENGINE_API static void InitEngine();

	LJENGINE_API static void RenderTriangle();
};

#endif