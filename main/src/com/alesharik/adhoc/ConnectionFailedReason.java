package com.alesharik.adhoc;

import lombok.AllArgsConstructor;
import lombok.Getter;

import javax.annotation.Nonnull;

@AllArgsConstructor
public enum ConnectionFailedReason {
    DOMAIN_MISMATCH(0),
    PASSPHRASE_MISMATCH(1),
    OTHER(2);

    @Getter
    private final int type;

    @Nonnull
    public static ConnectionFailedReason getReason(int type) {
        for (ConnectionFailedReason connectionFailedReason : values()) {
            if(connectionFailedReason.type == type)
                return connectionFailedReason;
        }
        return OTHER;
    }
}
