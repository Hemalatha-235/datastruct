#include <stdio.h>
#include <string.h>

void isPalindromeString(char str[]) {
   int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return false;
    }
    return true;
}
  int main() {
    char str[MAX];

    printf("Enter a string: ");
  
    scanf("%s", str); 

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}