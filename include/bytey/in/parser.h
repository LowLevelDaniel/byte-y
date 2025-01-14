#ifdef __cplusplus
#pragma once
#endif

#ifndef BYTEY_INPUT_PARSER_IMPL
#define BYTEY_INPUT_PARSER_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#include "bytey/in/global.h"

bool byin_parse(BYTEY_STREAM *ins, BYTEY_STREAM *outs);

#ifdef __cplusplus
}
#endif
#endif // BYTEY_INPUT_PARSER_IMPL