#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_helpers.h"

int count_splits(const char* string, const char* delimiter) {
    /*
    This function counts the number of times the split word appreas in the string
    @string: the string the user put in the program
    @delimiter: the string that the original string is going to be split by
    @count: the number of times the delimiter appears in the string

    */
    int count = 1;  // At least one substring
    const char* temp = string;

    // Count occurrences of the delimiter in the string
    while ((temp = strstr(temp, delimiter)) != NULL) { //compares strings
        count++;
        temp += strlen(delimiter);  // Move past the delimiter
    }

    return count;
}

void allocate_splits(char*** splits, int len) {
    /*
    This function makes space for the length of each new string created from split
    @splits: output array to store the strings into
    @len: the number of strings in splits
    */
    *splits = (char**)malloc(len * sizeof(char*)); 
    
}

char* copy_substring(const char* start, const char* end) {
    /*
    copies the substring
    @start: the original string that the user input, cannot be changed
    @end: the end of the substring
    @substring = making space for the seperated string
    */
    int length = end - start; //
    char* substring = (char*)malloc(length + 1);  // +1 for null
    strncpy(substring, start, length);
    substring[length] = '\0';  //ends the string

    return substring;
}

void split(char* string, const char* const delimiter,
           char** *splits, int *len){
    /*
      Split string on delimiter into an array of strings.
      @param string: the string to split
      @param delimiter: the delimiter to split on
      @output_param splits: The output array to store the strings 
      into. Assume the value at *splits is uninitialized.   
      @output_param len: The number of strings in splits.
      Assume the value at *len is uninitialized.
      @start = the original string to split
      @end: the first character of the delimiter
    */

   if (string == NULL || delimiter == NULL) {
        *splits = NULL;
        *len = 0;
        return; //if nothing in the string, return nothing
    }

    // count how many substrings we need
    *len = count_splits(string, delimiter);

    // if there are no splits, return the entire string as one substring
    if (*len == 0) {
        *splits = (char**)malloc(sizeof(char*));
        (*splits)[0] = copy_substring(string, string + strlen(string));
        return; 
    }

    // allocate memory for the result array
    allocate_splits(splits, *len);

    const char* start = string; //new const char because modifying @strings
    int index = 0;

    while (index < *len) {
        const char* end = strstr(start, delimiter);
        if (end == NULL) {
            // copy the last substring if no delimiter is found
            (*splits)[index] = copy_substring(start, start + strlen(start));
            break;
        }

        // copy the substring before the delimiter
        (*splits)[index] = copy_substring(start, end);
        start = end + strlen(delimiter);  // move past the delimiter
        index++;
    }
}


char* read_any_len_line() {
    /*
    Read a line of any length from the user input. 
    The newline character, while read, is not included in the returned string.
    @returns: The next line of characters from the input stream
    @modifies: stdin
    */
    int capacity = 64;
    char* line = malloc(capacity);
    int length = 0;
    int ch;

    if (line == NULL) return NULL; // handle malloc failure

    // read characters until newline or end of input
    while ((ch = getchar()) != '\n') { //as long as the character read isn't a new line
        if (length + 1 >= capacity) { //len + 1 for the null space
            capacity *= 2; //makes more space for the capacity
            line = realloc(line, capacity); //makes memory for capacity
            if (line == NULL) return NULL; // handle realloc failure
        }
        line[length++] = (char) ch; //add char to line
    }

    line[length] = '\0'; // finishes the string with the null character
    return line;
}
