import java.util.*;
class Delimiter
{

public static void main(String args[])
{

String s  = new String("abc:def:ghi:klm:pqr");
String result[]=s.split(":");
System.out.println("after splitting");

for(String sstr: result)
{
System.out.println(sstr);
}
}
}
