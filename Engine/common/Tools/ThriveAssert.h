#pragma once

#include <iostream>
#include <cstdlib>


//Function		: ReportAssertionFailure (const char*, const char*, const char*, int, const char*)
//Parameters    : 
//                const char* expression,
//                const char* message,
//	              const char* file,
//	              int line,
//	              const char* function
//Returns       : void
//Description   : This function will take in an expression, and a message and print out all the information for the user. 
/*
	Notes: This is a very common way to to write an assert function.
*/
inline void ReportAssertionFailure(
	const char* expression,
	const char* message,
	const char* file,
	int line,
	const char* function)
{
	std::cerr << "Assertion Failed!\n";
	std::cerr << "Expression: " << expression << "\n";

	if (message)
		std::cerr << "Message: " << message << "\n";

	std::cerr << "File      : " << file << "\n";
	std::cerr << "Line      : " << line << "\n";
	std::cerr << "Function  : " << function << "\n";

	std::abort(); // crash immediately
}


//This macro is designed for the thrive game engine. 

#ifdef THRIVE_DEBUG

	//Macro				: THRIVE_ASSERT
	//Parameter         : (expr, msg)
	//Description		: This macro will take in an expression and a string as a message. 
	#define THRIVE_ASSERT(expr, msg)									  \
	 do                                                                   \
		{                                                                 \
			if (!(expr))                                                  \
			{                                                             \
				ReportAssertionFailure(                                   \
					#expr,                                                \
					msg,                                                  \
					__FILE__,                                             \
					__LINE__,                                             \
					__FUNCTION__);                                        \
			}                                                             \
		} while (0)

#else

#define THRIVE_ASSERT(expr, msg) ((void)0)

#endif