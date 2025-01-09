#ifdef __cplusplus
#pragma once
#endif

#ifndef BYTEY_INPUT_MAIN_IMPL
#define BYTEY_INPUT_MAIN_IMPL
#ifdef __cplusplus
extern "C" {
#endif

#ifndef BYTEY_ARENA
  #define BYTEY_ARENA arena_buf_t
  #define BYTEY_ARENA_PUSH(Parena, Pval, size) if (by_arena_push(Parena,Pval,size)) { return true; }
  #define BYTEY_ARENA_CREATE(Parena, size) if (by_arena_create(Parena, size)) { return true; }
  #define BYTEY_ARENA_DELETE(Parena) by_arena_delete(Parena)
  #define BYTEY_ARENA_BUFFER(Parena) ((Parena)->buf)
  #define BYTEY_ARENA_CURRBUFF(Parena) ((Parena->buf) + Parena->bufindex)
  #define BYTEY_ARENA_SIZE(Parena) ((Parena)->bufsize)
  #include "bytey/arena.h"
#endif

#include "bytey/io.h"
#include "bytey/in/global.h"
#include "bytey/in/parser.h"

#ifdef __cplusplus
}
#endif
#endif // BYTEY_INPUT_MAIN_IMPL