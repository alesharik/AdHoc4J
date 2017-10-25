package com.alesharik.adhoc;

import com.alesharik.adhoc.security.SecuritySettings;
import sun.misc.Cleaner;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;

public final class AdHocNetwork {
    private volatile long pointer;

    AdHocNetwork(long pointer) {
        this.pointer = pointer;
        init();
        Cleaner.create(this, this::clean);
    }

    public native void connect(@Nonnull String pass, long geoId, boolean saveProfile,  boolean userSpecific);

    public native void deleteProfile();

    public native void disconnect();

    @Nonnull
    public native Guid getContextGuid();

    @Nonnull
    public native AdHocInterface getInterface();

    @Nullable
    public native String getProfileName();

    @Nonnull
    public native SecuritySettings getSecuritySettings();

    @Nonnull
    public native SignalQuality getSignalQuality();

    @Nonnull
    public native Guid getSignature();

    @Nullable
    public native String getSSID();

    @Nonnull
    public native ConnectionStatus getStatus();

    public native boolean hasProfile();

    public native void registerSink(@Nonnull Sink sink);

    public native void unregisterSink(@Nonnull Sink sink);

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
        void onConnectionFail(@Nonnull ConnectionFailedReason reason);

        void onStatusChange(@Nonnull ConnectionStatus status);
    }
}
