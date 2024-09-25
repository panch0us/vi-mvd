#include <stdio.h>
#include <stdlib.h>

int main()
{
    // create list
    
    int array[5] = {1, 2, 3, 4, 5};   

    struct item {
        int data;
        struct item *next;
    };


    struct item *int_arr_to_list(const int *arr, int len){
        struct item *first = NULL, *last = NULL, *tmp;
        int i;
        
        for(i = 0; i < len; i++){
            tmp = malloc(sizeof(struct item));
            tmp->data = arr[i];
            tmp->next = NULL;
            
            if(last){
                last->next = tmp;
                last = last->next;
            } else {
                first = last = tmp;
            }
        }
        return first;
    }

    // test
    struct item *result; 
    result = int_arr_to_list(array, 5);
    
    int b;
    for(b = 0; b < 5; b++){
        printf("%d\n", result->data);
        result = result + 2;
    }
        
}
