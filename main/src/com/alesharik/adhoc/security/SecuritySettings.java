package com.alesharik.adhoc.security;
//TODO create factory method for it!
public final class SecuritySettings {
    private final long pointer;

    private final AuthAlgorithm authAlgorithm;
    private final CipherAlgorithm cipherAlgorithm;

    SecuritySettings(long pointer, AuthAlgorithm authAlgorithm, CipherAlgorithm cipherAlgorithm) {
        this.pointer = pointer;
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
