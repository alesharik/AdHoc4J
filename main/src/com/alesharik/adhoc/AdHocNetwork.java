package com.alesharik.adhoc;

import com.alesharik.adhoc.security.SecuritySettings;
import sun.misc.Cleaner;

import java.util.UUID;

public final class AdHocNetwork {
    private volatile long pointer;

    AdHocNetwork(long pointer) {
        this.pointer = pointer;
        init();
        Cleaner.create(this, this::clean);
    }

    public native void connect(String pass, long geoId, boolean saveProfile,  boolean userSpecific);

    public native void deleteProfile();

    public native void disconnect();

    public native Guid getContextGuid();

    public native AdHocInterface getInterface();

    public native String getProfileName();

    public native SecuritySettings getSecuritySettings();

    public native SignalQuality getSignalQuality();

    public native Guid getSignature();

    public native String getSSID();

    public native ConnectionStatus getStatus();

    public native boolean hasProfile();

    public native void registerSink(Sink sink);

    public native void unregisterSink(Sink sink);

    private native void init();

    private native void clean();

    public static final class SignalQuality {
        private final long value;
        private final long max;

        SignalQuality(long value, long max) {
            this.value = value;
            this.max = max;
        }

        public long getValue() {
            return value;
        }

        public long getMax() {
            return max;
        }
    }

    public interface Sink {
        void onConnectionFail(ConnectionFailedReason reason);

        void onStatusChange(ConnectionStatus status);
    }
}
