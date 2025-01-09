#include "bytey/main.h"
#include "src/in/lex.h"
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

bool byin_get_type(BYTEY_STREAM *ins, struct TokenBaseVal *val) {
  char byte = bygetc(ins);
  switch (byte) {
  case BY_TYPE_SB:
    break;
  case BY_TYPE_UB:
    break;
  case BY_TYPE_SW:
    break;
  case BY_TYPE_UW:
    break;
  case BY_TYPE_SL:
    break;
  case BY_TYPE_UL:
    break;
  case BY_TYPE_SQ:
    break;
  case BY_TYPE_UQ:
    break;

  case BY_TYPE_FH:
    break;
  case BY_TYPE_FF:
    break;
  case BY_TYPE_FD:
    break;
  case BY_TYPE_FL:
    break;
  default:
    ERR("Invalid Type");
    return true;
  }
  return false;
}

// END

bool byin_lex(BYTEY_STREAM *ins, BYTEY_STREAM *outs, BYTEY_ARENA *arena) {
  for (BY_OPCODE_TYPE opcode = bygetop(ins); opcode != BY_EOF; opcode = bygetop(ins)) {
    union {
      struct TokenProgram prog;
      struct TokenImm imm;
      struct TokenVar var;
      struct TokenAddr addr;
    } tok;
    switch (opcode) {
    // DIRECTIVE
    // PROGRAM
    case BY_PROGRAM_INSERT: {
      tok.prog.type = BY_PROGRAM_INSERT;
      tok.prog.multiple = 1;

      if (byread(ins, &tok.prog.bytes_sizeof, sizeof(tok.prog.bytes_sizeof))) {
        ERR("BY_PEROGRAM_INSERT - 0");
        return true;
      }

      struct TokenProgram *tokbuf = (struct TokenProgram *)BYTEY_ARENA_CURRBUFF(arena);
      BYTEY_ARENA_PUSH(arena, &tok, sizeof(tok.prog) + tok.prog.bytes_sizeof - sizeof(tok.prog.bytes));

      if (byread(arena, &tokbuf.bytes, tok.prog.bytes_sizeof)) {
        ERR("BY_PEROGRAM_INSERT - 1");
        return true;
      }
      break;
    } case BY_PROGRAM_FILL: {
      tok.prog.type = BY_PROGRAM_FILL;

      if (byread(ins, &tok.prog.multiple, sizeof(tok.prog.multiple))) {
        ERR("BY_PEROGRAM_FILL - 0");
        return true;
      }

      if (byread(ins, &tok.prog.bytes_sizeof, sizeof(tok.prog.bytes_sizeof))) {
        ERR("BY_PEROGRAM_FILL - 1");
        return true;
      }

      struct TokenProgram *tokbuf = (struct TokenProgram *)BYTEY_ARENA_BUFFER(arena);
      BYTEY_ARENA_PUSH(arena, &tok, sizeof(tok.prog) + tok.prog.bytes_sizeof - sizeof(tok.prog.bytes));

      if (byread(arena, &tokbuf.bytes, tok.prog.bytes_sizeof)) {
        ERR("BY_PEROGRAM_FILL - 2");
        return true;
      }
      break;
    }
    // VALUE
    case BY_VALUE_VAR: {
    } 
    // ERROR
    default:
      ERR("Invalid directive opcode'" BY_OPCODE_PRINT "'", opcode);
      return true;
    }
  }

  return false;
}



bool byin_parse(BYTEY_STREAM *ins, BYTEY_STREAM *outs) {
  
  return false;
}