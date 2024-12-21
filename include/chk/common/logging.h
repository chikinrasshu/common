#pragma once

#include <chk/common/types.h>
#include <chk/common/visibility.h>

typedef enum chk_log_severity {
    CHK_LOG_SEVERITY_DEBUG = 0,
    CHK_LOG_SEVERITY_TRACE,
    CHK_LOG_SEVERITY_INFO,
    CHK_LOG_SEVERITY_WARNING,
    CHK_LOG_SEVERITY_ERROR,
    CHK_LOG_SEVERITY_FATAL,
} chk_log_severity_t;

CHK_COMMON_API void chk_raw_log(chk_log_severity_t sev, const char *msg,
                                const char *file, const char *func, s32 line);

CHK_COMMON_API void chk_raw_log_f(chk_log_severity_t sev, const char *msg,
                                  const char *file, const char *func, s32 line,
                                  ...);

#define chk_log(sev, msg, ...)                                                 \
    chk_raw_log##__VA_OPT__(_f)(sev, msg, __FILE__, __func__,                  \
                                __LINE__##__VA_OPT__(, ) __VA_ARGS__)

#define chk_dbg(msg, ...)                                                      \
    chk_log(CHK_LOG_SEVERITY_DEBUG, msg##__VA_OPT__(, ) __VA_ARGS__)

#define chk_trace(msg, ...)                                                    \
    chk_log(CHK_LOG_SEVERITY_TRACE, msg##__VA_OPT__(, ) __VA_ARGS__)

#define chk_info(msg, ...)                                                     \
    chk_log(CHK_LOG_SEVERITY_INFO, msg##__VA_OPT__(, ) __VA_ARGS__)

#define chk_warn(msg, ...)                                                     \
    chk_log(CHK_LOG_SEVERITY_WARNING, msg##__VA_OPT__(, ) __VA_ARGS__)

#define chk_error(msg, ...)                                                    \
    chk_log(CHK_LOG_SEVERITY_ERROR, msg##__VA_OPT__(, ) __VA_ARGS__)

#define chk_fatal(msg, ...)                                                    \
    chk_log(CHK_LOG_SEVERITY_FATAL, msg##__VA_OPT__(, ) __VA_ARGS__)
