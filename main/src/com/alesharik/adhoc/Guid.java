package com.alesharik.adhoc;

import java.util.Arrays;

/**
 * Like {@link java.util.UUID}, but for Windows
 */
public class Guid {
    protected long dword;
    protected short word1;
    protected short word2;
    /**
     * 8 elements
     */
    protected char[] data;

    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        if(!(o instanceof Guid)) return false;

        Guid guid = (Guid) o;

        return dword == guid.dword && word1 == guid.word1 && word2 == guid.word2 && Arrays.equals(data, guid.data);
    }

    @Override
    public int hashCode() {
        int result = (int) (dword ^ (dword >>> 32));
        result = 31 * result + (int) word1;
        result = 31 * result + (int) word2;
        result = 31 * result + Arrays.hashCode(data);
        return result;
    }
}
