package com.alesharik.adhoc;

import com.alesharik.adhoc.security.SecuritySettings;
import sun.misc.Cleaner;

import java.util.List;
import java.util.UUID;

public final class AdHocInterface {
    private volatile long pointer;

    public AdHocInterface(UUID signature) {
        init(signature);
        Cleaner.create(this, this::clean);
    }

    public native AdHocNetwork getActiveNetwork();

    public native UUID getDeviceSignature();

    public native String getFriendlyName();

    public native List<AdHocNetwork> getNetworks();

    public native List<SecuritySettings> getSecuritySettings();

    public native ConnectionStatus getStatus();

    public native boolean isAdHocSupported();

    public native boolean isDot11d();

    public native boolean isRadioOn();

    public native void register(Sink sink);

    public native void unregister(Sink sink);

    private native void clean();

    private native void init(UUID signature);

    public interface Sink {
        void onConnectionStatusChange(ConnectionStatus status);
    }
}
