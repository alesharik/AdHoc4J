package com.alesharik.adhoc;

import com.alesharik.adhoc.security.SecuritySettings;
import sun.misc.Cleaner;

import java.util.UUID;

public final class AdHocNetwork {
    private volatile long pointer;
    public AdHocNetwork(UUID sig) {
        init(sig);
        Cleaner.create(this, this::clean);
    }

    public native void connect(String pass, long geoId, boolean saveProfile,  boolean userSpecific);

    public native void deleteProfile();

    public native void disconnect();

    public native UUID getContextGuid();

    public native AdHocInterface getInterface();

    public native String getProfileName();

    public native SecuritySettings getSecuritySettings();

    public native SignalQuality getSignalQuality();

    public native UUID getSignature();

    public native String getSSID();

    public native ConnectionStatus getStatus();

    public native boolean hasProfile();

    public native void registerSink(Sink sink);

    public native void unregisterSink(Sink sink);

    private native void init(UUID signature);

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
