package org.qtproject.hardbuttonlistener

import android.view.KeyEvent;

public class HardButtonListener  extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static native void jVolUpPressed();
    private static native void jVolDownPressed();

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event){
        if ( keyCode == KeyEvent.KEYCODE_VOLUME_UP ) {
            // fill here
            jVolUpPressed();
        }
        if ( keyCode == KeyEvent.KEYCODE_VOLUME_DOWN ) {
            // fill here
            jVolDownPressed();
        }

        return super.onKeyDown(keyCode, event);
    }
}
