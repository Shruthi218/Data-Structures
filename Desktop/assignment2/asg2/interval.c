#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct job {
  char ID;
  int startTime;
  int finishTime;
};

int compare(const void * j1, const void* j2) {
  int left = ((struct job *)j1)->finishTime;
  int right = ((struct job *)j2)->finishTime;
  return (left - right);
}


void scheduleJobs(struct job jobs[], int size) {
 
 char result[size]; /* assuming max elements in result cannot exceed total lines in input */
  int m, k = 0, i = 0, j = 0;
 result[i] = jobs[i].ID;
 for( m = 1; m<=size; m++) {
   if(jobs[m].startTime >= jobs[k].finishTime) {
      result[++i] = jobs[m].ID;
      k = m;
   }
 }   
 
 int result_size = sizeof(result)/sizeof(result[0]);
  for(; j < result_size; j++) {
   if(isalpha(result[j])) 
   printf("%c \n", result[j]);
  }
}



int main(int argc, char **argv) {
 int i = 0;
 int j;
  char buffer[100];
 struct job jobs[1000];
struct job temp = {'z', -1, -1};;
   if(argc!=2) exit(1);
 

   FILE *fp = fopen(argv[1], "r");

   if(fp == NULL) exit(1);
   else {
     while(fgets (buffer, 100, fp) != NULL) {
        char *lstr = strtok(buffer, " ");
        char *rstr = strtok(NULL, " ");
        char *sstr = strtok(NULL, "\n");
        char tempID = *lstr;

        jobs[i].ID = tempID;
        jobs[i].startTime = atoi(rstr);
        jobs[i].finishTime = atoi(sstr);
        i++;
     }
   }
   qsort(jobs, i, sizeof(temp), compare); 
   scheduleJobs(jobs, i);  
   

}    
