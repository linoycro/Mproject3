#include <stdio.h>
#include "List.h"
#include <stdlib.h>

int main(){

    char* words[100] = NULL;
    int wordsC = 0, indx = 0;
    List* lst = StrList_alloc();
    int choice = 0;
    scanf("%d", &choice)

    if (choice == 1){
        scanf("%d", &wordsC)           
        for(int i=0; i<wordsC; i++){
            scanf("%s", words);
            words = (char *)malloc(100 * sizeof(words));
            StrList_insertLast(lst, words);
        }
    }

    if (choice == 2){
        scanf("%d", indx);
        scanf("%s", words);
        words = (char *)malloc(100 * sizeof(words));
        StrList_insertAt(lst, words, indx);
        
    }

    if (choice == 3){
        StrList_print(lst);
    }

    if (choice == 4){
        printf("%d", StrList_size(lst));
    }

    if (choice == 5){
        scanf("%d", indx)
        StrList_printAt(lst, indx);
    }

    if (choice == 6){
        printf("%d", StrList_printLen(lst));
    }

    if (choice == 7){
        scanf("%s", words);
        printf("%d", StrList_count(lst, worda));
    }

    if (choice == 8){
        scanf("%s", words);
        StrList_remove(lst, words);
    }

    if (choice == 9){
        scanf("%s", words);
        StrList_removeAt(lst, words);
    }

    if (choice == 10){
        StrList_reverse(lst);
    }

    if (choice == 11){
        lst == NULL;
    }

    if (choice = 12){
        StrList_sort(lst);
    }

    if (choice == 13){
        StrList_isSorted(lst);
    }

    if (choice == 0){
        return 0;
    }


}