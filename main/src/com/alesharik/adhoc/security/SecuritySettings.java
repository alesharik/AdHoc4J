package com.alesharik.adhoc.security;

public final class SecuritySettings {
    private final AuthAlgorithm authAlgorithm;
    private final CipherAlgorithm cipherAlgorithm;

    public SecuritySettings(AuthAlgorithm authAlgorithm, CipherAlgorithm cipherAlgorithm) {
        this.authAlgorithm = authAlgorithm;
        this.cipherAlgorithm = cipherAlgorithm;
    }

    public AuthAlgorithm getAuthAlgorithm() {
        return authAlgorithm;
    }

    public CipherAlgorithm getCipherAlgorithm() {
        return cipherAlgorithm;
    }
}
