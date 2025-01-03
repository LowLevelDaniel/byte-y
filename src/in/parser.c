#include "bytey/in/parser.h"


// Move This

bool byin_write_machine_ihlt(BYTEY_IN_READER *byin) { // halt for interrupt
  char opcode;
  switch (byin->arch) {
  case BYTEY_ARCH_TYPE_X86:
    opcode = 0xF4;
    if (by_write(byin->writer, &opcode, sizeof(char))) return true;
    
  default:
    ERR("Invalid Architecture"); 
  }
  return false;
}

// END(Move This)

bool byin_parse(BYTEY_IN_READER *byin) {

  for (BY_OPCODE_TYPE opcode = bygetc(byin->reader); opcode != BY_EOF; opcode = bygetc(byin->reader)) {
    switch (opcode) {
    // directives

    // memory
    case BY_FILL:
      ERR("BY_FILL is NotImplementedYet");
      return true;
    // control flow 
    case BY_IHLT: if (byin_write_machine_ihlt(byin)) return true; break;
    // error handling
    default:
      ERR("Invalid opcode in bytey file");
      return true;
    };
  }
}