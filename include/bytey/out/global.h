#ifdef __cplusplus
#pragma once
#endif

#ifndef BYTEY_OUTPUT_GLOBAL_IMPL
#define BYTEY_OUTPUT_GLOBAL_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "bytey/io.h"
#include "bytey/defines.h"

#define BYTEY_OUT_WRITER BYTEY_INPUT
#define BYTEY_OUT_WRITER_TO_BYTEY_INPUT(bytey_out_writer) \
  bytey_out_writer // no casting needed right now

#ifdef __cplusplus
}
#endif
#endif // BYTEY_OUTPUT_GLOBAL_IMPL