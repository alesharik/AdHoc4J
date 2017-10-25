package com.alesharik.adhoc;

import lombok.AllArgsConstructor;
import lombok.Getter;

import javax.annotation.Nonnull;

/**
 * Represent connection status
 */
@AllArgsConstructor
public enum ConnectionStatus {
    INVALID(0),
    DISCONNECTED(11),
    CONNECTING(12),
    CONNECTED(13),
    FORMED(14);

    @Getter
    private final int type;

    @Nonnull
    public static ConnectionStatus getStatus(int type) {
        for (ConnectionStatus connectionStatus : values()) {
            if(connectionStatus.type == type)
                return connectionStatus;
        }
        return INVALID;
    }
}
