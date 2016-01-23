import java.util.*;


class IteratorDemo
{

public static void main(String args[])
{

ArrayList<Integer> al = new ArrayList<Integer>();
al.add(1);
al.add(2);
al.add(3);
al.add(4);
al.add(5);
al.add(6);
al.add(7);
System.out.println("contents are" +al);


Iterator<Integer> itt = al.iterator();
while(itt.hasNext())
{

int m = itt.next();
System.out.println("element" +m);

}

ListIterator<Integer> li = al.listIterator();
while(li.hasNext())
{

int z = li.next();
li.set(z + 5);
}


}
}


