package com.alesharik.adhoc;

public enum ConnectionStatus {
    INVALID(0),
    DISCONNECTED(11),
    CONNECTING(12),
    CONNECTED(13),
    FORMED(14);

    private final int type;

    ConnectionStatus(int type) {
        this.type = type;
    }

    public int getType() {
        return type;
    }

    public static ConnectionStatus getStatus(int type) {
        for (ConnectionStatus connectionStatus : values()) {
            if(connectionStatus.type == type)
                return connectionStatus;
        }
        return INVALID;
    }
}
