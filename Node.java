class Node
{

private Node next;
private int data;
private Node head=null;

private Node tail=null;

Node()
{

//int data =d;
next = null;
}

public void insert(int d)
{

Node n = new Node();
n.data=d;

if(head==null)
{
head = tail = n;
}

else if(head.next==null)
{
/*working code
//n.next = head;
//head = n;
*/
head.next = n;
tail = n;
}
else
{
tail.next=n;
tail = n;
tail.next = null;

}
}


public void sortedinsert(int d1)
{

Node cur = head;

if(cur.data<d1.data)
{


public void display()
{

Node cur = head;

while(cur!=null)
{
System.out.println(cur.data + "->");
cur = cur.next;
}
System.out.println();
}

public static void main(String args[])
{

Node n1 = new Node();
n1.insert(5);

n1.insert(7);
n1.insert(8);
n1.display();
}
}
