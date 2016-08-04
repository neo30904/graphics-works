#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

/****************************************************************************
Created By @ Ajay Singh Tanwar
-EngineDevelopment
****************************************************************************/

#include <iostream>


#define DEBUG 1

#if(DEBUG)
	#define LOG(...)   fprintf(stderr , ##__VA_ARGS__) ,  std::cout<<std::endl
#else
	#define LOG(...)
#endif


#endif // MACROS_H_INCLUDED
