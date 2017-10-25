package com.alesharik.adhoc.security;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class AuthAlgorithmTest {
    @Test
    public void getAlgorithmTest() throws Exception {
        assertEquals(AuthAlgorithm.INVALID, AuthAlgorithm.getAlgorithm(-1));
        assertEquals(AuthAlgorithm.OPEN_80211, AuthAlgorithm.getAlgorithm(1));
        assertEquals(AuthAlgorithm.RSNA_PSK, AuthAlgorithm.getAlgorithm(7));

        for(int i = 8; i < 500; i++) {
            assertEquals(AuthAlgorithm.INVALID, AuthAlgorithm.getAlgorithm(i));
        }
    }
}