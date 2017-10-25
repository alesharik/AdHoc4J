package com.alesharik.adhoc;

import com.alesharik.adhoc.security.SecuritySettings;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;
import java.util.List;

public final class AdHocManager {
    private static volatile ManagerDelegate delegate;//FIXME delegate for testing

    private AdHocManager() { }

    @Nullable
    public static native AdHocNetwork commit(@Nonnull AdHocNetwork network, boolean saveProfile, boolean userSpecific);

    @Nonnull
    public static native AdHocNetwork createNetwork(@Nonnull String name, @Nonnull String password, long geoId, @Nonnull AdHocInterface adHocInterface, @Nonnull SecuritySettings securitySettings, @Nonnull Guid contextGuid);

    @Nonnull
    public static native List<AdHocInterface> getInterfaces();

    @Nonnull
    public static native List<AdHocNetwork> getNetworks();

    public static native AdHocNetwork getNetwork(@Nonnull Guid signature);

    public static native void registerSink(@Nonnull Sink sink);

    public static native void unregisterSink(@Nonnull Sink sink);

    public interface Sink {
        void onInterfaceAdded(@Nonnull AdHocInterface adHocInterface);

        void onInterfaceRemoved(@Nonnull Guid id);

        void onNetworkAdded(@Nonnull AdHocNetwork network);

        void onNetworkRemoved(@Nonnull Guid id);
    }

    interface ManagerDelegate {

    }
}
