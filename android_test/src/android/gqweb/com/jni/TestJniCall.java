package android.gqweb.com.jni;

public class TestJniCall {
	public native String callTestFun(String name);  
	
	static {
		System.loadLibrary("android_jni");
		System.out.println("load lib suc!");
	}
} 
   