#ifndef BY_GLOBAL_IO_IMPL
#define BY_GLOBAL_IO_IMPL

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>

enum BY_VALUE_TYPE {
  // Signed
  BY_VALUE_TYPE_SIGNED_8 = 0,
  BY_VALUE_TYPE_SIGNED_16 = 1,
  BY_VALUE_TYPE_SIGNED_32 = 2,
  BY_VALUE_TYPE_SIGNED_64 = 3,

  // Unsigned
  BY_VALUE_TYPE_UNSIGNED_8 = 10,
  BY_VALUE_TYPE_UNSIGNED_16 = 11,
  BY_VALUE_TYPE_UNSIGNED_32 = 12,
  BY_VALUE_TYPE_UNSIGNED_64 = 13,

  // Floating
  BY_VALUE_TYPE_FLOAT_32 = 20,
  BY_VALUE_TYPE_FLOAT_64 = 21
};

struct Token {
  BY_OPCODE_TYPE type;
};

// Directive

// Program
struct TokenProgram {
  BY_OPCODE_TYPE type;
  size_t multiple;
  size_t bytes_sizeof;
  void *bytes;
};

// Value Tokens
struct TokenBaseVal {
  BY_OPCODE_TYPE type;
  enum BY_VALUE_TYPE valtype;
};
struct TokenImm {
  BY_OPCODE_TYPE type;
  enum BY_VALUE_TYPE valtype;
  union {
    int64_t i;
    uint64_t u;
    long double f;
  } val;
};
struct TokenVar { // register / stack
  BY_OPCODE_TYPE type;
  enum BY_VALUE_TYPE valtype;
  unsigned long int reg;
  unsigned long int offset;
};
struct TokenAddr {
  BY_OPCODE_TYPE type;
  enum BY_VALUE_TYPE valtype;
  union {
    char *symbol;
    unsigned long long int addr;
  } val;
  bool issymbol;
};

// Control Flow
struct TokenCtrlFlow {
  BY_OPCODE_TYPE type;
  struct Token *address;
};

// Operand
struct TokenOperand {
  BY_OPCODE_TYPE type;
  struct Token *operand1;
  struct Token *operand2;
  struct Token *result;
};

#ifdef __cplusplus
}
#endif

#endif // BY_GLOBAL_IO_IMPL