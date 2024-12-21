#include <chk/common/logging.h>

#include <chk/common/format.h>

#include <stdio.h>
#include <stdlib.h>

CHK_COMMON_API void chk_raw_log(chk_log_severity_t sev, const char *msg,
                                const char *file, const char *func, s32 line) {
    const char *sev_name = "Unknown";
    switch (sev) {
        case CHK_LOG_SEVERITY_DEBUG: sev_name = "Debug"; break;
        case CHK_LOG_SEVERITY_TRACE: sev_name = "Trace"; break;
        case CHK_LOG_SEVERITY_INFO: sev_name = "Info"; break;
        case CHK_LOG_SEVERITY_WARNING: sev_name = "Warning"; break;
        case CHK_LOG_SEVERITY_ERROR: sev_name = "Error"; break;
        case CHK_LOG_SEVERITY_FATAL: sev_name = "Fatal"; break;
    }

    fprintf(stderr, "%s | %s:%s:%d | %s\n", sev_name, file, func, line, msg);

    if (sev == CHK_LOG_SEVERITY_FATAL) { exit(1); }
}

CHK_COMMON_API void chk_raw_log_f(chk_log_severity_t sev, const char *msg,
                                  const char *file, const char *func, s32 line,
                                  ...) {
    static char chk_raw_log_f_buf[1024];

    va_list args;
    va_start(args, line);
    chk_vformat(chk_raw_log_f_buf, sizeof(chk_raw_log_f_buf), msg, args);
    va_end(args);

    chk_raw_log(sev, chk_raw_log_f_buf, file, func, line);
}
