#ifdef __cplusplus
#pragma once
#endif

#ifndef BYTEY_INPUT_GLOBAL_IMPL
#define BYTEY_INPUT_GLOBAL_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "bytey/io.h"
#include "bytey/defines.h"

enum BYTEY_ARCH_TYPE : int {
  BYTEY_ARCH_TYPE_X86
};

struct byin {
  BYTEY_INPUT *reader;
  BYTEY_INPUT *writer;
  int machine_type;
  enum BYTEY_ARCH_TYPE arch;
};
#define BYTEY_IN_READER struct byin

#ifdef __cplusplus
}
#endif
#endif // BYTEY_INPUT_GLOBAL_IMPL