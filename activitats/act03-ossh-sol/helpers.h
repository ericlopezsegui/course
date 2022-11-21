#ifndef _HELPERS_H_
#define _HELPERS_H_

#define NOT_INVALID 0
#define INVALID 1

int split_line(char *line, char* separator, char ***tokens);
int read_line(char** line);
int contains_invalid_chars(char* word, char** invalid, size_t s_invalid_chars);

#endif