/*
   A very basic logger for output of messages at various logging levels
   with date/time stamp to standard out and a defined log file.

Author: Nate Peterson
Created: June 2013
Last Updated: Feb 2014
*/

#ifndef SIMPLOG_H
#define SIMPLOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

// Define logging levels
#define SIMPLOG_FATAL    -2    // A fatal error has occured: program will exit immediately
#define SIMPLOG_ERROR    -1    // An error has occured: program may not exit
#define SIMPLOG_INFO     0     // Nessessary information regarding program operation
#define SIMPLOG_WARN     1     // Any circumstance that may not affect normal operation
#define SIMPLOG_DEBUG    2     // Standard debug messages
#define SIMPLOG_VERBOSE  3     // All debug messages

// Public functions
typedef struct {
    void ( *const writeLog )( int loglvl, const char* filename, int line, const char* str, ... );
    void ( *const writeStackTrace )( void );
    void ( *const setLogDebugLevel )( int level );
    void ( *const setLogFile )( const char* file );
    void ( *const setLogSilentMode )( bool silent );
    void ( *const setLineWrap )( bool wrap );
    void ( *const flushLog )( void );
    void ( *const loadConfig )( const char* config );
} simplog_namespace;
extern simplog_namespace const simplog;

#define LOG_VERBOSE(format, args...) simplog.writeLog(SIMPLOG_VERBOSE, __FILE__, __LINE__, format, ##args)
#define LOG_DEBUG(format, args...) simplog.writeLog(SIMPLOG_DEBUG, __FILE__, __LINE__, format, ##args)
#define LOG_INFO(format, args...) simplog.writeLog(SIMPLOG_INFO, __FILE__, __LINE__, format, ##args)
#define LOG_WARN(format, args...) simplog.writeLog(SIMPLOG_WARN, __FILE__, __LINE__, format, ##args)
#define LOG_ERROR(format, args...) simplog.writeLog(SIMPLOG_ERROR, __FILE__, __LINE__, format, ##args)
#define LOG_FATAL(format, args...) simplog.writeLog(SIMPLOG_FATAL, __FILE__, __LINE__, format, ##args)

#ifdef __cplusplus
}
#endif

#endif
