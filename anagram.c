#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>



/*
This program compares two strings and sees if they are annagrams
*/

bool CompareStrings(char string1[], char string2[]) {
/*
This function takes both strings and marks an x if letters of string 2 appear in string 1
@string1: the user inputted string
@string2: the user inputted string that they want to compare the first one to
@newString1: is always x's to later compare with newString2
@newString2: changes the letter to x is it is found in the first string
@length1, length2: the lengths of strings 1 and 2
*/

    char newString2[21] = {0};
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int count = 0;
    
    if (length1 != length2) { // If words are not the same length, they are not anagrams
        return false;
    }

    for (int i = 0; i < length1; ++i) { // For each letter in the first string
        for (int j = 0; j < length2; ++j) { 
            // Compare each letter in the first string to all letters in the second one
            if (tolower(string1[i]) == tolower(string2[j]) && newString2[j] == 0) {
                // If a match is found and it's not already used in string2
                newString2[j] = '-'; // Mark this letter as used
                count++; // Increment count for each matched letter
                break;  // Move to the next character in string1
            }
        }
    }

    // If count matches the length of the strings, all characters were matched, so they are anagrams
    if (count == length2) {
        return true; // They are anagrams
    } else {
        return false; // They are not anagrams
    }
}

int main() {
    /*
    This function asks for and scans the users strings
    calls them later in the function
    */
    char string1[21];
    char string2[21];
    
    printf("Please enter the first word: ");
    scanf("%20s", string1);

    printf("Please enter the second word: ");
    scanf("%20s", string2);

    if (CompareStrings(string1, string2)) {
        printf("%s is an anagram of %s\n", string1, string2);
    } else {
        printf("%s is NOT an anagram of %s\n", string1, string2);
    }
}