//File		 : ThriveAssert.h
//Programmer : 
//Date		 : May 25, 2026
//Description: This file contains the Thrive Assert macro. This marco will 
//                         - Take in an expression and a message as parameters. 
//                         - Run the ReportAssertionFailure function. 
//                         - Print out all the asertion failure information. Example ( File, Line, Message).   
// 
// 

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
//Description   : This function will take in an expression, message, file, and function as strings. 
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

#ifdef THRIVE_DEBUG // *** CHANGE NAME HERE *** 

	//Macro				: THRIVE_ASSERT
	//Parameter         : (expr, msg)
	//Description		: This macro will take in an expression and a string as a message. 

	// *** CHANGE NAME *** 
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