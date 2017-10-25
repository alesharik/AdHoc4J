package com.alesharik.adhoc.security;

/**
 * This class represents cipher algorithm for secured AdHoc network
 */
public enum CipherAlgorithm {
    INVALID(-1),
    NONE(0),
    CCMP(4),
    WEP(101);

    private final int type;

    CipherAlgorithm(int type) {
        this.type = type;
    }

    public int getType() {
        return type;
    }

    public static CipherAlgorithm getAlgorithm(int type) {
        for (CipherAlgorithm cipherAlgorithm : values()) {
            if(cipherAlgorithm.type == type)
                return cipherAlgorithm;
        }
        return CipherAlgorithm.INVALID;
    }
}
