package com.alesharik.adhoc;

import com.alesharik.adhoc.security.SecuritySettings;
import sun.misc.Cleaner;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;
import java.util.List;

public final class AdHocInterface {
    private volatile long pointer;

    AdHocInterface(long pointer) {
        this.pointer = pointer;
        init();
        Cleaner.create(this, this::clean);
    }

    @Nullable
    public native AdHocNetwork getActiveNetwork();

    @Nonnull
    public native Guid getDeviceSignature();

    @Nonnull
    public native String getFriendlyName();

    @Nonnull
    public native List<AdHocNetwork> getNetworks();

    @Nonnull
    public native List<SecuritySettings> getSecuritySettings();

    @Nonnull
    public native ConnectionStatus getStatus();

    public native boolean isAdHocSupported();

    public native boolean isDot11d();

    public native boolean isRadioOn();

    public native void register(@Nonnull Sink sink);

    public native void unregister(@Nonnull Sink sink);

    private native void clean();

    private native void init();

    public interface Sink {
        void onConnectionStatusChange(@Nonnull ConnectionStatus status);
    }
}
