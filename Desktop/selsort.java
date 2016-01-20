import java.util.*;

class selsort
{

public static void selsort()
{
int min,i,j;
int temp;
int arr[] = new int[15];

for( i=0;i<arr.length-1;i++);
min = i;

for(j=i+1;j<arr.length;j++)
{

if(arr[j]<arr[min])
{

min = j;
}

else
{

temp = arr[i];
arr[i]=arr[min];
arr[min]=temp;
}
}
}


public static void main(String args[])
{

int arr[] = {5,1,12,-5,16,2,12,14};
System.out.println("enter the elements");
Scanner i = new Scanner(System.in);
int input = i.nextInt();

for(int z =0;z<arr.length;z++)
{

arr[z]=i.nextInt();
}

selsort();
System.out.println("values after sorting");
for(int l =0;l<arr.length;l++)
System.out.println(arr[l]);
}
}
