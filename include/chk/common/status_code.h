#pragma once

#include <chk/common/types.h>

typedef enum chk_status_code {
    CHK_STATUS_FAILURE = 0,
    CHK_STATUS_SUCCESS,
    CHK_STATUS_ALREADY_INITIALIZED,
    CHK_STATUS_NOT_INITIALIZED,
    CHK_STATUS_BAD_PTR,
    CHK_STATUS_BAD_PATH,
    CHK_STATUS_BAD_FILE,
    CHK_STATUS_BAD_MAGIC,
} chk_status_code_t;
