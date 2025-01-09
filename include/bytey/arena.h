#ifndef BYTEY_ARENA_IMPLEMENTED
#define BYTEY_ARENA_IMPLEMENTED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> // bool, true, false
#include <stddef.h> // size_t

struct arena_buf {
  char *buf;
  size_t bufsize;
  size_t bufindex;
};
typedef struct arena_buf arena_buf_t;

bool by_arena_create(arena_buf_t *buf, size_t size);
void by_arena_delete(arena_buf_t *buf);
bool by_arena_recreate(arena_buf_t *buf, size_t size);
bool by_arena_push(arena_buf_t *buf, void *data, size_t data_size);

#ifdef __cplusplus
}
#endif
#endif // BYTEY_ARENA_IMPLEMENTED