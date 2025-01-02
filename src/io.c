#include "bytey/io.h"

char bygetc(FILE *srcf) {
  char in;
  for (in = fgetc(srcf);; in = fgetc(srcf)) {
    if (in == EOF) return EOF;
    if (in != ' ' && in != '\n' && in != '\t') break;
  }
  return in;
}