#include "bytey/out/directives.h"

bool byout_write_fill(BYTEY_OUT_WRITER *writer, unsigned long long int index_to_fill, unsigned char byte_value_to_fill) {
  BY_OPCODE_TYPE opcode = BY_FILL;
  if (by_write(writer, &opcode, sizeof(BY_OPCODE_TYPE))) return true;
  if (by_write(writer, &index_to_fill, sizeof(unsigned long long int))) return true;
  if (by_write(writer, &byte_value_to_fill, sizeof(unsigned char))) return true;
  return false;
}