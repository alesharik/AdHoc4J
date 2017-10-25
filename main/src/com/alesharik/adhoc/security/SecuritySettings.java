package com.alesharik.adhoc.security;

import com.alesharik.adhoc.AdHocInterface;
import lombok.Getter;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;

/**
 * This class represents security settings
 */
public final class SecuritySettings {
    private final long pointer;

    @Getter
    @Nonnull
    private final AuthAlgorithm authAlgorithm;
    @Getter
    @Nonnull
    private final CipherAlgorithm cipherAlgorithm;

    public SecuritySettings(long pointer, @Nonnull AuthAlgorithm authAlgorithm, @Nonnull CipherAlgorithm cipherAlgorithm) {
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
}
