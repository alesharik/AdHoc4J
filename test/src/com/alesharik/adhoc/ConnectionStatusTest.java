package com.alesharik.adhoc;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class ConnectionStatusTest {
    @Test
    public void getStatusTest() throws Exception {
        assertEquals(ConnectionStatus.INVALID, ConnectionStatus.getStatus(0));
        assertEquals(ConnectionStatus.DISCONNECTED, ConnectionStatus.getStatus(11));
        assertEquals(ConnectionStatus.CONNECTING, ConnectionStatus.getStatus(12));
        assertEquals(ConnectionStatus.CONNECTED, ConnectionStatus.getStatus(13));
        assertEquals(ConnectionStatus.FORMED, ConnectionStatus.getStatus(14));
        for(int i = 15; i < 100; i++) {
            assertEquals(ConnectionStatus.INVALID, ConnectionStatus.getStatus(i));
        }
    }
}