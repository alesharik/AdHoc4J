package com.alesharik.adhoc;

import java.util.Arrays;
import java.util.UUID;

/**
 * Like {@link java.util.UUID}, but for Windows
 */
public class Guid {
    protected int dword;
    protected short word1;
    protected short word2;
    /**
     * 8 elements
     */
    protected byte[] data;

    protected Guid(int dword, short word1, short word2, byte[] data) {
        this.dword = dword;
        this.word1 = word1;
        this.word2 = word2;
        this.data = data;
    }

    public static Guid fromUUID(UUID uuid) {
        return new Guid(
                (int) (uuid.getMostSignificantBits() >> 32),
                (short) (uuid.getMostSignificantBits() >> 16),
                (short) uuid.getMostSignificantBits(),
                new byte[]{
                        (byte) (uuid.getLeastSignificantBits() >> 56),
                        (byte) (uuid.getLeastSignificantBits() >> 48),
                        (byte) (uuid.getLeastSignificantBits() >> 40),
                        (byte) (uuid.getLeastSignificantBits() >> 32),
                        (byte) (uuid.getLeastSignificantBits() >> 24),
                        (byte) (uuid.getLeastSignificantBits() >> 16),
                        (byte) (uuid.getLeastSignificantBits() >> 8),
                        (byte) uuid.getLeastSignificantBits()
                }
        );
    }

    public UUID toUUID() {
        return new UUID(
                ((long) dword & 0xFFFFFFFFL) << 32 |
                        ((long) word1 & 0xFFFF) << 16 |
                        (long) word2 & 0xFFFF,
                ((long) data[0] & 0xFF) << 56 |
                        ((long) data[1] & 0xFF) << 48 |
                        ((long) data[2] & 0xFF) << 40 |
                        ((long) data[3] & 0xFF) << 32 |
                        ((long) data[4] & 0xFF) << 24 |
                        ((long) data[5] & 0xFF) << 16 |
                        ((long) data[6] & 0xFF) << 8 |
                        ((long) data[7] & 0xFF)
        );
    }

    public static Guid fromString(String string) {
        return fromUUID(UUID.fromString(string.toLowerCase()));
    }

    @Override
    public String toString() {
        return toUUID().toString();
    }

    public static Guid randomGuid() {
        return fromUUID(UUID.randomUUID());
    }

    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        if(!(o instanceof Guid)) return false;

        Guid guid = (Guid) o;

        return dword == guid.dword && word1 == guid.word1 && word2 == guid.word2 && Arrays.equals(data, guid.data);
    }

    @Override
    public int hashCode() {
        int result = dword;
        result = 31 * result + (int) word1;
        result = 31 * result + (int) word2;
        result = 31 * result + Arrays.hashCode(data);
        return result;
    }
}
