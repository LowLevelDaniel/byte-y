#include "bytey/out/control_flow.h"

bool byout_write_ihalt(BYTEY_OUT_WRITER *writer) {
  BY_OPCODE_TYPE opcode = BY_IHLT;
  if (by_write(writer, &opcode, sizeof(BY_OPCODE_TYPE))) return true;
  return false;
}
