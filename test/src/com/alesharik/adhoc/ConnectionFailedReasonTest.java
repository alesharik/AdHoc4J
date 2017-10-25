package com.alesharik.adhoc;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class ConnectionFailedReasonTest {
    @Test
    public void getReasonTest() throws Exception {
        assertEquals(ConnectionFailedReason.DOMAIN_MISMATCH, ConnectionFailedReason.getReason(0));
        assertEquals(ConnectionFailedReason.PASSPHRASE_MISMATCH, ConnectionFailedReason.getReason(1));
        assertEquals(ConnectionFailedReason.OTHER, ConnectionFailedReason.getReason(2));
        for(int i = 3; i < 100; i++) {
            assertEquals(ConnectionFailedReason.OTHER, ConnectionFailedReason.getReason(i));
        }
    }
}