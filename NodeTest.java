public class NodeTest {

	

	 int data;

	private NodeTest next;

	private NodeTest head=null;

         NodeTest cur;

NodeTest()

{

	next = null;

}




public void findduplicate()
{

NodeTest cur = head;
int data;

if(cur.data == cur.next.data)
{

System.out.println("duplicate found" + cur.data);
cur = cur.next;
}

else
{

System.out.println("no duplicate found");
}

}
public void insert(int key)

{



	NodeTest n = new NodeTest();

	n.data = key;

	

	if(head == null)

	{

		head = n;

	}

	

	else

	{

		n.next = head;

		head = n;

	}

	}





public void countnodes()
{

int count =0;

NodeTest cur = head;

for(cur = head;cur!=null;cur = cur.next)
{
count++;
}

System.out.println(count);
}


public void display()

{



	NodeTest cur = head;

	



	while(cur!=null)

	{

		System.out.print(cur.data + "-");

		cur = cur.next;



	}

	System.out.println();

}







	

public static void main(String args[])

{

	

	NodeTest n1 = new NodeTest();

	n1.insert(10);

	n1.insert(30);
        n1.insert(30);  
	n1.insert(40);

        n1.insert(40);
        
       

	n1.display();
        n1.countnodes();
        n1.findduplicate();
        

}

}




