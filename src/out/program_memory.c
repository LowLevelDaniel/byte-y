#include "bytey/out/program_memory.h"

bool byout_write_fill(BYTEY_STREAM *stream, size_t index_to_fill, unsigned char byte_value_to_fill) {
  if (byputop(BY_FILL, stream)) return true;
  if (bywrite(stream, &index_to_fill, sizeof(size_t))) return true;
  if (bywrite(stream, &byte_value_to_fill, sizeof(unsigned char))) return true;
  return false;
}
bool byout_write_insert(BYTEY_STREAM *stream, size_t _sizeof, void *bytes) {
  if (byputop(BY_INSERT, stream)) return true;
  if (bywrite(stream, &_sizeof, sizeof(size_t))) return true;
  if (bywrite(stream, bytes, _sizeof)) return true;
  return false;
}