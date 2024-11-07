#include <stdio.h>
#include <string.h>
/*
This program finds a certain substring within a user given string and gives the index where it starts
*/
int FindSub(char substring[], char string[]) {
    /*
    This functinon finds the substring within the string
    @substring: the user inputted substring that is checked for being in the string
    @string: the user inputted string
    @stringLength: the length of the original string
    @substringLength: the length of the substring
    */
    if (substring[0] == '\0') { //checks for empty substring
        return 0; 
    }

    int stringLength = strlen(string);
    int substringLength = strlen(substring);

    for (int i = 0; i <= stringLength - substringLength; i++) {
        //specified index length so that it does not go above the search string length
        int j;
        for (j = 0; j < substringLength; j++) { //cycles through the substring
            if (string[i + j] != substring[j]) { //if the specific letter in the search string does not equal the subtring letter...
                break; //checks the next letter
            }
        }
        if (j == substringLength) {
            return i; // Return starting index if substring is found
        }
    }
    return -1; // Return -1 if substring is not found
}

int main() {
    /*
    This function asks and gets the user inputted strings and calls the above function to compare them
    @searchString: The user inputted string
    @substring: the user inputted string that should be found in the search string
    @index: where the substring is first found in the string
    */

    char searchString[101];
    char substring[101];
    int index = 0;
    //fgets to read the entire line
    //strstr to compare?
    printf("Enter the string to search: ");
    fgets(searchString, sizeof(searchString), stdin);
    searchString[strcspn(searchString, "\n")] = '\0'; // Remove newline character

    printf("Enter the substring to search for: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0'; // Remove newline character

    // Call the find function to find the substring

    index = FindSub(substring, searchString);

    if (index >= 0) {
        printf("\"%s\" first appears at index %d in \"%s\".\n", substring, index, searchString);
    } else {
        printf("\"%s\" does not appear in \"%s\".\n", substring, searchString);
    }

}