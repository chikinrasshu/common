chk_common_src = ['chk/common/format.c', 'chk/common/logging.c']

chk_common_dep = library(
    'chk_common',
    sources: chk_common_src,
    include_directories: chk_common_inc,

    gnu_symbol_visibility: 'hidden',
    c_shared_args: ['-DCHK_COMMON_DLL', '-DCHK_COMMON_DLL_EXPORTS'],
    install: true,
)