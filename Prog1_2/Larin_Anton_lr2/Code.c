#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define FIELD_LEN 80

typedef struct MusicalComposition{
	char* name;
	char* author;
	int year;
	struct MusicalComposition* next;
}MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n); // creates 'MusicalComposition' list

void push(MusicalComposition*  head, MusicalComposition* element); // pushes 'element' at the tail of 'musical_composition_list'

void removeEl (MusicalComposition*  head, char* name_for_remove); // removes 'element' which 'name' equals  'name_for_remove'

int count(MusicalComposition*  head); // returns number of elements

void print_names(MusicalComposition*  head); // prints names of composition


int main(){
    int length;
    scanf("%d\n", &length);  

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    for (int i=0;i<length;i++)
    {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;

    char name_for_remove[80];

    fgets(name_for_push, 80, stdin);
    fgets(author_for_push, 80, stdin);
    fscanf(stdin, "%d\n", &year_for_push);
    (*strstr(name_for_push,"\n"))=0;
    (*strstr(author_for_push,"\n"))=0;

    MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

    fgets(name_for_remove, 80, stdin);
    (*strstr(name_for_remove,"\n"))=0;

    printf("%s %s %d\n", head->name, head->author, head->year);
    int k = count(head);

    printf("%d\n", k);
    push(head, element_for_push);

    k = count(head);
    printf("%d\n", k);

    removeEl(head, name_for_remove); 
    print_names(head);

    k = count(head);
    printf("%d\n", k);

    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    free(names);
    free(authors);
    free(years);

    return 0;

}

MusicalComposition* createMusicalComposition(char* name, char* author, int year){
	MusicalComposition* Node = malloc(sizeof(MusicalComposition));
	
	Node->name = malloc(FIELD_LEN * sizeof(char));
	Node->author = malloc(FIELD_LEN * sizeof(char));
	Node->year = year;
	Node->next = NULL;
	
	strncpy(Node->name, name, FIELD_LEN);
	strncpy(Node->author, author, FIELD_LEN);
	
	return Node;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
	MusicalComposition* head = n?createMusicalComposition(array_names[0], array_authors[0], array_years[0]):NULL;
	if(!n)return NULL;
	MusicalComposition* tmp = head;
	
	for(int i = 1; i < n; i++){
		tmp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		tmp = tmp->next;
		tmp->next = NULL;
	}
	
	return head;
}

void push(MusicalComposition*  head, MusicalComposition* element){
	MusicalComposition* it = head;
	while(it->next)it = it->next;
	it->next = malloc(sizeof(MusicalComposition));
	*(it->next) = *element;
	it->next->next=NULL;
	return;
}

void removeEl (MusicalComposition*  head, char* name_for_remove){
	MusicalComposition* dat = NULL;
	for(MusicalComposition* it = head;it; it = it->next){
		if(!strcmp(it->name, name_for_remove)){
			if(!dat){
				void* lnk = head->next;
				(*head)=*(head->next);
				free(lnk);
			}
			else{
				dat->next = it->next;
				free(it);
				return;
			}
		}
		dat = it;
	}
}

int count(MusicalComposition*  head){
	int i = 0;
	while(head){i++;head=head->next;}
	return i;
}

void print_names(MusicalComposition*  head){
	MusicalComposition* dat = NULL;
	for(MusicalComposition* it = head;it; it = it->next){
		printf("%s\n",it->name);
	}
}
