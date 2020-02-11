#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>

void main(int argc, char *argv[])
{
	char	fname[80], buf[80], prgarg[80];
	int	i;
  if(argc < 2) {
    fprintf(stderr,"usage bc_cpp filename.c/cpp\n");
    exit(1);
  }
  *prgarg = 0;
  for(i=1; i<argc; i++) {
    if(*argv[i] == '/' || *argv[i] == '-')
      sprintf(prgarg + strlen(prgarg), "%s ", argv[i]);
    else
      strcpy(fname, argv[i]);
  }
  if(access(fname, 0) != 0) {
    fprintf(stderr,"%s : access denied\n", fname);
    exit(1);
  }
  sprintf(buf, "wcl386 /c %s %s", prgarg, fname);
  system(buf);
  system("wpp2con");
  for(i=0;i<strlen(fname);i++) {
    if(fname[i] == '.') {
      sprintf(fname + i, ".err");
      break;
    }
  }

  if(access(fname, 0) == 0)
    unlink(fname);

}