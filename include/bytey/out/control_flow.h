#ifdef __cplusplus
#pragma once
#endif

#ifndef BYTEY_OUTPUT_CONTROL_FLOW_IMPL
#define BYTEY_OUTPUT_CONTROL_FLOW_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#include "bytey/out/global.h"

void byout_write_halt(BYTEY_OUT_WRITER *writer);

#ifdef __cplusplus
}
#endif
#endif // BYTEY_OUTPUT_CONTROL_FLOW_IMPL