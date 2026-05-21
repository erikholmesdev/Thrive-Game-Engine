#pragma once
//File		 : Log.h
//Programmer :
//Date		 : Dec 18, 2025
//Description: This file contains the log class. The log class allows messages to appear in the console or log file. 

#include <spdlog/spdlog.h>
#include <spdlog\sinks\stdout_color_sinks.h>
#include <spdlog\sinks\basic_file_sink.h>


namespace Thrive
{
	class Log
	{
	public:

		//Method	 : Init()
		//Parameters : bool logFileActive = false
		//Description: This method will will initialize our logger. If logFileActive = true then a log file will be create in the build/engine/log.
		//              else logFileActive = false at default and no log file will be created.    
		static void Init(bool logFileActive = false)
		{
			if (m_CoreLogger) return;

			// Console sink
			auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

			if (logFileActive) // Console and file 
			{
				// File sink 
				auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../engine/log/engine.log", true);

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

		//Method	 : GetLogger
		//Description: This method will get our logger. 
		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }

	private:
		inline static std::shared_ptr<spdlog::logger>m_CoreLogger = nullptr; 
		
	};
}

#ifdef THRIVE_DEBUG //Can be found in the engine/CmakeLists.txt 

	#define LOG_CORE_TRACE(...)    ::Thrive::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define LOG_CORE_INFO(...)     ::Thrive::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define LOG_CORE_WARN(...)     ::Thrive::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define LOG_CORE_ERROR(...)    ::Thrive::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define LOG_CORE_CRITICAL(...) ::Thrive::Log::GetCoreLogger()->critical(__VA_ARGS__)

#else
	// Compile out logging completely
	#define LOG_CORE_TRACE(...)
	#define LOG_CORE_INFO(...)
	#define LOG_CORE_WARN(...)
	#define LOG_CORE_ERROR(...)
	#define LOG_CORE_CRITICAL(...)

#endif
