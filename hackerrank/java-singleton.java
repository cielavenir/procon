import java.util.*;
import java.lang.reflect.*;
class Singleton{
	private static Singleton singleton=new Singleton();
	public String str;
	private Singleton(){}
	public static Singleton getSingleInstance(){return singleton;}
}