#pragma once
/*
* @file Log.h
* @brief This file contains a Log class which is a wrapper class for spdlog
*/
#include <string.h>
#include <spdlog/spdlog.h>
#include <spdlog\sinks\stdout_color_sinks.h>
#include <spdlog\sinks\basic_file_sink.h>


namespace Thrive
{

	//Change this path to the file you want.
	const std::string k_FilePath = "../engine/log/engine.log"; 

	/*
	 * @brief Used to create a logging object for debugging.  
	 *
	 *  This class handles the logging output between the game engine 
	 *    to the programmer. 
	 * 
	 *  @note This class is not thread save 
	 * 
	*/
	class Log
	{
	public:

		/*
		* @brief Initialize a logging object to be used to communicate between the engine and the programmer. 
		* 
		* @param bool logFile = false
		* 
		* @warning This class is static and will be used 
		*/
		static void Init(bool logFileActive = false)
		{
			if (m_CoreLogger) return;

			// Console sink
			auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

			if (logFileActive) // Console and file 
			{
				// File sink 
				auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(k_FilePath, true);

				std::vector<spdlog::sink_ptr> sinks { consoleSink, fileSink };

				
				m_CoreLogger = std::make_shared<spdlog::logger> ("CORE", sinks.begin(),sinks.end());
			}
			else //console only 
			{
				m_CoreLogger = std::make_shared<spdlog::logger> ("CORE",consoleSink);
			}

			m_CoreLogger->set_level(spdlog::level::trace);
			spdlog::register_logger(m_CoreLogger);
		}

		/*
		* @brief Gets the core logger
		* 
		* @note 
		*  This method is used to get the core logger. 
		* 
		* @warning This method is static
		* @return std::shared_ptr <spdlog::logger>
		*/
		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }

	private:
		inline static std::shared_ptr<spdlog::logger>m_CoreLogger = nullptr; 
		
	};
}

#ifdef THRIVE_DEBUG //Can be found in the engine/CmakeLists.txt 
	
	/*
	* @brief This macro will print out a trace message used for debugging
	* 
	* @note 
	*		This macro can only be used when the project is building debug mode. Nothing will happen if this 
	*        macro is used in when the project is built in release mode. 
	* 
	* @param "Message" or std::string
	* 
	*/
	#define LOG_CORE_TRACE(...)    ::Thrive::Log::GetCoreLogger()->trace(__VA_ARGS__)

	/*
	* @brief This macro will print out a information message used for debugging 
	* 
	* @note
	*		This macro can only be used when the project is building in debug mode. Nothing will happen if this
	*		macro is used in when the project is built in release mode.
	* @param 
	*/
	#define LOG_CORE_INFO(...)     ::Thrive::Log::GetCoreLogger()->info(__VA_ARGS__)

	/*
	* @brief This macro will print out a warning message used for debugging
	*
	* @note
	*		This macro can only be used when the project is building in debug mode. Nothing will happen if this
	*		macro is used in when the project is built in release mode.
	* @param
	*/
	#define LOG_CORE_WARN(...)     ::Thrive::Log::GetCoreLogger()->warn(__VA_ARGS__)

	/*
	* @brief This macro will print out a error message used for debugging
	*
	* @note
	*		This macro can only be used when the project is building in debug mode. Nothing will happen if this
	*		macro is used in when the project is built in release mode.
	* @param
	*/
	#define LOG_CORE_ERROR(...)    ::Thrive::Log::GetCoreLogger()->error(__VA_ARGS__)

	/*
	* @brief This macro will print out a critical message used for debugging
	*
	* @note
	*		This macro can only be used when the project is building in debug mode. Nothing will happen if this
	*		macro is used in when the project is built in release mode.
	* @param
	*/
	#define LOG_CORE_CRITICAL(...) ::Thrive::Log::GetCoreLogger()->critical(__VA_ARGS__)

#else
	// Compile out logging completely
	#define LOG_CORE_TRACE(...)
	#define LOG_CORE_INFO(...)
	#define LOG_CORE_WARN(...)
	#define LOG_CORE_ERROR(...)
	#define LOG_CORE_CRITICAL(...)

#endif
