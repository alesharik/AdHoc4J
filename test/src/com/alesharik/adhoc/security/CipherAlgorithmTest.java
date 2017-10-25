package com.alesharik.adhoc.security;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class CipherAlgorithmTest {
    @Test
    public void getAlgorithmTest() throws Exception {
        assertEquals(CipherAlgorithm.INVALID, CipherAlgorithm.getAlgorithm(-1));
        assertEquals(CipherAlgorithm.NONE, CipherAlgorithm.getAlgorithm(0x00));
        assertEquals(CipherAlgorithm.CCMP, CipherAlgorithm.getAlgorithm(0x04));
        assertEquals(CipherAlgorithm.WEP, CipherAlgorithm.getAlgorithm(0x101));

        for(int i = 0x101 + 1; i < 500; i++) {
            assertEquals(CipherAlgorithm.INVALID, CipherAlgorithm.getAlgorithm(i));
        }
    }
}