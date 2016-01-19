import java.util.*;

class BubbleSort
{

public static void main(String args[])

{
int temp;
System.out.println("enter the number of elements to sort");
Scanner item = new Scanner(System.in);
int in = item.nextInt();
int array[] = new int[in];

for(int z=0;z<array.length;z++)
array[z]=item.nextInt();

for(int i=0;i<array.length;i++)
for(int j=i+1;j<array.length;j++)
if(array[i] > array[j])
{

temp=array[i];
array[i]=array[j];
array[j]=temp;
}

System.out.println("sorted list");
for(int k=0;k<array.length;k++)
System.out.println(array[k]);
}
}

