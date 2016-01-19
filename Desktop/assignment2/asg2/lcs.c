#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
//char X[MAX],Y[MAX];
//int c[MAX][MAX],b[MAX][MAX];
void printLCS(int b[MAX][MAX], const char *X, int i,int j);

void LCSlength(const char *X, const char *Y)

{
int i, j, m , n;
int c[MAX][MAX],b[MAX][MAX];
m=strlen(X);
n=strlen(Y);
for (i=1;i<=m;i++) c[i][0]=0;
for (j=0;j<=n;j++) c[0][j]=0;
for (i=1;i<=m;i++)
for (j=1;j<=n;j++) {
if (X[i-1]==Y[j-1]) {
c[i][j]=c[i-1][j-1]+1;
b[i][j]=1;
}
else if (c[i-1][j]>=c[i][j-1]) {
c[i][j]=c[i-1][j];
b[i][j]=2;
}
else {
c[i][j]=c[i][j-1];
b[i][j]=3;
}
}
printLCS(b, X, m, n);
printf("\n");
//return c[m][n];
}

void printLCS(int b[MAX][MAX], const char *X, int i,int j)

{
char print[100];
int l;
//if (i==0 || j==0) return;
if( i > 0 && j > 0) {
if (b[i][j]==1) {
printLCS(b, X, i-1,j-1);
printf("%c",X[i-1]);
}
else if (b[i][j]==2)
printLCS(b, X, i-1,j);
else
printLCS(b, X , i,j-1);
}

}


int main(int argc, char** argv) {

 char buffer[100];
 if(argc != 2) {
  printf("no input file\n"); 
  exit(1);
 }
 char word1[100][100], word2[100][100];
 
 int i = 0;
 int j;
 FILE *fp = fopen(argv[1],"r");
 if(fp == NULL) {
  printf("error opening file\n");  
  exit(1);
 }
 else {
    while(fgets(buffer, 100, fp) != NULL) {
      char *lstr = strtok(buffer, " ");
      char *rstr = strtok(NULL, "\n");
      strcpy(word1[i], lstr);
      strcpy(word2[i], rstr);
       i++;
    }
 }
for(j = 0; j < i; j++) {
LCSlength(word1[j], word2[j]);
 }

}
  

