package com.alesharik.adhoc.security;

import lombok.AllArgsConstructor;
import lombok.Getter;

/**
 * This class represents cipher algorithm for secured AdHoc network
 */
@AllArgsConstructor
public enum CipherAlgorithm {
    INVALID(-1),
    NONE(0x00),
    CCMP(0x04),
    WEP(0x101);

    @Getter
    private final int type;

    public static CipherAlgorithm getAlgorithm(int type) {
        for (CipherAlgorithm cipherAlgorithm : values()) {
            if(cipherAlgorithm.type == type)
                return cipherAlgorithm;
        }
        return CipherAlgorithm.INVALID;
    }
}
