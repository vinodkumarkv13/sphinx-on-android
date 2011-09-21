package android.gqweb.net.active;

import android.app.Activity;
import android.gqweb.com.R;
import android.gqweb.net.jni.SphinxJniCall;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;


public class AndroidSphinxActivity extends Activity {
	private SphinxJniCall sphinxJniCall = new SphinxJniCall();
	private Button btnInit;
	private Button btnStart;
	private Button btnStop;
	private Button btnRecogStr;
	private TextView txtRecogStr;

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		
		//sphinxJniCall = new SphinxJniCall();
		
		btnInit = (Button) this.findViewById(R.id.btnInit);
		btnStart = (Button) this.findViewById(R.id.btnStart);
		btnStop = (Button) this.findViewById(R.id.btnStop);
		btnRecogStr = (Button) this.findViewById(R.id.btnRecogStr);
		txtRecogStr = (TextView) this.findViewById(R.id.recog_out_str);
		
		addBtnListenner();
		btnInit.setVisibility(Button.INVISIBLE);
		btnStop.setVisibility(Button.INVISIBLE);
		btnStart.setVisibility(Button.VISIBLE);
		btnRecogStr.setVisibility(Button.INVISIBLE);
		sphinxJniCall.initSphinx();
	}
	
	private void addBtnListenner() {
		btnInit.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				System.out.println("btnInit");
				//sphinxJniCall.initSphinx();
				
			}
		});
		
		btnStart.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				System.out.println("btnStart");
				btnStop.setVisibility(Button.VISIBLE);
				btnStart.setVisibility(Button.INVISIBLE);
				btnRecogStr.setVisibility(Button.INVISIBLE);
				sphinxJniCall.startSphinxRecord();
				
			}
		});
		
		btnStop.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				System.out.println("btnStop");
				btnStop.setVisibility(Button.INVISIBLE);
				btnStart.setVisibility(Button.VISIBLE);
				btnRecogStr.setVisibility(Button.VISIBLE);
				sphinxJniCall.stopSphinxRecord();
			}
		});
		
		btnRecogStr.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				System.out.println("btnRecogStr");
				String strRecog = "strRecog:";
				strRecog += sphinxJniCall.getSphinxRecognizedStr();
				txtRecogStr.setText(strRecog);
			}
		});
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
		sphinxJniCall.destroySphinx();
	}

}