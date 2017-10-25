package com.alesharik.adhoc.security;

/**
 * AdHoc network auth algorithm
 */
public enum AuthAlgorithm {
    INVALID(-1),
    OPEN_80211(1),
    RSNA_PSK(7);

    private final int type;

    AuthAlgorithm(int type) {
        this.type = type;
    }

    public int getType() {
        return type;
    }

    public static AuthAlgorithm getAlgorithm(int type) {
        for (AuthAlgorithm authAlgorithm : values()) {
            if(authAlgorithm.type == type)
                return authAlgorithm;
        }
        return AuthAlgorithm.INVALID;
    }
}
