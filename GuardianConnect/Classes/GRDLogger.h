//
//  GRDLogger.h
//  Guardian
//
//  Created by Constantin Jacob on 31.10.21.
//  Copyright © 2021 Sudo Security Group Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "stdarg.h"

NS_ASSUME_NONNULL_BEGIN

// Macros to expose the various function format so that we can pickup the line numbers etc.
#define GRDLog(format, ...) zzz_GRDLog(__PRETTY_FUNCTION__, __LINE__, NO, format, ## __VA_ARGS__)
#define GRDWarningLog(format, ...) zzz_GRDLog(__PRETTY_FUNCTION__, __LINE__, NO, [NSString stringWithFormat:@"[WARNING] %@", format], ## __VA_ARGS__)
#define GRDErrorLog(format, ...) zzz_GRDLog(__PRETTY_FUNCTION__, __LINE__, NO, [NSString stringWithFormat:@"[ERROR] %@", format], ## __VA_ARGS__)

#ifdef DEBUG
#define GRDDebugLog(format, ...) zzz_GRDLog(__PRETTY_FUNCTION__, __LINE__, YES, [NSString stringWithFormat:@"[DEBUG] %@", format], ## __VA_ARGS__)
#else
#define GRDDebugLog(format, ...) /* Doing nothing if not in debug mode */
#endif

#define LOG_SELF zzz_GRDLog(__PRETTY_FUNCTION__, __LINE__, YES, @"%@ %@", self, NSStringFromSelector(_cmd))
#define LOG_SELF_PERSISTENT zzz_GRDLog(__PRETTY_FUNCTION__, __LINE__, NO, @"%@ %@", self, NSStringFromSelector(_cmd))

// Key definitions for these objects in NSUserDefaults
static NSString * const kGRDPersistentLog 			= @"kGRDPersistentLog";
static NSString * const kGRDPersistentLogEnabled 	= @"kGRDPersistentLogEnabled";

@interface GRDLogger : NSObject

@property BOOL persistentLoggingEnabled;

// Setup and management functions
+ (NSArray *)allLogs;
+ (void)deleteAllLogs;
+ (void)togglePersistentLogging:(BOOL)enabled;

// C function (like NSLog) that actually writes the log
void zzz_GRDLog(const char *functionName, int lineNumber, BOOL preventPersistentLog, NSString *format, ...);

@end

NS_ASSUME_NONNULL_END
