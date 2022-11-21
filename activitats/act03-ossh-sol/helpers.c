#include <string.h> // strstr()
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include "helpers.h"
#include <assert.h>

int read_line(char** line){
  size_t buffer_size = 0;

 if (getline(line, &buffer_size, stdin) == -1){
      perror("read_line():getline");
      return -1;
  }

  return 0;
}

int split_line(char *line, char* separator, char ***tokens){

  const size_t BUFSIZE = 100;   
  size_t bufsize = BUFSIZE;
  int position = 0; 
  *tokens = malloc(BUFSIZE * sizeof(char*));
  if (!tokens) {
      fprintf(stderr, "split_line():malloc(): allocation error\n");
      return -1;
  }
  char** _tokens = *tokens;
  char *token = malloc(BUFSIZE * sizeof(char));
  token=strtok(line, separator); 
  while (token != NULL) {
    _tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += BUFSIZE;
      _tokens = realloc(_tokens, BUFSIZE * sizeof(char*));
      if (!_tokens) {
        fprintf(stderr, "split_line():realloc() allocation error\n");
        return -1;
      }
    }
    token = strtok(NULL, separator);
  }
  _tokens[position] = '\0';
  return position;
}


int contains_invalid_chars(char* word, char** invalid_chars, size_t s_invalid_chars){
 int res = NOT_INVALID;
 assert (word != NULL && invalid_chars != NULL);
 for (int c=0; c<s_invalid_chars;c++) {
    if ( strstr(word, invalid_chars[c]) != NULL ){
      res = INVALID;
      break;
    }
  }
  return res;
}

