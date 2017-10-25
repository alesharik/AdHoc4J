package com.alesharik.adhoc;

import org.junit.Before;
import org.junit.Test;

import java.util.UUID;

import static org.junit.Assert.assertEquals;

public class GuidTest {
    private Guid guid;

    @Before
    public void setUp() throws Exception {
        guid = Guid.randomGuid();
    }

    @Test
    public void testUUID() throws Exception {
        UUID converted = guid.toUUID();
        Guid parsed = Guid.fromUUID(converted);

        assertEquals(guid, parsed);
    }

    @Test
    public void testString() throws Exception {
        String converted = guid.toString();
        Guid parsed = Guid.fromString(converted);
        assertEquals(guid, parsed);
    }
}