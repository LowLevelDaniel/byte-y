#ifndef BY_GLOBAL_IO_IMPL
#define BY_GLOBAL_IO_IMPL

#ifdef __cplusplus
extern "C" {
#endif

#define SNL "\n"
#define NL '\n'

#include <stdio.h>
#include <stdbool.h>

#define LOG(msg, ...) printf("INFO: " msg SNL, ##__VA_ARGS__)
#define ERR(msg, ...) printf("ERR: " msg SNL, ##__VA_ARGS__)
#define WARN(msg, ...) printf("WARNING: " msg SNL, ##__VA_ARGS__)

enum BYTEY_INPUT_SRC_TYPE : int {
  BYTEY_INPUT_SRC_TYPE_FILE,
  BYTEY_INPUT_SRC_TYPE_PTR
};

struct bytey_input {
  enum BYTEY_INPUT_SRC_TYPE src_type;
  union {
    FILE *file;
    char *ptr;
  } src;
};

#define BYTEY_INPUT struct bytey_input

int bygetc(BYTEY_INPUT *byin);
bool by_create_file(BYTEY_INPUT *writer, FILE *file);
bool by_create_ptr(BYTEY_INPUT *writer, char *ptr);
bool by_write(BYTEY_INPUT *writer, void *ptr, size_t bsize);

#ifdef __cplusplus
}
#endif

#endif // BY_GLOBAL_IO_IMPL