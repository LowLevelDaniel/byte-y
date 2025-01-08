#ifndef BY_GLOBAL_IO_IMPL
#define BY_GLOBAL_IO_IMPL

#ifdef __cplusplus
extern "C" {
#endif

#define SNL "\n"
#define NL '\n'

#include <stdio.h>
#include <stdbool.h>

#include "bytey/defines.h"

#define LOG(msg, ...) printf("INFO: " msg SNL, ##__VA_ARGS__)
#define ERR(msg, ...) printf("ERR: " msg SNL, ##__VA_ARGS__)
#define WARN(msg, ...) printf("WARNING: " msg SNL, ##__VA_ARGS__)

struct btyey_stream {
  union { 
    FILE *file;
    char *bytes;
    // PIPE ?
  } src;
  // Fill in with more once
};

#define BYTEY_STREAM struct btyey_stream

bool by_create_file(BYTEY_STREAM *stream, FILE *file);

int bygetc(BYTEY_STREAM *stream);
BY_OPCODE_TYPE bygetop(BYTEY_STREAM *stream);
bool byread(BYTEY_STREAM *stream, void *ptr, size_t bsize);

bool byputc(int value, BYTEY_STREAM *stream);
bool byputop(BY_OPCODE_TYPE opcode, BYTEY_STREAM *stream);
bool bywrite(BYTEY_STREAM *stream, void *ptr, size_t bsize);

size_t bytell(BYTEY_STREAM *stream);

#ifdef __cplusplus
}
#endif

#endif // BY_GLOBAL_IO_IMPL