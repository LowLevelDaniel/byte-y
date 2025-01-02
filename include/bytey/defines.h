/*
* Essentialy the grammar of bytey
* helpful when parsing and writing bytey files
*
*/
// --- TOKENS --- //

// --- LEAFS --- //

// --- BYTEY OPCODE --- //
// other
#define BY_COMPILER_INTERACT 0x01
#define BY_GLOBAL 0x02
#define BY_IDENT 0x03
#define BY_FILL 0x04
// control flow
#define BY_DECLARE_SYMBOL 0x10
#define BY_DECLARE_OPTIMIZED_SYMBOL 0x11
#define BY_CALL 0x12
#define BY_JMP 0x13
#define BY_RET 0x14
#define BY_SCOPE 0x15 // stack scope
#define BY_IHLT 0x16 // interrupt halt
// operands
#define BY_CMP 0x20
#define BY_ADD 0x21
#define BY_SUB 0x22
#define BY_DIV 0x23
#define BY_MUL 0x24
#define BY_MOD 0x25
// error handling
#define BY_EOF 0x00 // EOF is converted to this in bygetc

