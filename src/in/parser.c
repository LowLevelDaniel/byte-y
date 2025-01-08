#include "bytey/in/parser.h"
#include <stdlib.h>

// Program Memory
bool byin_write_machine_fill(BYTEY_STREAM *ins, BYTEY_STREAM *outs) {
  // --- input --- //
  // get index
  size_t index;
  if (byread(ins, &index, sizeof(index))) {
    ERR("BY_FILL - Uncompleted Opcode 0");
    return true;
  }
  // get value
  int value = bygetc(ins);
  if (value == EOF) {
    ERR("BY_FILL - Uncompleted Opcode 1");
    return true;
  }

  // --- output --- //
  for (long int cindex = bytell(outs); cindex < index; ++cindex) {
    if (byputc(value, outs)) {
      ERR("BY_FILL - byputc(outs) failed");
      return true;
    }
  }

  return false;
}

bool byin_write_machine_insert(BYTEY_STREAM *ins, BYTEY_STREAM *outs) {
  // --- input --- //
  // get sizeof
  size_t _sizeof;
  if (byread(ins, &_sizeof, sizeof(_sizeof))) {
    ERR("BY_INSERT - Uncompleted Opcode 0");
    return true;
  }

  // get value
  void *value = malloc(_sizeof);
  if (byread(ins, value, _sizeof)) {
    ERR("BY_INSERT - Uncompleted Opcode 1");
    return true;
  }

  // --- output --- //
  if (bywrite(outs, value, _sizeof)) {
    ERR("BY_INSERT - bywrite(outs) failed");
    return true;
  }

  return false;
}

// END

bool byin_parse(BYTEY_STREAM *ins, BYTEY_STREAM *outs) {
  BY_OPCODE_TYPE opcode = bygetop(ins);
  for (; opcode != BY_EOF; opcode = bygetop(ins)) {
    switch (opcode) {
    // directives
    // program memory
    case BY_FILL:
      if (byin_write_machine_fill(ins,outs)) return true;
      break;
    case BY_INSERT:
      if (byin_write_machine_insert(ins,outs)) return true;
      break;
    // control flow 
    // error handling
    default:
      ERR("Invalid opcode in bytey file");
      return true;
    };
  }
  return false;
}