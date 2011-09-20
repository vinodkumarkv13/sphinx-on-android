package android.gqweb.com;

import android.app.Activity;
import android.gqweb.com.jni.SphinxJniCall;
import android.os.Bundle;

public class Android_testActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        SphinxJniCall jni = new SphinxJniCall();
        //jni.callTestFun("gqw"); 
    }
}