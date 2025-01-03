#ifdef __cplusplus
#pragma once
#endif

#ifndef BYTEY_OUTPUT_CONTROL_FLOW_IMPL
#define BYTEY_OUTPUT_CONTROL_FLOW_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#include "bytey/out/global.h"

bool byout_write_fill(BYTEY_OUT_WRITER *writer, unsigned long long int index_to_fill, unsigned char byte_value_to_fill);

#ifdef __cplusplus
}
#endif
#endif // BYTEY_OUTPUT_CONTROL_FLOW_IMPL