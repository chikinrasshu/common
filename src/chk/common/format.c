#pragma once

#include <chk/common/format.h>

#include <stdio.h>

CHK_COMMON_API s32 chk_vformat(char *buffer, size_t size, const char *msg,
                               va_list orig_args) {
    va_list args;
    va_copy(args, orig_args);

    s32 result = vsnprintf(buffer, size, msg, args);

    va_end(args);

    return result;
}

CHK_COMMON_API s32 chk_format(char *buffer, size_t size, const char *msg, ...) {
    va_list args;
    va_start(args, msg);

    s32 result = chk_vformat(buffer, size, msg, args);

    va_end(args);

    return result;
}
