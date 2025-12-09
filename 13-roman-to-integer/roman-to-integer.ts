function romanToInt(s: string): number {
    const values: Record<string, number> = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000
    };

    let result = 0;

    for (let i = 0; i < s.length; i++) {
        const cur = values[s[i]];
        const next = values[s[i + 1]];

        if (next && cur < next) {
            result -= cur;
        } else {
            result += cur;
        }
    }

    return result;
}