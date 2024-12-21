#pragma once

#include <chk/common/types.h>
#include <chk/common/visibility.h>

#include <stdarg.h>

CHK_COMMON_API s32 chk_vformat(char *buffer, size_t size, const char *msg, va_list args);

CHK_COMMON_API s32 chk_format(char *buffer, size_t size, const char *msg, ...);
