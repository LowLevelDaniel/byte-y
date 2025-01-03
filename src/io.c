#include "bytey/io.h"
#include "bytey/defines.h"

#include <string.h>

int bygetc(BYTEY_INPUT *byin) {
  if (byin->src_type == BYTEY_INPUT_SRC_TYPE_FILE) {
    int in = fgetc(byin->src.file);
    if (in == EOF) return BY_EOF;
    return in;
  } else if (byin->src_type == BYTEY_INPUT_SRC_TYPE_PTR) {
    char *bptr = (char*)byin->src.ptr;
    char in = *(++bptr);
    if (in == '\0') return BY_EOF;
    return (int)in;
  }
  ERR("byin_getc failed to find src_type");
  return BY_EOF;
}

bool by_create_file(BYTEY_INPUT *writer, FILE *file) {
  writer->src_type = BYTEY_INPUT_SRC_TYPE_FILE;
  writer->src.file = file;
  return false;
}
bool by_create_ptr(BYTEY_INPUT *writer, char *ptr) {
  writer->src_type = BYTEY_INPUT_SRC_TYPE_PTR;
  writer->src.ptr = ptr;
  return false;
}

bool bywrite(BYTEY_INPUT *writer, void *ptr, size_t bsize) {
  switch (writer->src_type) {
    case BYTEY_INPUT_SRC_TYPE_FILE:
      fwrite(ptr, 1, bsize, writer->src.file);
      break;
    case BYTEY_INPUT_SRC_TYPE_PTR:
      memcpy(writer->src.ptr, ptr, bsize);
      char *byte_ptr = ((char*)writer->src.ptr);
      byte_ptr += bsize;
      break;
    default:
      ERR("Invalid BYTEY_INPUT_SRC_TYPE %d", writer->src_type);
      return true;
  }
  return false;  
}