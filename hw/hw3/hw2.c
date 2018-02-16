/*
    JTSK-320111
    hw2.c
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
/*
 Inserts a new int at the beginning of the list         list: list where element should be inserted             value: integer to be inserted
 Returns the updated list
 */
struct list {
    int info;
    struct list* next;
};

struct list* push_front(struct list *my_list, int value)
{
    struct list *newel;
    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}


/* Like the previous one, but inserts at the end */
struct list* push_back(struct list* my_list, int value)
{
	struct list *cursor, *newel;

	cursor = my_list;
	newel = (struct list*) malloc(sizeof(struct list));
	if (newel == NULL) {
		printf("Error allocating memory\n");
		exit(1);
	}
	newel->info = value;
	newel->next = NULL;
	if (my_list == NULL)
		return newel;
	while (cursor->next != NULL)
      cursor = cursor->next;
  cursor->next = newel;
  return my_list;
}


void print_elements(struct list* my_list)
{
	while (my_list != NULL) {
		printf("%d ", my_list->info);
		my_list = my_list->next;
	}
	printf("\n");
}

void dispose_list(struct list* my_list)
{
   struct list *nextelem;
   while (my_list != NULL) {
      nextelem = my_list->next;
      free(my_list);
      my_list = nextelem;
   }
}

struct list* insertAt(struct list* lst, int idx, int info){
    if(idx < 0){
        printf("Invalid position!\n");
        return lst;
    }
    if(idx > 0 && lst == NULL){
        printf("Invalid position!\n");
        return lst;
    }
    if(idx == 0){
        //insert at front
        return push_front(lst, info);
    } else {
        //not at front
        lst->next = insertAt(lst->next, idx - 1, info);
        return lst;
    }
}

struct list* reverse(struct list* lst){
    if(lst == NULL)
        return NULL;
    if(lst->next == NULL)
        return lst;
    int info = lst->info;
    struct list* tmp = lst->next;
    free(lst);
    return push_back(reverse(tmp), info);
}

int main(int argc, char** argv){
    char buf[100]; // buffer
    int input;

    int pos;
    char cmd;
    struct list* lst = NULL;

    while(1){
        // read the command
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &cmd);
        switch(cmd){
            case 'a':
                // read the int
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &input);
                // insertion
                lst = push_back(lst, input);
                break;
            case 'b':
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &input);
                // insertion
                lst = push_front(lst, input);
                break;
            case 'r':
                if(lst == NULL)
                    // invalid operation
                    exit(1);
                struct list* tmp = lst;
                lst = lst->next;
                free(tmp);
                break;
            case 'p':
                print_elements(lst); // simply print them
                break;
            case 'q':
                dispose_list(lst);
                exit(0); // quit the program
                break;
            case 'i':
                // insertion
                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &pos);
                //read the position

                fgets(buf, sizeof(buf), stdin);
                sscanf(buf, "%d", &input);
                // read the value

                lst = insertAt(lst, pos, input);
                break;
            case 'R':
                lst = reverse(lst);
            default:
                break;
        }
    }

    return 0;
}
