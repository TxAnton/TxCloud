#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

char* list_dir(const char *dirPath, char u)
{
    DIR *dir = opendir(dirPath);  
    if(dir) { 
        struct  dirent *de = readdir(dir);  
        while (de) {  
            char *st = malloc(strlen(dirPath)+strlen(de->d_name)+2);
            strcpy(st,dirPath); strcat(st,"/"); strcat(st,de->d_name);
            char* h;
            if (((de->d_name)[0])!='.') h = list_dir(st,u);
            else h = NULL;
            if (h){
            	return h;
            }
            else {
            	FILE* file = fopen(st,"r");
            	if (file){
            		if (((de->d_name)[0] == u) && ((de->d_name)[1] == '.')){
            			return st;
            		}
              	}
            }
            de = readdir(dir);
			free(st);
        }
        return NULL;
    }
    closedir(dir); 
	return NULL;
}

int main(){
	char s[255];
	char *way;
	char str[] = "./tmp";
	int i;
	scanf("%s", s);  
	while(s[i]!='\0'){
		way = list_dir(str,s[i]);
		if (way) {
			printf("%s\n",way+2);
			free(way);
		}
		i++;					     	
	}
}
