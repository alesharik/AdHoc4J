package com.alesharik.adhoc;

import javax.annotation.Nonnull;

public enum ConnectionFailedReason {
    DOMAIN_MISMATCH(0),
    PASSPHRASE_MISMATCH(1),
    OTHER(2);
    private final int type;

    ConnectionFailedReason(int type) {
        this.type = type;
    }

    public int getType() {
        return type;
    }

    @Nonnull
    public static ConnectionFailedReason getReason(int type) {
        for (ConnectionFailedReason connectionFailedReason : values()) {
            if(connectionFailedReason.type == type)
                return connectionFailedReason;
        }
        return OTHER;
    }
}
