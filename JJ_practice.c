#include <stdio.h>
#include <pthread.h>

struct value_set
{
	int num_val; // 1,2,3 ...
	char letter_val; // A, B, C , ...
};


void printing_function_str(struct value_set arg_var)
{

struct value_set fun_var=arg_var;
//printf("Starting printing_function_str\n");
printf("%c%d\n",fun_var.letter_val,fun_var.num_val);
//printf("Exiting printing_function_str\n");
}

void* printing_function_str2(void* arg_var2)
{

struct value_set* fun_var2=arg_var2;
//printf("Starting printing_function_str\n");
//printf("%c%d\n",fun_var2->letter_val,fun_var2->num_val);
printf("%d-%c\n",fun_var2->num_val,fun_var2->letter_val);	
//printf("Exiting printing_function_str\n");
}


int main()
{
printf("Starting main function\n");

int num_limit=26;
int num_val_start=1;
char letter_val_start='A';
struct value_set arr_JJJ[num_limit];

for (int i=0;i<num_limit;i++)
{
arr_JJJ[i].letter_val=letter_val_start+i;
arr_JJJ[i].num_val=num_val_start+i;
}


struct value_set var_JJJ;
var_JJJ.num_val=num_val_start;
var_JJJ.letter_val=letter_val_start;



/*
for (int j=0;j<num_limit;j++)
{
printing_function_str(arr_JJJ[j]);
}
*/

/*
for (int j=0;j<num_limit;j++)
{
printing_function_str2(&arr_JJJ[j]);
}
*/

/*
//pthread_t pt1;	//thread handle
pthread_t pt1,pt2,pt3;	//thread handle
pthread_create(&pt1,NULL,printing_function_str2,&arr_JJJ[0]);
pthread_create(&pt2,NULL,printing_function_str2,&arr_JJJ[1]);
pthread_create(&pt3,NULL,printing_function_str2,&arr_JJJ[2]);
pthread_join(pt1,NULL);
pthread_join(pt2,NULL);
pthread_join(pt3,NULL);
*/

pthread_t pt_arr[num_limit];	//thread handle

for (int j=0;j<num_limit;j++)
{
pthread_create(&pt_arr[j],NULL,printing_function_str2,&arr_JJJ[j]);
}

for (int j=0;j<num_limit;j++)
{
pthread_join(pt_arr[j],NULL);
}



printf("Exiting main function\n");
return 0;

}
