package com.alesharik.adhoc.security;

import com.alesharik.adhoc.AdHocInterface;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;

/**
 * This class represents security settings
 */
public final class SecuritySettings {
    private final long pointer;

    private final AuthAlgorithm authAlgorithm;
    private final CipherAlgorithm cipherAlgorithm;

    public SecuritySettings(long pointer, AuthAlgorithm authAlgorithm, CipherAlgorithm cipherAlgorithm) {
        this.pointer = pointer;
        this.authAlgorithm = authAlgorithm;
        this.cipherAlgorithm = cipherAlgorithm;
    }

    @Nullable
    public static SecuritySettings findSettings(@Nonnull AdHocInterface adHocInterface, @Nonnull AuthAlgorithm authAlgorithm, @Nonnull CipherAlgorithm algorithm) {
        for(SecuritySettings securitySettings : adHocInterface.getSecuritySettings()) {
            if(securitySettings.authAlgorithm == authAlgorithm && securitySettings.cipherAlgorithm == algorithm)
                return securitySettings;
        }
        return null;
    }

    @Nonnull
    public AuthAlgorithm getAuthAlgorithm() {
        return authAlgorithm;
    }

    @Nonnull
    public CipherAlgorithm getCipherAlgorithm() {
        return cipherAlgorithm;
    }
}
