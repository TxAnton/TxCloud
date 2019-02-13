#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

int list_dir(const char *dirPath,int op,int level)
{
	int res = op&&1;
	int c,a;
    DIR *dir = opendir(dirPath);					//"открываем" директорию
    if(dir){ 										// если это удалось успешно
        struct dirent *de = readdir(dir);  			// получаем очередной элемент открытой директории
        while (de){  								// если это удалось
            for(int i = 0;i<level;i++)putchar('\t');
			printf("%0.0s/%s\n", dirPath, de->d_name); // печатаем имя этого элемента
            
            char* str = malloc(strlen(dirPath) + strlen(de->d_name) + 1);
	        strcpy(str,dirPath);strcat(str, "/");strcat(str, de->d_name);
	        
            if(de->d_type == DT_DIR){
            //if(!strchr(de->d_name, '.')){
            	
            	
            	if(!strstr(de->d_name,".")){
	            	
	            	a = list_dir(str,de->d_name[0]-'a',level+1);
	            	res = op?res*a:res+a;
	            	//directory
            	}
            }
            else{
            	FILE * ptrFile = fopen(str, "r");
            	if(ptrFile){
	            	c = fscanf(ptrFile,"%d ",&a);
	            	while(c!=-1){
	            		res = op?res*a:res+a;
	            		c = fscanf(ptrFile,"%d ",&a);
	            	}
	            	
	            	fclose (ptrFile);
            	}
            	else printf(str);
            	//file
            	printf("\nFILE %s DONE %d\n",de->d_name,res);
            }
            de = readdir(dir);						// снова получаем очередной элемент открытой директории
        }
    }
    closedir(dir); 									// не забываем "закрыть" директорию
    return res;
}

int main(){
	char str[] = "./root";
	DIR *dir = opendir(str);
	int val = 0;
	//readdir(dir)->d_name[0]-'a';
	FILE * ptrFile = fopen("result.txt", "w");
	val = list_dir(str,readdir(dir)->d_name[0]-'a',0);
	fprintf(ptrFile,"%d",val);
	printf("%d",val);
	closedir(dir);
	fclose (ptrFile);
	return 0;	
}
