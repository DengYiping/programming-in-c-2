#include "stack.h"
#include "string.h"

int isPalindromic(){
    char sentence[31*12 + 2]; //at most 30 characters long + 1 space
    //at most 12 of such a word
    //plus a line change and string termination \0
    fgets(sentence, sizeof(sentence), stdin); //directly obtain the sentence
    if(strcmp(sentence, "exit\n") == 0)
        exit(0); //case to exit
    int wordStart = 0;
    int wordEnd = 0;
    char* word;
    struct stack* s = createStack();
    // pushing
    for(int i = 0; sentence[i] != '\0'; i++){
        if(sentence[i] == ' ' || sentence[i] == '\n'){
            //if a new word
            wordEnd = i; // the end of a word
            word = (char*) malloc(sizeof(char) * (wordEnd - wordStart + 1));
            memcpy(word, sentence + wordStart, sizeof(char) * (wordEnd - wordStart)); //copy the word
            word[wordEnd - wordStart] = '\0'; //terminate the word
            wordStart = wordEnd + 1; //begin a new word
            push(word, s); // push into the stack
        }
    }

    wordStart = 0;
    wordEnd = 0;
    char* stackWord;
    for(int i = 0; sentence[i] != '\0'; i++){
        if(sentence[i] == ' ' || sentence[i] == '\n'){
            //if a new word
            wordEnd = i; // the end of a word
            word = (char*) malloc(sizeof(char) * (wordEnd - wordStart + 1));
            memcpy(word, sentence + wordStart, sizeof(char) * (wordEnd - wordStart)); //copy the word
            word[wordEnd - wordStart] = '\0'; //terminate the word
            wordStart = wordEnd + 1; //begin a new word
            stackWord = pop(s);
            if(strcmp(word, stackWord))
                return 0;
            free(word);
            free(stackWord);
        }
    }

    freeStack(s);
    return 1;
}

int main(int argc, char** argv){
    while(1){
        if(isPalindromic())
            printf("The sentence is palindromic by words!\n");
        else
            printf("The sentence is not palindromic by words!\n");
    }
    return 0;
}
