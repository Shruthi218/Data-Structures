class DeleteElement
{
public static int delete()
{
int n;
int i;
int arr[] = new int[10];
n = arr.length;
int x = 5;
for(i=0;i<n;i++)
if(arr[i]==x)
break;

if(i<=n)
{
n = n-1;
for(int k =1;k<n;k++)
arr[k] = arr[k+1];

}
return n;
}



public static void main(String args[])
{ 
int arr[] = {1,5,6,10,11};
int x = 5;
int n = arr.length;
n = delete();
for(int i =0;i<n;i++)


System.out.println("after deletion" +arr[i]);
}
}













