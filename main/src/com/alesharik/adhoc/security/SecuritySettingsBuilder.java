package com.alesharik.adhoc.security;

public final class SecuritySettingsBuilder {
    private AuthAlgorithm authAlgorithm;
    private CipherAlgorithm cipherAlgorithm;

    public SecuritySettingsBuilder setAuthAlgorithm(AuthAlgorithm authAlgorithm) {
        this.authAlgorithm = authAlgorithm;
        return this;
    }

    public SecuritySettingsBuilder setCipherAlgorithm(CipherAlgorithm cipherAlgorithm) {
        this.cipherAlgorithm = cipherAlgorithm;
        return this;
    }

    public SecuritySettings createSecuritySettings() {
        return new SecuritySettings(authAlgorithm, cipherAlgorithm);
    }
}