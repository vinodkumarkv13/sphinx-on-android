package android.gqweb.net.active;

import android.gqweb.net.R;
import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources.Theme;
import android.gqweb.net.jni.SphinxJniCall;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.os.Bundle;
import android.util.AttributeSet;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager.LayoutParams;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.TextView;

public class AndroidSphinxActivity extends Activity {
	private SphinxAppContext ctxSphinx;
	private Button btnInit;
	private Button btnStart;
	private Button btnStop;
	private Button btnRecogStr;
	private TextView txtRecogStr;
	private TextView txtDebugInfo;
	private ExpandableListView elvHmmPath;

	private String sDebugInfo;
	
	boolean bInited = false;

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		
		printDebugInfo("onCreate");
		
		ctxSphinx = (SphinxAppContext)getApplicationContext();
		if (ctxSphinx.getSphinxJniCall() == null) {
			ctxSphinx.setSphinxJniCall(new SphinxJniCall());
			ctxSphinx.getSphinxJniCall().initSphinx();
		}
		 
		btnInit = (Button) this.findViewById(R.id.btnInit);
		btnStart = (Button) this.findViewById(R.id.btnStart);
		btnStop = (Button) this.findViewById(R.id.btnStop);
		btnRecogStr = (Button) this.findViewById(R.id.btnRecogStr);
		txtRecogStr = (TextView) this.findViewById(R.id.recog_out_str);
		txtDebugInfo = (TextView) this.findViewById(R.id.debug_str);
		elvHmmPath = (ExpandableListView) this.findViewById(R.id.elv_hmm_path);
		

		addBtnListenner();
		btnInit.setVisibility(Button.INVISIBLE);
		btnStop.setVisibility(Button.INVISIBLE);
		btnStart.setVisibility(Button.VISIBLE);
		btnRecogStr.setVisibility(Button.INVISIBLE);

	}

	private void addBtnListenner() {
		btnInit.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				printDebugInfo("btnInit");
				//sphinxJniCall.initSphinx();

			}
		});

		btnStart.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				printDebugInfo("btnStart");
				btnStop.setVisibility(Button.VISIBLE);
				btnStart.setVisibility(Button.INVISIBLE);
				btnRecogStr.setVisibility(Button.INVISIBLE);
				ctxSphinx.getSphinxJniCall().startSphinxRecord();

			}
		});

		btnStop.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				printDebugInfo("btnStop");
				btnStop.setVisibility(Button.INVISIBLE);
				btnStart.setVisibility(Button.VISIBLE);
				btnRecogStr.setVisibility(Button.VISIBLE);
				ctxSphinx.getSphinxJniCall().stopSphinxRecord();
			}
		});

		btnRecogStr.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				printDebugInfo("btnRecogStr");
				String strRecog = "strRecog:";
				strRecog += ctxSphinx.getSphinxJniCall().getSphinxRecognizedStr();
				txtRecogStr.setText(strRecog);
			}
		});
	}
	
	public void printDebugInfo(String debugInfo) {
		System.out.println(debugInfo);
		sDebugInfo = sDebugInfo + "\r\n " + debugInfo;
		if (bInited) {
			txtDebugInfo.setText(sDebugInfo);
		}
	}


	@Override
	protected void onDestroy() {
		super.onDestroy();
		//sphinxJniCall.destroySphinx();
		printDebugInfo("@onDestroy");
		sDebugInfo += "\r\n @onDestroy";
		txtDebugInfo.setText(sDebugInfo);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// TODO Auto-generated method stub
		super.onActivityResult(requestCode, resultCode, data);
		printDebugInfo("@onActivityResult");
	}

	@Override
	protected void onApplyThemeResource(Theme theme, int resid, boolean first) {
		// TODO Auto-generated method stub
		super.onApplyThemeResource(theme, resid, first);
		printDebugInfo("@onApplyThemeResource");
	}

	@Override
	public void onAttachedToWindow() {
		// TODO Auto-generated method stub
		super.onAttachedToWindow();
		printDebugInfo("@onAttachedToWindow");
	}

	@Override
	public void onBackPressed() {
		// TODO Auto-generated method stub
		super.onBackPressed();
		printDebugInfo("@onBackPressed");
	}

	@Override
	protected void onChildTitleChanged(Activity childActivity,
			CharSequence title) {
		// TODO Auto-generated method stub
		super.onChildTitleChanged(childActivity, title);
		printDebugInfo("@onChildTitleChanged");
	}

	@Override
	public void onConfigurationChanged(Configuration newConfig) {
		// TODO Auto-generated method stub
		super.onConfigurationChanged(newConfig);
		printDebugInfo("@onConfigurationChanged");
	}

	@Override
	public void onContentChanged() {
		// TODO Auto-generated method stub
		super.onContentChanged();
		printDebugInfo("@onContentChanged");
	}

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		// TODO Auto-generated method stub
		printDebugInfo("@onContextItemSelected");
		return super.onContextItemSelected(item);
	}

	@Override
	public void onContextMenuClosed(Menu menu) {
		// TODO Auto-generated method stub
		super.onContextMenuClosed(menu);
		printDebugInfo("@onContextMenuClosed");
	}

	@Override
	public void onCreateContextMenu(ContextMenu menu, View v,
			ContextMenuInfo menuInfo) {
		// TODO Auto-generated method stub
		super.onCreateContextMenu(menu, v, menuInfo);
		printDebugInfo("@onCreateContextMenu");
	}

	@Override
	public CharSequence onCreateDescription() {
		printDebugInfo("@onCreateDescription");
		return super.onCreateDescription();
	}

	@Override
	protected Dialog onCreateDialog(int id, Bundle args) {
		// TODO Auto-generated method stub
		printDebugInfo("@onCreateDialog");
		return super.onCreateDialog(id, args);
	}

	@Override
	protected Dialog onCreateDialog(int id) {
		// TODO Auto-generated method stub
		printDebugInfo("@onCreateDialog");
		return super.onCreateDialog(id);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// TODO Auto-generated method stub
		printDebugInfo("@onCreateOptionsMenu");
		return super.onCreateOptionsMenu(menu);
	}

	@Override
	public boolean onCreatePanelMenu(int featureId, Menu menu) {
		// TODO Auto-generated method stub
		printDebugInfo("@onCreatePanelMenu");
		return super.onCreatePanelMenu(featureId, menu);
	}

	@Override
	public View onCreatePanelView(int featureId) {
		// TODO Auto-generated method stub
		printDebugInfo("@onCreatePanelView");
		return super.onCreatePanelView(featureId);
	}

	@Override
	public boolean onCreateThumbnail(Bitmap outBitmap, Canvas canvas) {
		// TODO Auto-generated method stub
		printDebugInfo("@onCreateThumbnail");
		return super.onCreateThumbnail(outBitmap, canvas);
	}

	@Override
	public View onCreateView(String name, Context context, AttributeSet attrs) {
		// TODO Auto-generated method stub
		printDebugInfo("@onCreateView");
		return super.onCreateView(name, context, attrs);
	}

	@Override
	public void onDetachedFromWindow() {
		// TODO Auto-generated method stub
		printDebugInfo("@onDetachedFromWindow");
		super.onDetachedFromWindow();
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		// TODO Auto-generated method stub
		printDebugInfo("@onKeyDown");
		return super.onKeyDown(keyCode, event);
	}

	@Override
	public boolean onKeyLongPress(int keyCode, KeyEvent event) {
		// TODO Auto-generated method stub
		printDebugInfo("@onKeyLongPress");
		return super.onKeyLongPress(keyCode, event);
	}

	@Override
	public boolean onKeyMultiple(int keyCode, int repeatCount, KeyEvent event) {
		// TODO Auto-generated method stub
		printDebugInfo("@onKeyMultiple");
		return super.onKeyMultiple(keyCode, repeatCount, event);
	}

	@Override
	public boolean onKeyUp(int keyCode, KeyEvent event) {
		// TODO Auto-generated method stub
		printDebugInfo("@onKeyUp");
		return super.onKeyUp(keyCode, event);
	}

	@Override
	public void onLowMemory() {
		printDebugInfo("@onLowMemory");
		// TODO Auto-generated method stub
		super.onLowMemory();
	}

	@Override
	public boolean onMenuItemSelected(int featureId, MenuItem item) {
		// TODO Auto-generated method stub
		printDebugInfo("@onMenuItemSelected");
		return super.onMenuItemSelected(featureId, item);
	}

	@Override
	public boolean onMenuOpened(int featureId, Menu menu) {
		// TODO Auto-generated method stub
		printDebugInfo("@onMenuOpened");
		return super.onMenuOpened(featureId, menu);
	}

	@Override
	protected void onNewIntent(Intent intent) {
		// TODO Auto-generated method stub
		printDebugInfo("@onNewIntent");
		super.onNewIntent(intent);
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// TODO Auto-generated method stub
		printDebugInfo("@onOptionsItemSelected");
		return super.onOptionsItemSelected(item);
	}

	@Override
	public void onOptionsMenuClosed(Menu menu) {
		// TODO Auto-generated method stub
		printDebugInfo("@onOptionsMenuClosed");
		super.onOptionsMenuClosed(menu);
	}

	@Override
	public void onPanelClosed(int featureId, Menu menu) {
		// TODO Auto-generated method stub
		printDebugInfo("@onPanelClosed");
		super.onPanelClosed(featureId, menu);
	}

	@Override
	protected void onPause() {
		printDebugInfo("@onPause");
		// TODO Auto-generated method stub
		super.onPause();
	}

	@Override
	protected void onPostCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		printDebugInfo("@onPostCreate");
		super.onPostCreate(savedInstanceState);
	}

	@Override
	protected void onPostResume() {
		printDebugInfo("@onPostResume");
		// TODO Auto-generated method stub
		super.onPostResume();
	}

	@Override
	protected void onPrepareDialog(int id, Dialog dialog, Bundle args) {
		// TODO Auto-generated method stub
		printDebugInfo("@onPrepareDialog");
		super.onPrepareDialog(id, dialog, args);
	}

	@Override
	protected void onPrepareDialog(int id, Dialog dialog) {
		// TODO Auto-generated method stub
		printDebugInfo("@onPrepareDialog");
		super.onPrepareDialog(id, dialog);
	}

	@Override
	public boolean onPrepareOptionsMenu(Menu menu) {
		// TODO Auto-generated method stub
		printDebugInfo("@onPrepareOptionsMenu");
		return super.onPrepareOptionsMenu(menu);
	}

	@Override
	public boolean onPreparePanel(int featureId, View view, Menu menu) {
		// TODO Auto-generated method stub
		printDebugInfo("@onPreparePanel");
		return super.onPreparePanel(featureId, view, menu);
	}

	@Override
	protected void onRestart() {
		// TODO Auto-generated method stub
		printDebugInfo("@onRestart");
		super.onRestart();
	}

	@Override
	protected void onRestoreInstanceState(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		printDebugInfo("@onRestoreInstanceState");
		super.onRestoreInstanceState(savedInstanceState);
	}

	@Override
	protected void onResume() {
		printDebugInfo("@onResume");
		// TODO Auto-generated method stub
		super.onResume();
	}

	@Override
	public Object onRetainNonConfigurationInstance() {
		// TODO Auto-generated method stub
		printDebugInfo("@onRetainNonConfigurationInstance");
		return super.onRetainNonConfigurationInstance();
	}

	@Override
	protected void onSaveInstanceState(Bundle outState) {
		// TODO Auto-generated method stub
		printDebugInfo("@onSaveInstanceState");
		super.onSaveInstanceState(outState);
	}

	@Override
	public boolean onSearchRequested() {
		// TODO Auto-generated method stub
		printDebugInfo("@onSearchRequested");
		return super.onSearchRequested();
	}

	@Override
	protected void onStart() {
		// TODO Auto-generated method stub
		printDebugInfo("@onStart");
		super.onStart();
	}

	@Override
	protected void onStop() {
		printDebugInfo("@onStop");
		// TODO Auto-generated method stub
		super.onStop();
	}

	@Override
	protected void onTitleChanged(CharSequence title, int color) {
		// TODO Auto-generated method stub
		printDebugInfo("@onTitleChanged");
		super.onTitleChanged(title, color);
	}

	@Override
	public boolean onTouchEvent(MotionEvent event) {
		// TODO Auto-generated method stub
		printDebugInfo("@onTouchEvent");
		return super.onTouchEvent(event);
	}

	@Override
	public boolean onTrackballEvent(MotionEvent event) {
		// TODO Auto-generated method stub
		printDebugInfo("@onTrackballEvent");
		return super.onTrackballEvent(event);
	}

	@Override
	public void onUserInteraction() {
		printDebugInfo("@onUserInteraction");
		// TODO Auto-generated method stub
		super.onUserInteraction();
	}

	@Override
	protected void onUserLeaveHint() {
		printDebugInfo("@onUserLeaveHint");
		// TODO Auto-generated method stub
		super.onUserLeaveHint();
	}

	@Override
	public void onWindowAttributesChanged(LayoutParams params) {
		// TODO Auto-generated method stub
		printDebugInfo("@onWindowAttributesChanged");
		super.onWindowAttributesChanged(params);
	}

	@Override
	public void onWindowFocusChanged(boolean hasFocus) {
		// TODO Auto-generated method stub
		printDebugInfo("@onWindowFocusChanged");
		super.onWindowFocusChanged(hasFocus);
	}

	
}