package android.gqweb.com;

import android.app.Activity;
import android.gqweb.com.jni.TestJniCall;
import android.os.Bundle;

public class Android_testActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        TestJniCall jni = new TestJniCall();
        jni.callTestFun("gqw"); 
    }
}