#include <stdio.h>

#include <stdlib.h>

#include <dirent.h>

#include<string.h>

#include <ctype.h>


#define vtos(v) ( *((char**)v) )


#define STRLEN 100

#define STRBLOCK 10


long long int findNumbers(char* strs){

	//int off1;

	long long int k = 0;

	int tmp = sscanf(strs, "%lld", &k);

	//int off2;

	return k;

}


int cmp(const void* a, const void* b){

	long long int c;c = findNumbers(vtos(a));

	long long int h;h = findNumbers(vtos(b));

	return c>h?1:c==h?0:-1;

}







void list_dir(const char *dirPath, char*** strs, int* i){

    DIR *dir = opendir(dirPath); 

	char* c = 0;

	char* str = NULL;

	char buf[STRLEN];

    if(dir) {

        struct  dirent *de = readdir(dir); 

        while (de) {

			str = malloc(strlen(dirPath) + strlen(de->d_name) + 2);

	        strcpy(str,dirPath);

			strcat(str, "/");

			strcat(str, de->d_name);

            FILE* tempFile = fopen(str, "r");

            if (tempFile){ // esli file otkrilysa 

				while(c = fgets(buf,STRLEN,tempFile)){

					char* tmp = strchr(buf,'\n');

					if(tmp)*tmp = '\0';

					if(!((*i)%STRBLOCK))(*strs) = realloc(*strs,((*i)+STRBLOCK)*sizeof(char*));

					(*strs)[(*i)]=malloc(STRLEN * sizeof(char));

					strcpy((*strs)[(*i)],buf);

					(*i)++;

					

				}

            	fclose(tempFile);

			}

			else{

				if (!strchr(de->d_name, '.'))

					list_dir(str, strs,i);

				}

			de = readdir(dir);

			free(str);

        }

    }

    closedir(dir);   

}



int main(){

	int i = 0;

	char path[] = "./tmp";

	char** strs = NULL;

	FILE* file = fopen("result.txt","w");

	list_dir(path, &strs, &i);

	qsort(strs, i,sizeof(char*),cmp);

	for(int k=0; k<i; k++){

		fputs(strs[k],file);

		fputs("\n",file);

	}

	return 0;

}
