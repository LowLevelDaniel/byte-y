#ifdef __cplusplus
#pragma once
#endif

#ifndef BYTEY_OUTPUT_PROGRAM_MEMORY_IMPL
#define BYTEY_OUTPUT_PROGRAM_MEMORY_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#include "bytey/out/global.h"

bool byout_write_fill(BYTEY_STREAM *stream, size_t index_to_fill, unsigned char byte_value_to_fill);
bool byout_write_insert(BYTEY_STREAM *stream, size_t _sizeof, void *bytes);

#ifdef __cplusplus
}
#endif
#endif // BYTEY_OUTPUT_PROGRAM_MEMORY_IMPL
