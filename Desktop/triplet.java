import java.util.*;

class triplet
{

public static boolean trip(int arr[],int n)
{

// arr[] = new int[30];
for(int i=0;i<arr.length;i++)
{
arr[i]=arr[i]*arr[i];
}

Arrays.sort(arr);
int l=0;
int r = n-1;

int m = n;

for(int y=0;y<n-1;y++)
{
while(l<r)
{

if(arr[l]+arr[r]==arr[m])
{
System.out.println("triplet found");
return true;
}

if(arr[l]+arr[r]<arr[m])
l++;
else
r--;

}
}

return false;
}


public static void main(String args[]) throws Exception
{

int arr[] = {3,1,4,6,5};
int n = arr.length;
trip(arr,n);
}
}
