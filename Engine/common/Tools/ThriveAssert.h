/*
* @file ThriveAssert.h
* 
* @brief This file contains the ReportAssertionFailure function and the ThriveAssert macro.
* 

*/

#pragma once

#include <iostream>
#include <cstdlib>


/*
* @brief Report to the user about any assertion fails 
* 
* @note There does not need to be a message entered.
* 
* @param const char* experssion 
* @param const char* message
* @param const char* file
* @param int line,
* @param const char* function
* 
* @return void
* 
* @warning If this method is triggered then the program will crash.
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

 
#ifdef THRIVE_DEBUG // *** CHANGE NAME HERE *** 

	/*
	* @brief This macro is used for assertion.
	*
	* @note 
	*   This method will call the ReportAssertionFailure function if the expr = false. 
	*   *** Change name of macro if using in own project *** 
	* @param expr 
	* @param msg 
	* 
	* @warning This macro can only work when the project is being built in debug mode 
	*/
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

#else //Release mode

#define THRIVE_ASSERT(expr, msg) ((void)0)

#endif