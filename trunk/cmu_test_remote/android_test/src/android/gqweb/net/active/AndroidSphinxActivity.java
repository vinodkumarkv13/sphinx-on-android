package android.gqweb.net.active;

import android.app.Activity;
import android.gqweb.com.R;
import android.gqweb.net.jni.SphinxJniCall;
import android.os.Bundle;

public class AndroidSphinxActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        SphinxJniCall jni = new SphinxJniCall();
        //jni.callTestFun("gqw"); 
    }
}