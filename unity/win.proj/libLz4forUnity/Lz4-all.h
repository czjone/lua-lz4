#ifndef LZ4_INI
#if _WINDOWS 
extern "C" {
#	include "../../lz4-lua/lz4/lz4.c"
#	include "../../lz4-lua/lz4/lz4frame.c"
#	include "../../lz4-lua/lz4/lz4hc.c"
#	include "../../lz4-lua/lz4/xxhash.c"
}
#endif
#endif