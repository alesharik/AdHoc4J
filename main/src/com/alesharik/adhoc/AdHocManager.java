package com.alesharik.adhoc;

import com.alesharik.adhoc.security.SecuritySettings;

import java.util.List;
import java.util.UUID;

public final class AdHocManager {
    private AdHocManager() { }

    static native HResult commit(AdHocNetwork network, boolean saveProfile, boolean userSpecific);

    static native AdHocNetwork createNetwork(String name, String password, long geoId, AdHocInterface adHocInterface, SecuritySettings securitySettings, UUID contextGuid);

    public static native List<AdHocInterface> getInterfaces();

    public static native List<AdHocNetwork> getNetworks();

    public static native AdHocNetwork getNetwork(UUID signature);

    public static native void registerSink(Sink sink);

    public static native void unregisterSink(Sink sink);

    public interface Sink {
        void onInterfaceAdded(AdHocInterface adHocInterface);

        void onIterfaceremoved(UUID id);

        void onNetworkAdded(AdHocNetwork network);

        void onNetworkRemoved(UUID id);
    }
}
