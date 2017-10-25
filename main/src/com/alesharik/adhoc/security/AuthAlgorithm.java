package com.alesharik.adhoc.security;

import lombok.AllArgsConstructor;
import lombok.Getter;

/**
 * AdHoc network auth algorithm
 */
@AllArgsConstructor
public enum AuthAlgorithm {
    INVALID(-1),
    OPEN_80211(1),
    RSNA_PSK(7);

    @Getter
    private final int type;

    public static AuthAlgorithm getAlgorithm(int type) {
        for (AuthAlgorithm authAlgorithm : values()) {
            if(authAlgorithm.type == type)
                return authAlgorithm;
        }
        return AuthAlgorithm.INVALID;
    }
}
