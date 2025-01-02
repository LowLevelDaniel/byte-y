#ifndef BY_GLOBAL_IO_IMPL
#define BY_GLOBAL_IO_IMPL

#define SNL "\n"
#define NL '\n'

#include <stdio.h>

#define LOG(msg, ...) printf("INFO: " msg SNL, ##__VA_ARGS__)
#define ERR(msg, ...) printf("ERR: " msg SNL, ##__VA_ARGS__)
#define WARN(msg, ...) printf("WARNING: " msg SNL, ##__VA_ARGS__)

#ifdef __cplusplus
extern "C"
#endif
char bygetc(FILE *srcf);

#endif // BY_GLOBAL_IO_IMPL