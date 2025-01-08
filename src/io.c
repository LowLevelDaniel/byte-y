#include "bytey/io.h"


bool by_create_file(BYTEY_STREAM *stream, FILE *file) {
  stream->src.file = file;
  return false;
}

int bygetc(BYTEY_STREAM *stream) {
  return fgetc(stream->src.file);
}
BY_OPCODE_TYPE bygetop(BYTEY_STREAM *stream) {
  BY_OPCODE_TYPE type;
  size_t bread = fread(&type, sizeof(BY_OPCODE_TYPE), 1, stream->src.file);
  if (bread != 1) return BY_EOF;
  return type;
}
bool byread(BYTEY_STREAM *stream, void *ptr, size_t bsize) {
  size_t bread = fread(ptr, 1, bsize, stream->src.file);
  if (bread != bsize) return true;
  return false;
}

bool byputc(int value, BYTEY_STREAM *stream) {
  fputc(value, stream->src.file);
  return false;
}
bool byputop(BY_OPCODE_TYPE opcode, BYTEY_STREAM *stream) {
  fwrite(&opcode, sizeof(opcode), 1, stream->src.file);
  return false;
}
bool bywrite(BYTEY_STREAM *stream, void *ptr, size_t bsize) {
  fwrite(ptr, 1, bsize, stream->src.file);
  return false;
}

size_t bytell(BYTEY_STREAM *stream) {
  return ftell(stream->src.file);
}