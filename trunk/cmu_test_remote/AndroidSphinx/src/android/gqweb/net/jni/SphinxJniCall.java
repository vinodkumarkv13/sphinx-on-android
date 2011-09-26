package android.gqweb.net.jni;



public class SphinxJniCall {
	private boolean bInit = false;
	
	public boolean isbInit() {
		return bInit;
	}
	public void setbInit(boolean bInit) {
		this.bInit = bInit;
	}
	//public native String callTestFun(String name); 
	public native boolean initSphinx();
	public native boolean startSphinxRecord();
	public native boolean stopSphinxRecord();
	public native String getSphinxRecognizedStr();
	public native boolean destroySphinx();
	
	static {
		System.loadLibrary("adsphinxbase");
		System.loadLibrary("adpocketsphinx");
		System.loadLibrary("android_exe");
		System.out.println("load lib suc!"); 
	}
} 
   